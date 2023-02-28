/*********************************************
 * Id: liu6033
 * 
 * Weekly Coding W05:This program takes in an integer from command line as the size of the Hanoi Tower and prints out the solution of solving that Hanoi Tower (the same rules as Hanoi tower)
 *********************************************/ 

#include<stdio.h>
#include <stdlib.h>
#include <math.h>

void Hanoi(char a,char b,char c,int n);  //定义函数设置from：a ,temp:b ,to:c  
void Hanoi2(char a, char b, char c, int n);
//Hanoi2 is the main Hanoi function that has the main function 

int main(int argc, char * argv[])
{
   int a; 
   a = atoi(argv[1]);

   Hanoi2('A','B','C',a);
   return 0;
}


//Hanoi() is the function for sorting out the Hanoi tower, used recursively
void Hanoi(char a,char b,char c,int n)  //定义函数设置from：a ,temp:b ,to:c                                                                                                                                 
{
   if(n==1)
   {
      //     printf("1 %c %c %c\n",a,b,c);
      printf("Move %c to %c\n",a,b);  //printf()函数传入变量a,c                                                                                                                                            
      printf("Move %c to %c\n",b,c);
      //move from A to C

   }
   else 
   {
      //   printf("%c %c %c\n",a,b,c);

      Hanoi(a,b,c, n-1);

      printf("Move %c to %c\n",a,b);
  
      Hanoi(c, b, a, n-1);

      printf("Move %c to %c\n",b,c);

      Hanoi(a,b, c, n-1);

   }
}

//Hanoi2 is the main Hanoi function that has the main function
void Hanoi2(char a, char b, char c, int n){

   if(n <=2 ){
      Hanoi( a, b, c, n);
   }
   else{

      Hanoi2( 'A', 'B', 'C', n-1);
      //printf("ha\n");
      printf("Move %c to %c\n", 'A', 'B');
      //printf("ha\n");

      Hanoi('C', 'B', 'A', n-1);
      //move the stack from C to A

      //printf("ha\n");
      printf("Move %c to %c\n", 'B', 'C');
      //printf("ha\n");
      Hanoi2('A', 'B', 'C', n-1);
   }


}
