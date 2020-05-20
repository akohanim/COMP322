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
#include <aio.h>


void matrix_add (int block[][], int size, int scalar){
    for (i = 0; i < size; i++){
        for(j=0; j < size; j++){
            block[i][j] += scalar;
        }
    }
}


int main(int argc, char **argv){
    int size = atoi(argv[1];)
    int blocks[][] = atoi(argv[2]);
    int scalar;

    time_t start_time, end_time, total_time;

    //get current time
    time(&start_time);
    
    for (x = 1; x < blocks; x++){
        for (y = 1; y < blocks; y++){

            //asynch read request of matric [x,y]
            aio_read (); //Enqueue a read request.  This is the asynchronous analog of read(2)

            //block = async read return matrix[x, y]
            block[x][y] = read(fd1, buf1, "a");

    
			matrix_add(block, block_size, scalar);

		    //async write request block
			aio_write(fd2, buf2, "a");


        }
    } 
    time(&end_time);
    total_time = end_time - start_time;
    printf("total time = %ld\n", total_time);

	return 0;
}
