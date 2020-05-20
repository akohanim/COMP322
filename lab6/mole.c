
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
#include <unistd.h>

//a program that emits the following messagage to lab6.log 
    //-fprint(logfile,Pop %s\n", argv[0]);

int main(int argc, char **argv){

    FILE *file;

    if(argc !=0){
        printf("only one arg porfavor! \n");
		exit(EXIT_FAILURE);
    }
    file = fopen( "lab6.log", "a"); //a for appending 

	fprintf(file, "Pop %s\n", argv[0]);

    //Close file
	fclose(file);

	return 0;

}