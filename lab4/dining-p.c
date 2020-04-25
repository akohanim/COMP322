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



int main(int argc, char** argv){
    int i;
    sem_t chopstick[5];
    while(1) {
        sem_wait(chopstick[i]);
        sem_wait(chopstick[i+1]);


        //eat

        sem_post(chopstick[i]);
        sem_post(chopstick[i+1]);

        //think

    }
    return 0;
}