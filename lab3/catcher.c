// Ariel Kohanim 
// 106776512
// Comp 322 Lab 3

#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>


//globals 
//list of signals to look out for (from slack)
static char* sigs[] = {"HUP", "INT", "QUIT", "ILL", "TRAP",
 "ABRT", "IOT", "BUS", "FPE", "USR1", "SEGV", "USR2",
  "PIPE", "ALRM", "TERM", "STKFLT", "CHLD", "CONT", "TSTP",
   "TTIN", "TTOU", "URG", "XCPU", "XFSZ", "VTALRM", "PROF", "WINCH"};
static int sigterm = 0; //signals that cause program terminations 
static int counter = 0;

void processCmdArgs(int argc, char** argv, int catcherArray[]){ //The program processes the command line arguments
	//nested loop to process desired arguments
	for(int i = 1; i < argc; i++){
		for(int j = 0; j < 30; j++){ 
			if(strcmp(sigs[j], argv[i]) == 0){ // if the argument is a match to one of the sigs above
				catcherArray[i - 1] = j + 1; //store the argument label in catcherArray
				break;
			}
		}
	}
}

void signalHandler(int signal)
{
//The handler emits a line to stdout that indicates the signal caught, and the time it was caught
	printf("SIG%s caught at %ld\n", sigs[signal - 1], time(NULL));
	counter++;
	if(signal == SIGTERM){
		sigterm++;
	}
}

void signalHelper(int argc, int catcherArray[])
{
	while(sigterm < 4){  //The program gracefully terminates after receiving three successive SIGTERM signals	
		for(int k = 0; k < 30; k++){
			signal(k, SIG_IGN);
		}

		for(int l = 0; l < argc - 1; l++){
			signal(catcherArray[l], signalHandler);	//The program registers a handler for each argument  
		}
		pause();	//continuous pause          
	}
}


int main(int argc, char** argv)
{
	int catcherArray[argc ]; // -1 for program name 

//The program processes the command line arguments 
	processCmdArgs(argc, argv, catcherArray);

//The program emits a status line that includes its PID to stderr
	fprintf(stderr, "%s $$: %d\n", argv[0], getpid());

	signalHelper(argc, catcherArray); //catches signals 

//The program emits a final status message to stderr that indicates the number of signals caught
	fprintf(stderr, "%s: Total signals count = %d\n", argv[0], counter);

	return 0;
}