// Ariel Kohanim 
// 106776512
// Comp 322 Lab 7

#include <stdio.h>
#include <semaphore.h>
#include <signal.h>

#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

void matrix_add (int block[][], int size, int scalar){
    for (i = 0; i < size; i++){
        for(j=0; j < size; j++){
            block[i][j] += scalar;
        }
    }
}

int main(int argc, char **argv){
 int size;
 int block;
 int scalar;



	return 0;
}
