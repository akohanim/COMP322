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
#include <unistd.h>



void daemonize(const char *cmd){
    int i, fd0, fd1, fd2;
    pid_t;
    struct rlimit rl;
    struct sigaction sa;

    //set the file creation mask to 0
    umask(0); 

    //fork and gave parent exit
    if ((pid = fork())<0)
    err_quit("%s: cant fotk",cmd);

    else if (pid != 0){
        exit(0);
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



int main(int argc, char **argv){



}