// Ariel Kohanim 
// 106776512
// Comp 322 Lab 4

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

//create philosopher structure 
struct Philosopher{
    int seats;
    int position;
    int cycles;

    sem_t* chopstick[2];
    sem_t* returnVal;

    char buffer[32];
    char buffer1[32];
} philosopher;


void eat (){
usleep(rand());
printf("Philosopher #%d is eating \n", philosopher.position);
}

void think(){
usleep(rand());
printf("Philosopher #%d is thinking \n", philosopher.position);
}

//part 1 step 3 
void sigHandler(int sig)
{
    signal(SIGTERM, sigHandler);
    if (sig == SIGTERM){
       // sem_destroy()
        sem_close(philosopher.chopstick[0]);
        sem_close(philosopher.chopstick[1]);
        sem_unlink(philosopher.buffer);
        sem_unlink(philosopher.buffer1);
        
        }
    fprintf(stderr, "Philosopher [%d] completed %d cycles\n", philosopher.position, philosopher.cycles);
}

int main(int argc, char** argv){
    //arg 1 = program name , 2 = seats, 3 = position 
    philosopher.seats = atoi(argv[1]);
    philosopher.position = atoi(argv[2]); //converts string arg to int 


    //4a. allocate a semaphore for each chopstick 
    philosopher.returnVal = sem_open(philosopher.buffer, O_CREAT, 0666, 1);
        if (philosopher.returnVal == SEM_FAILED ) { 
            perror(NULL); 
            philosopher.returnVal = sem_open(SEM_FILE1, 0);
        }
    philosopher.chopstick[0]=  philosopher.returnVal;

    philosopher.returnVal = sem_open(philosopher.buffer1, O_CREAT, 0666, 1);
        if (philosopher.returnVal == SEM_FAILED ) { 
            perror(NULL); 
            philosopher.returnVal = sem_open(SEM_FILE1, 0);
        }
    philosopher.chopstick[1]=  philosopher.returnVal;


    
    while(1) {
        //4b
        sem_wait(philosopher.chopstick[0]);
        sem_wait(philosopher.chopstick[(1) % philosopher.seats]);

        eat(philosopher.position);
        //4c
        sem_post(philosopher.chopstick[0]);
        sem_post(philosopher.chopstick[(1) % philosopher.seats]);

        think(philosopher.position);
        philosopher.cycles +=1;

    }
    //needs debugging 

    return 0;
}

