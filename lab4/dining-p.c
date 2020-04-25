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


//globals 
int counter = 0;

void eat (phil_position){
usleep(rand());
printf("Philosopher #%d is eating \n", phil_position);
}

void think(phil_position){
usleep(rand());
printf("Philosopher #%d is thinking \n", phil_position)
}


int main(int argc, char** argv){

    int phil_position = atoi(argv[2]); //converts string arg to int 
    int i;
    int seats;
    
    sem_t chopstick[5];
    while(1) {
        sem_wait(chopstick[i]);
        sem_wait(chopstick[(i + 1) % seats]);


        eat();

        sem_post(chopstick[i]);
        sem_post(chopstick[(i + 1) % seats]);

        think();

        counter++;
    }
    return 0;
}