/*********************************************
 * Id: liu6033
 * 
 * Weekly Coding W05:This program takes in an integer from command line as the size of the Hanoi Tower and prints out the solution of solving that Hanoi Tower (the same rules as Hanoi tower)
 *********************************************/ 

#include<stdio.h>
#include <stdlib.h>
#include <math.h>

void Hanoi(char a,char b,char c,int n);  //定义函数设置from：a ,temp:b ,to:c  

int main(int argc, char * argv[])
{
   int a; 
   a = atoi(argv[1]);

   Hanoi('A','B','C',a);
   return 0;
}


//Hanoi() is the function for sorting out the Hanoi tower, used recursively
void Hanoi(char a,char b,char c,int n)  //定义函数设置from：a ,temp:b ,to:c                                                                                                                                 
{
   if(n==1)
   {
      printf("Move %c to %c\n",a,c);  //printf()函数传入变量a,c                                                                                                                                             
   }
   else
   {
      Hanoi(a,c,b,n-1);  //移动上层的n-1个碟子从a柱子移到b柱子，c为交换柱子                                                                                                                                 
      printf("Move %c to %c\n",a,c);  //移动最底层的一个碟子                                                                                                                                                
      Hanoi(b,a,c,n-1);
   }
}
