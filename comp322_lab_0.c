// Ariel Kohanim 
// 106776512
// Comp 322 Lab 0


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


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





int main()
{
      
    FILE *fptr; 
    
    //printf("Enter the filename to open \n"); 
    //scanf("%s", filename); 


    fptr = fopen("sampletxt.txt", "r") ; 
    char singleLine[9];
    int num;
    int dec;
    
    printf("Original      ASCII       Decimal        Parity       T. Error \n");
    printf("--------      -----       -------        -------      ---------\n");

    while (!feof(fptr)){ //while not at end of file
        //if character = " " or /n then do not include it 

        fgets(singleLine,9, fptr); //retrieves next 8 characters in file
        num = atoi(singleLine); //string -> int
        printf("%d",num);
        printf("\t\t");
        dec = binaryToDecimal(num);
        printf("%d",dec);


       
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