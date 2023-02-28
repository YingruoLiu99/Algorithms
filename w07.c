/*********************************************
 * Id: liu6033
 * 
 * Weekly Coding W07:(cyclic)This program takes in an integer from command line as the size of the Hanoi Tower and prints out the solution of solving that Hanoi Tower (the same rules as Hanoi tower)
 *********************************************/ 

#include<stdio.h>
#include <stdlib.h>
#include <math.h>

void Hanoi(char a,char b,char c,int n); //A to C
void Hanoi2(char a, char b, char c, int n);//C to A
void Hanoi3(char a, char b, char c, int n);//C to B
void Hanoi4(char a, char b, char c, int n);//B to A
void Hanoi5(char a, char b, char c, int n);//A to B
void Hanoi6(char a, char b, char c, int n);//B to C

int main(int argc, char * argv[])
{
   int a; 
   a = atoi(argv[1]);

   Hanoi('A','B','C',a);
   return 0;
}


//Hanoi() is the function for sorting out the Hanoi tower, used recursively, and it moves sets from A to C cyclically
void Hanoi(char a,char b,char c,int n)  //定义函数设置from：a ,temp:b ,to:c                                                                                                                                 
{
   if(n==1)
   {
      printf("Move %c to %c\n",a,b);  //printf()函数传入变量a,c                                                                                                                                           

      printf("Move %c to %c\n",b,c);
   }

   else {
      Hanoi(a, b, c, n-1);// This call moves the thing(s) above our pivot from A to C
      printf("Move %c to %c\n",a,b);//this moves the pivot from A to B
      Hanoi2(a, b, c, n-1);//This call moves thing(s) above from C to A 
      //so that it leaves space for the pivot to move from B to C
      printf("Move %c to %c\n",b,c);//this moves the pivot from B to C,
      Hanoi(a, b, c, n-1);//This call moves the thing(s) above our pivot from A to C
   }

}


//Hanoi2 is used for moving sets from C to A
void Hanoi2(char a, char b, char c, int n){

   if(n==1){
      printf("Move %c to %c\n",c,a);
   }

   else {
      Hanoi3(a, b, c, n-1);//This function call moves the things above pivot of the chunk from B to C from C to B 
      //this function call moves from C to B
      printf("Move %c to %c\n",c,a);//step b, move the largest number of this move set from C to A
      Hanoi4(a, b, c, n-1);//This function call moves that same chunk from B to A
      //this function call moves from B to A
   }
}

//Hanoi3 is used for moving sets from C to B
void Hanoi3(char a, char b, char c, int n){

   if(n==1){
      printf("Move %c to %c\n",c,a);
      printf("Move %c to %c\n",a,b);

   }
   else{
      Hanoi3(a,b,c, n-1);

      printf("Move %c to %c\n",c,a);

      Hanoi6(a,b,c,n-1);//move the chunk above the bottom from B to C

      printf("Move %c to %c\n",a,b);

      Hanoi3(a,b,c,n-1);
  }


}

//Hanoi4 is used for moving sets from B to A
void Hanoi4(char a, char b, char c, int n){

   if(n==1){
      printf("Move %c to %c\n",b,c);
      printf("Move %c to %c\n",c,a);
   }
   else{

      Hanoi4(a, b, c, n-1);

      printf("Move %c to %c\n",b,c);

      Hanoi5(a,b,c, n-1);//This function call moves things from A to B

      printf("Move %c to %c\n",c,a);

      Hanoi4(a, b, c, n-1);  
   }
}

//Hanoi5 moves things from A to B
void Hanoi5(char a, char b, char c, int n){

   if(n==1){
      printf("Move %c to %c\n",a,b);
   }
   else{

      //function call move things above from A to C
      Hanoi(a, b, c, n-1);

      //move the bottom from A to B
      printf("Move %c to %c\n",a,b);

      //function call move things above the bottom from C to B
      Hanoi3(a,b,c,n-1);
  }

}

//Hanoi6 moves from B to C
void Hanoi6(char a, char b, char c, int n){

   if(n==1){
      printf("Move %c to %c\n", b, c);
   }
   else{

      //move the chunk above the bottom from B to A
      Hanoi4(a, b, c, n-1);

      //move the bottom from B to C
      printf("Move %c to %c\n", b, c);

      //move the chunk above the bottom from A to C
      Hanoi(a,b,c,n-1);

  }

}
