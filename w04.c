/*********************************************
 * Id: liu6033
 * 
 * Weekly Coding W04: This program takes in a serious of numbers followed by the number n which is the number of lines. Then this program sets up an augmented matrix and reduce the matrix to its reduced echelon form.
 *********************************************/ 


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){

   if( argc < 2){
      printf("please enter a series of numbers in command line!\n");
      exit(0);
   }

   int n = atoi (argv[1]);//n is the number of lines of the matrix
   int m = n+1;//m is the number of columns of the matrix

   float Arr[n][m];// declare array of type float
   
   //the following methoods store the elements into array A in a horizaontal order
   int i, j;//i keeps count of line number while j keeps count of column number
   int a = 2;//a keeps count of the number of the float in argv[], we are storing from the second element in argv[]
   
   for( i=0; i<n; i++){
      for(j=0; j<m; j++){

         Arr[i][j]= atof(argv[a]);
         a++;
         printf("%.2f ", Arr[i][j]); 

     }
      printf("\n");
   }
   printf("\n");

   float temp2;                                                                                                                                                                                               int k;                                                                                                                                                                                                  
   int o;
   // k and o are used in the print function

   int ii= n-2;
   int jj= n-1; 
   //i keeps track of the pivot column
   //j keeps track of the line number

   for( i=0; i<=ii; i++){
      //this for loop keeps track of the column as our pivot
      for( j=i+1; j<=jj; j++){
         //this for loop keeps track of how many lines down from here we need to perform elimination
         //tempji=Arr[j][i];
         temp2= Arr[j][i]/Arr[i][i];
         //temp2 stores the ratio between the pivot on our line and the line above

         //ji is the pivot we choose to eliminate everything below from here
         for(k=i; k<=n; k++){
            //this for loop will eliminate everything else in the larger columns in the same line as j
            Arr[j][k]= Arr[j][k]- temp2*Arr[i][k]; 
       }
     }
      for( k=0; k<n; k++){
         for(o=0; o<m; o++){
            printf("%.2f ", Arr[k][o]);
       }
         printf("\n");
     }
      printf("\n");
      
   }
   printf("\n");   
   return 0;
}
