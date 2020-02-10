// Ariel Kohanim 
// 106776512
// Comp 322 Lab 0


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
# define  bool int 
#define BUFFER_SIZE 1024


int binaryToDecimal(int n) 
{ 
    int num = n; 
    int dec_value = 0; 
  
    // Initializing base value to 1, i.e 2^0 
    int base = 1; 
  
    int temp = num; 
    while (temp) { 
        int last_digit = temp % 10; 
        temp = temp / 10; 
  
        dec_value += last_digit * base; 
  
        base = base * 2; 
    } 
  
    return dec_value; 
} 


bool findParity(int x) 
{ 
    int y = x ^ (x >> 1); 
    y = y ^ (y >> 2); 
    y = y ^ (y >> 4); 
    y = y ^ (y >> 8); 
    y = y ^ (y >> 16); 
  
    // Rightmost bit of y holds the parity value 
    // if (y&1) is 1 then parity is odd else even 
    if (y & 1) 
        return 1; 
    return 0; 
} 


int main()
{
      
    FILE *fptr; 
    
    //printf("Enter the filename to open \n"); 
    //scanf("%s", filename); 


    fptr = fopen("sampletxt.txt", "r") ; 
    char singleLine[9];
    int num;
    int dec;
    bool tof;
    
    printf("Original      ASCII       Decimal        Parity       T. Error \n");
    printf("--------      -----       -------        -------      ---------\n");


//tokenize 

    while (!feof(fptr)){ //while not at end of file
        //if character = " " or /n then do not include it 
        // need a delimiter 


        fgets(singleLine,9, fptr); //retrieves next 8 characters in file


        num = atoi(singleLine); //string -> int

        printf("%d",num); //prints original as an int 
        printf("\t\t");

        int c = num; 
        printf("%c", c);
        printf("\t\t");

        dec = binaryToDecimal(num);
        printf("%d",dec);
        printf("\t\t");

        (findParity(dec)==0)?printf("Even       FALSE\n"): 
                             printf("Odd         TRUE\n");

    }
  
    fclose(fptr); 
  
   return 0;
}






// void nextEight(){
//    char c;
//    while((c = fgetc(fp)) != EOF)
//       {
//          if(c == ' ' || c == '\n')
//          {
            
//          }
//          else
//          {
//             printf("%c", c);
//          }
//       }
// }

// void read_words (FILE *fptr) {
//     char x[9];
//     /* assumes no word exceeds length of 1023 */
//     while (fscanf(fptr, " %8s", x) == 1) {
//         puts(x);
//     }
// }