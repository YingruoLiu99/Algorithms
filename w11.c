/*********************************************
 * Id: liu6033
 * 
 * Weekly Coding W11: insertionsort
 *********************************************/ 


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void insertionSort(int number[], int);
void printArray( int number[], int, int);

int main(int argc, char *argv[]){

   int count= argc-1;// count is argc-1, which represents the number of the numbers we have in the array 

   //we store argv of type char into another array of type int

   int a=0;//a will be used as a variable in the "copying" process
   int A[count];

   for( ; a < count; a++){

      A[a] = atoi(argv[a+1]);
  
   } 

   //insertion sort function call
   insertionSort( A, count);

   return 0;
   
}
	      
//insertion
void insertionSort(int number[],int count){
 
   printArray( number, count, 0);
   int i;
   int v;
   int j;

   for( i=1; i < count; i++){
      v = number[i];
      j= i-1;

      while(j >=0 && number[j] > v){
         number[j+1]= number[j];
         j--;
      }

      number[j+1]=v;
      printArray(number, count, i);
   }
}
//insertion

//printArray with bars
void printArray(int number[], int count, int bar){
   //bar is the integer of the index of the element which should be followed by a bar to differentiate which part is sorted
   int i;
   for(i=0; i<count; i++){
      printf("%d ", number[i]);
      if( i == bar ){
         printf("| ");
      }
   }
   printf("\n");
}
//print
