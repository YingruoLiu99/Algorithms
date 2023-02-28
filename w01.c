/*********************************************
 * Id: liu6033
 * 
 * Weekly Coding W01: This program takes in integers from the command line and calculate the minimum abosulate value of the difference between two numbers as the minimum distance, and then prints out the * minimum distance
 *********************************************/ 


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){

   int dmin;// this number stores the minimum number of the distances between two numbers
   int count= argc-1;// count is argc-1 

   if( argc < 3){

      printf("Not enough arguments to calculate minimum distance!\n");

   }
   else{
      int i,j;
    
      for(i=0; i < count; i++){

         for (j=0; j< count; j++){

            int val1 = atoi(argv[i+1]); 
            int val2 = atoi(argv[j+1]); 

            if( i==0 && j==0){
               dmin = abs ( atoi(argv[2])- atoi(argv[1]));
               //initiate dmin to the distance between the first two numbers
	    }
	 else{
               if(i != j){

                  if( dmin > abs (val1 - val2))
                  dmin = abs (val1 - val2);
	  }
	}
      }
    }
   }
   printf("%d\n", dmin);
   return dmin;
}
	      

