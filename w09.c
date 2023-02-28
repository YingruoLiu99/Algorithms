/*********************************************
 * Id: liu6033
 * 
 * Weekly Coding W09: Selection Sort
 *********************************************/ 


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){

   //First we print out the array
   int i;
   int Arr[256];
   int count = argc-1;//count is how many elements are in the array from command line

   for(i = 0; i < count; i++){

      Arr[i] = atoi(argv[i+1]);
    
      if ( i < count-1){
         printf("%d ", Arr[i]);
      }
      else{
         printf("%d \n", Arr[i]);
      }

   }
   int min;//this integer stores the index for the minimum value
   int j;
   int m;//this int is used in printing array
   int temp;// this value is used as an intermediate temp value in swapping A[i] and A[min]
   //Then we implement the selection sort

   for(i=0; i< count-1; i++){

      min = i;
      for( j = i+1; j < count; j++){

         if( Arr[j] < Arr[min]){
            min = j;
      }

    }

      temp = Arr[min];
      Arr[min] = Arr[i];
      Arr[i] = temp;

      for(m = 0; m < count; m++){

         if ( m < count-1){
            printf("%d ", Arr[m]);
         }
         else{
            printf("%d \n", Arr[m]);
         }

      }

   }   
   return 0;
}
	      

