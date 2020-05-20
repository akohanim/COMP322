// Ariel Kohanim 
// 106776512
// Comp 322 Lab 6

#include <stdio.h>
#include <semaphore.h>
#include <signal.h>

#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

//#include "apue.h"
#include <syslog.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <limits.h>
#include <unistd.h>
#include <fcntl.h>

pid_t mole, child;
unsigned int moleChild,liveChild;
char cwd[PATH];

void daemonize(){
    int i, fd0, fd1, fd2;

    struct rlimit rl;
    struct sigaction sa;

    //set the file creation mask to 0
    umask(0); 

    //fork and gave parent exit
    if ((mole = fork())<0){
        fprintf("cant fork");
        return0;
    }
    


    else if (mole != 0){
        return 0;
    }
    //create a new session & create new proccess group 
    setsid();

    //change current working directiory to be "/"
    if(chdir ("/") < 0){
        err_quit("%s: can't change dir to /" cmd);
    }

    // close all open file descriptors
    // need it to only close the UNNEEDED file descriptors 
    // GETRLIMIT(2)    
    if (rl.rlim_max == RLIM_INFINITY){
        rl.rlim_max = 1024;
    }
    for(i=0; i<rl.rlim_max; i++){
        close(i);
    }

    //reopen the std file descriptors to map to /dev/null
    fd0= open("/dev/null",O_RDWR);
    fd1 = dup(0);
    fd2 = dup(0);

}


}
//part2

void signalHandler(void)
{
    static char* sigs[] = {"TERM", "USR1", "USER2"}
    int i;

        //if SIG_TERM, program kills all child processes and shutdowns the daemon gracefully 
        if(sig == SIGTERM & mole != 0){
	           //kills child process
		        kill(mole , SIGKILL); //kill2
	        }
            kill(getpid(), SIGKILL);

        //if SIG_USR1, the program will kill child process #1 (mole1) or mole 2 if it does not already exist 
        else if(strcmp(sigs[1], argv[0]) == 0)){
            if(child != 0){
		        kill(mole, SIGKILL);
            }

        //USER2 program will kill chil process #1(mole2) randomly create either mole1 or mole 2 if it does not already exists
        else if(strcmp(sigs[2], argv[0]) == 0)){    

            exit(EXIT_SUCCESS);
}
    
void molarize()
{
    //fork a new process                   
	mole = fork();

    //Randomly choose if child process number is 1 or 2
	liveChild = (rand() % 2) + 1;


	if(liveChild == 1 && moleChild == 0)
	{
        //exec the program mole with val of argv[0] set to mole1
		char* newArg[] = {"mole1", NULL};
		execv(cwd, newArg);
	}

	if(liveChild == 2 && moleChild == 0)
	{
        //exec the program mole with val of argv[0] set to mole1
		char* newArg[] = {"mole2", NULL};
		execv(cwd, newArg);
	}
}

int main()
{

	// getcwd(cwd, sizeof(cwd));
	// strcat(cwd, "/mole\0");



    //infinite loop  to keep daemon running 
	while(1)
	{
	    daemonize();
    }

	return 0;
}
