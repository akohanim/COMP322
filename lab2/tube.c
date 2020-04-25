// Ariel Kohanim 
// 106776512
// Comp 322 Lab 2

#include <stdio.h>  
#include <sys/types.h> /* pid_t */
#include <unistd.h>  /* _exit, fork */
#include <stdlib.h>  /* exit */
#include <errno.h>   
#include <sys/wait.h>
#include <string.h> 

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

//Buffers to hold command line args 
void make_buffers(char** argv, int argc, char** buffer1, char** buffer2){
//Buffer to hold first half of argv
	int i = 0;
	int j = 0;
	int k = 0;
	while(strcmp(argv[i], ",") != 0){
		i++;
		if(strcmp(argv[i], ",") == 0)//is it the ","?
		{
			i++;
			break;
		}
		else { //no, store arg in buffer
			buffer1[j] = argv[i];
			j++;
		}
	}

    //Buffer to hold second half of argv
	while(i < argc)
	{
		buffer2[k] = argv[i];//store arg in buffer
		i++;
		k++;
		if(i >= argc)//last of args 
		{
			break;
		}
	}
}

int main(int argc, char** argv){

	pid_t child_1, child_2;
	int status_1, status_2;	
	char* buffer1[100];
	char* buffer2[100];
    int pipefd[2];
	int fd[2];
	pid_t pid;

	// not enough args 
	if (argc <= 3) {
		fprintf(stderr, "Error: Usage: %s Not enough args\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	else
	{
		make_buffers(argv, argc, buffer1, buffer2);
	}

    //from the textbook :) allocate a pipe 
	if(pipe(pipefd) == -1)
	{

		fprintf(stderr, "Error: Usage: %s Pipe failed\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	//The program forks two child processes
	child_1 = fork();

	//Error fork fail
	if(child_1 < 0)
	{
		fprintf(stderr, "Error: Usage: %s fork 1 failed\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	child_2 = fork();
	
	//Error fork fail
	if(child_2 < 0)
	{
		fprintf(stderr, "Error: Usage: %s fork 2 failed\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	//Parent
	if(child_1 > 0 && child_2 > 0)
	{
		fprintf(stderr, "child 1 %s: $$ = %d\n", buffer1[0], child_1);
		fprintf(stderr, "child 2 %s: $$ = %d\n", buffer2[0], child_2);

	//The parent process closes access to the pipe and
		close(pipefd[READ_END]);//close read end

		write(pipefd[WRITE_END], buffer1, sizeof(buffer1));
		write(pipefd[WRITE_END], buffer2, sizeof(buffer2));

		close(pipefd[WRITE_END]);//close write end

		waitpid(child_1, &status_1, WUNTRACED);
		waitpid(child_2, &status_2, WUNTRACED);

		fprintf(stderr, "child 1 %s: $? = %d\n", buffer1[0], status_1);
		fprintf(stderr, "child 2 %s: $? = %d\n", buffer2[0], status_2);
	}

	// child 1
	else if(child_1 == 0 && child_2 > 0)
	{
		dup2(pipefd[READ_END], READ_END);//duplicate read end of the pipe
		close(pipefd[WRITE_END]);
		read(pipefd[READ_END], buffer1, sizeof(buffer1));//read data from parent
		close(pipefd[READ_END]);

		char *newargv[sizeof(buffer1)];

		for(size_t i = 0; i < sizeof(buffer1); i++)
		{
			newargv[i] = buffer1[i];
		}
		execve(buffer1[0], newargv, NULL);

	//Error
		fprintf(stderr, "Error: Usage: %s Exec 1 failed\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	//Second child
	else if(child_2 == 0 && child_1 > 0)
	{
		dup2(pipefd[READ_END], READ_END);
		close(pipefd[WRITE_END]);//close write end
		read(pipefd[READ_END], buffer2, sizeof(buffer2));//read data from parent  
		close(pipefd[READ_END]); 
		char *newargv[sizeof(buffer2)];

		for(size_t i = 0; i < sizeof(buffer2); i++)
		{
			newargv[i] = buffer2[i];
		}
		execve(buffer2[0], newargv, NULL);
		fprintf(stderr, "Error: Usage: %s Exec 2 failed\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	return 0;
}