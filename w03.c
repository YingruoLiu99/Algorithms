/*********************************************
 * Id: liu6033
 * 
 * Weekly Coding W03: This program takes in a number n from the command line and calculates 2 to the nth and gives it as an output
 *********************************************/ 


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int recursive(int n);

int main(int argc, char *argv[]){

   int n = atoi(argv[1]);
   //n is the index we will use later and n should be a nonnegative

   if( n < 0 ){
      printf("Please enter a nonnegative integer!\n");
      exit(0);
   }
   
   int result = recursive(n);
   //calculate 2 to the nth and store it in integer "result"

   printf("%d\n", result);  
   return 0;
}


//this recursion function splits 2 to the nth into halves recursively and count how many 2 to the 0th are containted in 2 to the nth 
int recursive(int n){

   int result;
   //this integer will be used to store the calculated result

   if(n < 1){

      return 1;
      //n<1 for a noninteger n, n is 0, and 2 to the 0th is 1, and here we can stop the recursion
   }
   else {
      //if n is a positive integer then we keep splitting n into halves
      result = recursive(n-1) + recursive(n-1);
      return result;    
   }

}

