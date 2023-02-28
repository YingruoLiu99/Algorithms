/*********************************************
 * Id: liu6033
 * 
 * Weekly Coding W08: This program takes in two arrays from the command line and brute forces for matching patters
 *********************************************/ 


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(int argc, char *argv[]){

   if( argc < 3){

      printf("Not enough arguments to find matching patterns!\n");

   }
   else{
      char small[256];
      char big[256];
      strcpy(small,argv[1]);
      strcpy(big, argv[2]);

      int count;//this integer keeps count of how many letters the small array has
      int count2;//this integer keeps count of how many letters the big array has

      int i;
      for( i=0; small[i] != '\0'; i++){

      }
      count=i;
      for( i=0; big[i]!= '\0'; i++){

      }    
      count2=i;

      int j;
      int boolFound = 0;
      printf("Matches found at locations:");
      for(i=0; i <= count2-count; i++){
         j=0;

         while(j<count && small[j] == big[i+j]){
	    j++;
         } 

         if(j == count){
            printf(" %d", i);
            boolFound=1;
         }
      }

      if(boolFound==0){
         printf(" -1");
      }

      printf("\n");


   }
   return 0;
}
	      

