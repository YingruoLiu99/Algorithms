/*********************************************
 * Id: liu6033
 * 
 * Comment about what this program does 
 *********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ALPHABET 128
#define TABLE_ROW_LENGTH 16
#define MIN_WRITEABLE 32

void printShiftTable(int table[]);
void shiftTable(char needle[], int size, int table[]);
void horspoolMatching(char needle[], char hayStack[], int m, int n, int table[]);

int main(int argc, char *argv[]){

   int a;
   int needleLgth=0;//needle length
   int hayLgth=0;//haystack length

   //counting the length of the needle
   while(argv[1][a]!='\0'){
      needleLgth++;
      a++;
   }
   //declare needle array with the size counted
   char needle[a];
   //set a to 0 to count the haystack
   a=0;
   while(argv[2][a]!='\0'){
      hayLgth++;
      a++;
   }
   //declare haystack
   char hayStack[a];

   for(a=0; a < needleLgth; a++){
      needle[a] = argv[1][a];
   }
   needle[a] ='\0';

   for(a=0; a < hayLgth; a++){
      hayStack[a] =argv[2][a];
   }
   hayStack[a]='\0';
   int table[128];
   shiftTable(needle, needleLgth, table);
   printShiftTable(table);
   horspoolMatching(needle, hayStack, needleLgth, hayLgth, table);
   return 0;
}

//store the shift numbers into table array
void shiftTable(char needle[], int size, int table[]){

   int i;
   for(i=0; i < 128; i++){
      table[i] = size;
   } 
   int j;
   int la = size-1;
   int needleIndex;
   for(j=0; j < la; j++){
      needleIndex = needle[j];
      table[needleIndex] = size-1-j;
   }

}

//print the shift table	      
void printShiftTable(int table[])
{
   int i, start;
   for(start = MIN_WRITEABLE; start < MAX_ALPHABET; start+=TABLE_ROW_LENGTH){
      for(i = start; i < start+TABLE_ROW_LENGTH; i++){
         printf("%c\t", i);
      }
      printf("\n");

      for(i = start; i < start+TABLE_ROW_LENGTH; i++){
         printf("%d\t", table[i]);
      }
      printf("\n\n");
   }
}

//find the matching places in the stack
void horspoolMatching(char needle[], char hayStack[], int m, int n, int table[]){

   printf("%s\n", hayStack);

   int i = m-1;
   int ha = n-1;
   int k;
   int matchNum=0;
   int matches[256];
   int index=0;
   int hayIndex;

   while(i<=ha){
      k=0;//number of matches characters

      while(k<= m-1 && needle[m-1-k] == hayStack[i-k]){
         k++;
      }
      if(k==m){
         printf("%*s%s---found\n", i-m+1,"", needle);
         matchNum++;
         matches[index]=i-m+1;
         index++;
      }
      else{
         printf("%*s%s\n", i-m+1, "", needle);
      }
      hayIndex=hayStack[i];
      i +=  table[hayIndex];//keep searching

   }


   printf("Matches found at locations:");
   if(matchNum==0){
      printf(" -1\n");
   }
   for(i = 0; i < matchNum; i++){
      printf(" %d", matches[i]);
   }
   printf("\n");

}

