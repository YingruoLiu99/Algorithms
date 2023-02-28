/*********************************************
 * Id: liu6033
 * 
 * Weekly Coding W02: This program improves on the previous program in w01 which takes in integers from the command line and calculate the minimum abosulate value of the difference between two numbers as the minimum distance, and then prints out the * minimum distance
 *********************************************/ 


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void quicksort(int number[], int , int);

int main(int argc, char *argv[]){

   int count= argc-1;// count is argc-1, which represents the number of the numbers we have in the array 

   //we store argv of type char into another array of type int

   int a=0;//a will be used as a variable in the "copying" process
   int A[count];

   for( ; a < count; a++){

      A[a] = atoi(argv[a+1]);
  
   } 

   //we use quick sort algorithm to sort out the array, which takes O(n logn )time

   quicksort(A, 0, count-1);
   
   int dmin = A[count-1];//initialize the minimum distance to the max number in the array
  
  
   if( argc < 2){

      printf("Not enough arguments to calculate minimum distance!\n");

   }
   else{
      int i;
      //now we find out the minimum distacne by comparing the adjacent numbers in the sorted list, this step takes O(n) time
      for ( i=0; i< count-1; i++) 
      if (A[i+1] - A[i] < dmin) 
      dmin = A[i+1] - A[i];


   }

   printf("%d\n", dmin);
   return dmin;
}
	      
//quicksort function sorts out an array in ascending order using method quick sort                                                                                                                         
void quicksort(int number[],int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
	i++;
         while(number[j]>number[pivot])
	j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
      }
    }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);

  }
}
//quicksort function sorts out an array in ascending order using method quick sort                                                                                                                          

