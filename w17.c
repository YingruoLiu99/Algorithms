/*********************************************
 * Id: liu6033
 * 
 * Weekly Coding W17: This program takes in integers from the command line and calculate the minimum abosulate value of the difference between two numbers as the minimum distance, and then prints out the * minimum distance
 *********************************************/ 


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){

   int row = atoi(argv[1]);
   int column = atoi(argv[2]);
   int board[row][column];
   int collected[row][column];
   int i,j;//i is used for tracking rows and j is used for tracking columns
   int k = 3;//argv[3] should be the first element on the board

   printf("Board Inputed:\n");

   for(i=0; i <row; i++){
      for(j=0; j<column; j++){
         if( *argv[k] != 'X'){
            board[i][j] = atoi(argv[k]);
            printf("%d\t", board[i][j]);
         }
         else{
            board[i][j] = 3;
            printf("X\t");
         }
         k++;
      }
      printf("\n");
   }
   printf("\n");
   //there we have made up our 2D array and printed it out
   printf("Coin Collecting Table:\n");
   collected[0][0]=board[0][0];

   //then traverse through the first row

   int blocked;
   for(j=1, blocked = 0; j<column; j++){
      if(board[0][j] != 3 && blocked ==0 ){
         collected[0][j] = collected[0][j-1] + board[0][j];
      }
      else{
         blocked = 1;
         board[0][j] = 3;//invisibly set the top to be blocked on the board
         collected[0][j]=0;
      }
   }
  
   int max;
   for(i=1, blocked=0; i<row; i++){
      if(board[i][0] != 3 && blocked ==0 ){
         collected[i][0] = collected[i-1][0] + board[i][0];
      }
      else{
         blocked = 1;
         board[i][0] = 3;//invisibly set the left to be blocked on the board
         collected[i][0]=0;
      }
   }

   for(i = 1; i < row; i++){
      for(j=1; j<column; j++){
         if(board[i-1][j] ==3 && board[i][j-1] !=3){
            //when the above is X
            if(board[i][j] != 3){      
               max = collected[i][j-1];
               collected[i][j] = max + board[i][j];
            }
            else{
               collected[i][j] = 0;
            }
         }
         else if(board[i][j-1] ==3 && board[i-1][j] !=3){
            //when the left is X
            if(board[i][j] !=3){
               max = collected[i-1][j];
               collected[i][j] = max + board[i][j];
            }
            else{
               collected[i][j] = 0;
	    }
         }
         else if(board[i-1][j] ==3 && board[i][j-1] ==3){
            //both X
            collected[i][j] = 0;
            board[i][j] = 3;// because we can't access this area too, it acts as a block too
         }
         else{
            //not X
            if(board[i][j] != 3){
               if(collected[i-1][j] >= collected[i][j-1]){
                  max = collected[i-1][j];
	       }
	       else{
                  max= collected[i][j-1];
	       }
               collected[i][j] = max + board[i][j];
            }
	   else{
               collected[i][j] = 0;
	   }
         }

      }

   }
 
   for(i=0; i <row; i++){
      for(j=0; j<column; j++){
         printf("%d\t", collected[i][j]);
      }
      printf("\n");
   }
   printf("\n");
   printf("The optimal path with this board is: %d\n", collected[row-1][column-1]);
   return 0;
 
}
	      

