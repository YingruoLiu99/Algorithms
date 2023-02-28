/*********************************************
 * Id: liu6033
 * 
 * Weekly Coding W10: Quicksort & Hoares partition
 *********************************************/ 


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void quicksort(int number[], int l, int r);//this is the major quicksort function
int hoarePartition(int number[], int l, int r);//Hoare Partition as is named
void printSubArray(int number[], int l, int r);//this function prints out elements in an array from indices l to r

int main(int argc, char *argv[]){

   int count= argc-1;// count is argc-1, which represents the number of the numbers we have in the array 

   //we store argv of type char into another array of type int

   int a=0;//a will be used as a variable in the "copying" process
   int A[count];//the array of numbers that need to be sorted

   for( ; a < count; a++){

      A[a] = atoi(argv[a+1]);
   } 

   //we use quick sort algorithm to sort out the array

   quicksort(A, 0, count-1);
   printSubArray( A, 0, count-1);   
   return 0;  
}
	      
//quicksort function sorts out an array in ascending order using method quick sort                                                                                                                         
void quicksort(int number[],int l,int r){

   if(l<r){

      int s;
      s = hoarePartition(number, l, r);

      quicksort( number, l, s-1);
      quicksort( number, s+1, r);

      printSubArray(number, l, r);
   }

}
//quicksort function sorts out an array in ascending order using method quick sort                                                                                                                          

//this is Hoare partition
int hoarePartition(int number[], int l, int r){

   int pivot = number[l];
   int i = l;
   int j = r+1;
   int swap;

   while(i<j){
      //do this until i>=j
      do{
         i++;
      }while(number[i] < pivot);

      do{
         j--;
      }while(number[j] > pivot);

      swap = number[i];
      number[i]= number[j];
      number[j]= swap;
   }

   swap = number[i];
   number[i]= number[j];
   number[j]= swap;
   //undo swap when i >= j 

   swap = number[l];
   number[l]= number[j];
   number[j]= swap;

   return j;
}

//print sub arry l to r
void printSubArray(int number[], int l, int r){

   int total;
   total=r-l;

   int i, j;
   for(i=0, j=l; i<=total; i++, j++){

      printf("%d ", number[j]);

   }
   printf("\n");
}
//print sub array l to r
