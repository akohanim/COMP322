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

//create philosopher structure 
struct Philosopher{
    int seats;
    int position;
    int cycles;
    char buff1[32];
    char buff2[32];
    sem_t* chopsticks[2];
} philosopher;

//globals 
int counter = 0;

void eat (phil_position){
usleep(rand());
printf("Philosopher #%d is eating \n", philosopher.position);
}

void think(phil_position){
usleep(rand());
printf("Philosopher #%d is thinking \n", philosopher.position)
}

//part 1 step 3 
void sigHandler(int sig)
{
    signal(SIGTERM, sigHandler);
    if (sig == SIGTERM){
        sem_destroy(philosopher)
        sem_close(philosopher.chopsticks[0]);
        sem_close(philosopher.chopsticks[1]);
        sem_unlink(philosopher.buff1);
        sem_unlink(philosopher.buff2);
        
        }
    fprintf(stderr, "Philosopher [%d] completed %d cycles\n", philosopher.position, philosopher.cycles);
}

int main(int argc, char** argv){

    int philosopher.position = atoi(argv[2]); //converts string arg to int 
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
    //part 1 step 3 
    // signal(SIGTERM, handle_sigint); 
    //     while (1) 
    //     { 
    //         printf("SIGTERM (%d) received...\n", handle_sigint);
    //         int sem_destroy(sem_t *sem);
    //         sem_destroy()

    //     } 
        

    return 0;
}

