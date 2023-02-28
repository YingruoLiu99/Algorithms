/*********************************************
 * Id: liu6033
 * 
 * Weekly Coding W13:Russian Peasant Multiplication
 *********************************************/ 


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){

   int x = atoi(argv[1]);//x is the first number to be multiplied
   int y = atoi(argv[2]);//y is the second number to be multiplied
   int sum=0;//this integer keeps track of the sum of the numbers that need to be added to calculate the final answer
   do{
      if( x%2 ==0){
         printf("%6d %6d\n", x,y);
      }
      else{//if x is an odd number
         printf("%6d %6d %6d\n", x,y,y);
         sum += y;
     }
      x=x/2;
      y=y*2;

   } while( x >= 1);

   printf("%20s\n", "------");
   printf("%20d\n", sum);
   return 0;
}	      

