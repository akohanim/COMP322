// Ariel Kohanim 
// 106776512
// Comp 322 Lab 1

#include <stdio.h>  
#include <time.h> 
#include <sys/types.h> // pid_t , wait()
#include <unistd.h>  // _exit, fork 
#include <stdlib.h>  
#include <errno.h>   //errno 
#include <sys/wait.h> //wait
#include <sys/times.h> 


int status;
pid_t pid;

void func1 (){
    printf("PPID: %d\t", getppid());
    printf("PID: %d\n", getpid()); 
    exit(0);
}

void func2(){
    printf("PPID %d\t", getppid()); //ppid
    printf("PID: %d\t", getpid()); //pid
    printf("CPID: %d\t", pid); // CPID
    printf("RETVAL: %d\n",status); //returnvalue

    struct tms buf;
    times(&buf);

    printf("USER: %ld\t", buf.tms_utime);
    printf("SYS: %ld\n", buf.tms_stime);
    printf("CUSER: %ld\t", buf.tms_cutime);
    printf("USER: %ld\n", buf.tms_cstime);
   
}

int main(void)
{
    time_t start, stop;
    start = time(NULL);
    printf("START: ");
    printf("%ld", start);
    printf("\n");
 
    // Fork system call is used for creating a new process, which is called child process,
    // which runs concurrently with the process that makes the fork() call (parent process).
    // After a new child process is created, both processes will execute the next instruction
    // following the fork() system call. A child process uses the same pc(program counter), 
    // same CPU registers, same open files which use in the parent process.

    pid = fork();
    
    if (pid == 0) 
    {
        func1(); 
    }

    else if (pid > 0)// PID of the newly created child process
    {
        waitpid(pid, &status, WUNTRACED); 
        func2(); //prints out pid, ppid, cpid, retval and times
       
    }
    else {
        exit(EXIT_FAILURE);
    }   

    stop = time(NULL);
    printf("STOP: ");
    printf("%ld", stop);
    printf("\n");
    //ok if start and stop times are the same, since measured in seconds

    return 0; 
}
