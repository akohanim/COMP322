// Ariel Kohanim 
// 106776512
// Comp 322 Lab 2

#include <stdio.h>   /* printf, stderr, fprintf */
#include <sys/types.h> /* pid_t */
#include <unistd.h>  /* _exit, fork */
#include <stdlib.h>  /* exit */
#include <errno.h>   
#include <sys/wait.h>

void func1(int argc, char** argv)
{
	char *newargv[argc];

	for(int i = 1; i - 1 < argc; i++)
	{
		newargv[i - 1] = argv[i];
	}

	execve(argv[1], newargv, NULL); // must take 3 parameters 

	//if theres an error
	perror("execve"); 
       	exit(EXIT_FAILURE);
}



int main(int argc, char** argv)
{

	if (argc <= 1) {
		fprintf(stderr, "Error, too few arguments");
		exit(EXIT_FAILURE);
	}


	int status;
	pid_t  pid;

	pid = fork();

    if(pid > 0)
	{
		printf( stderr, "%s: $$ = %d\n", argv[1], getpid());

		//The parent prints the return value of the child on stderr    (see waitpid(2))
		waitpid(pid, &status, WUNTRACED);
		printf( stderr, "%s: $? = %d\n", argv[1], status);
    }
	else if(pid == 0)
	{
			func1(argc, argv);
	}

	else
	{
		printf("Failure\n");
	}

return 0;
}

