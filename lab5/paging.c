// Ariel Kohanim 
// 106776512
// Comp 322 Lab 5 

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void printStuff(int a, int b, int c){
   printf("The address %d contains: \n", a);
   printf("Page Number = %d \n", b);
   printf("Offset = %d \n", c);
}

int main(int argc, char **argv)
{
   unsigned int pageSize = 4096;  //4KB page size = 4096 byes 
   unsigned int address; 
   unsigned int pageNumber;
   unsigned int offset;

   if (argc != 2){
       printf("2 arguments only porfavor");
       return 0;
   }

   address = atoi(argv[1]);
   pageNumber = address / pageSize;
   offset = address % pageSize;

   printStuff(address, pageNumber, offset);

   return 0;
}