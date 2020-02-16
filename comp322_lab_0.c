// Ariel Kohanim 
// 106776512
// Comp 322 Lab 0

#include<stdio.h>  
#include<string.h>  
#include<stdlib.h>  
#include<unistd.h>  
#include <fcntl.h>
# define  bool int 

bool getParity( int n) 
{ 
    bool p = 0; 
    while (n) 
    { 
        p = !p; 
        n      = n & (n - 1); 
    }         
    return p; 
} 

int main(int argc, char*argv[])
{
	char numberStr[9], chr;
	int myFile, bites, value, count,parity, i,j,k,a,b;
	
		printf("Original\tASCII\tDecimal\tParity\tT.Error\n");
		printf("--------\t-----\t-------\t------\t--------\n");
    if (argc == 1)
    {
        printf("error, invalid argument");
    }
	else if (argc == 2) // case a file is provided 
	{
		//printf("using a file");

		myFile = open(argv[1], O_RDONLY, 0);
		value = 0;
		count = 0;
		parity = 0;
		bites = read(myFile, &chr, 1);
			
			
			while (bites == 1) //caluculates the value of the string of 1s & 0s   
			{
				if (chr == '0' && count < 8) 
				{
					value *= 2;
					numberStr[count++] = chr;
				}
                
				else if (chr == '1' && count < 8)
				{
					value *= 2;
					value += 1;
					numberStr[count++] = chr;
					parity++;
				}
				else 
				{
					numberStr[count++] = 0;
					count = 0;
					//
					printf("%8s    %c       %3d  %-5s  %-5s\n", numberStr, (char)(value%128), value % 128,
					parity & 1 ? "ODD" : "EVEN",
					value > 128 ? "FALSE" : "TRUE");

					value = 0;
					parity = 0;
				}
				bites = read(myFile, &chr, 1);
			}
			while (count < 8)
			{
				value *= 2;
				numberStr[count++] = '0';
			}
			numberStr[count++] = 0;
			printf("%8s        %c      %3d  %-5s  %-5s\n", numberStr, (char)(value%128), value % 128,
				parity & 1 ? "ODD" : "EVEN",
				value > 128 ? "FALSE" : "TRUE");
			close(myFile);

	}

	else if (argc >= 2)
		{
		for (i=1; i < argc; i++)
			{
 
            printf("%s",argv[i]); 

			int len = strlen( argv[i] );
			// printf("\t %d",len); uncomment for size of arg

       			value = 0;
				count = 0;
				parity = 0;

            // if (len < 8){ //function to append last item with "0s"

            //         int temp,q;
            //         temp = 8-len;
            //         char mytemp[8];
            //         char src[7], dest[8];

            //         argv[i]= dest;
            //         strcpy(src,  "This is source");
            //         //strcpy(dest, dest[]);

            //         strcat(argv[i], dest);

            //         printf("Final destination string : |%s|", dest);
            //     }   


                for (j=1;j<8; j++){ 
                
				chr = argv[i][j]; 
                
				if (chr == '0' && count < 8) 
				{
					value *= 2;
				}

				else if (chr == '1' && count < 8)
				{
					value *= 2;
					value += 1;

					parity++;
				}

                else if (chr == '-' && count < 8){
                    printf("error");
                }
			}
				printf("\t%c \t %3d ", (char)(value%128), value % 128);
				printf((getParity(value%128)? "\todd\n": "\teven\n"));
        }
	}

    
	return 0;
}