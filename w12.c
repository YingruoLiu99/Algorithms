/*********************************************
 * Id: liu6033
 * 
 * Weekly Coding W12: Selection & Insertion & Quicksort Comparison
 *********************************************/ 


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<time.h>
#include<sys/time.h>

void quicksort(int number[], int l, int r);//this is the major quicksort function
int hoarePartition(int number[], int l, int r);//Hoare Partition as is named, used in quicksort
void selectionSort(int number[], int count);//selection sort
void insertionSort(int number[], int count);//selection sort

int main( ){

   int a;//a keeps track of how many elements during the process of generating


   //first we generate an array of size 1000
   //10 to the power of 3
   srand(time(NULL));//seed the random function
   int count1;//count is how many random elements that need to be sorted
   count1= pow(10, 3);
   int A[count1];// A[100]
   for( a=0; a < count1; a++){

      A[a] = rand()%10;
 
   } 


   //now we generate the random array of size 10000
   //10 to the power of 4  
   srand(time(NULL));
   int count2;//count is how many random elements that need to be sorted
   count2 = pow(10, 4);
   int B[count2];//B[10000] 
   for( a=0; a < count2; a++){

      B[a] = rand()%10;

   }


   //now we generate the random array of size 100000
   //10 to the power of 5
   srand(time(NULL));
   int count3;//count is how many random elements that need to be sorted
   count3 = pow(10, 5);
   int C[count3];//C[10000]
   for( a=0; a < count3; a++){

      C[a] = rand()%10;

   }




   //here we start testing the runtime for A[10]

   struct timeval start, stop;

   gettimeofday(&start, NULL);

   quicksort(A, 0, count1-1);

   gettimeofday(&stop, NULL);
   double quick1Time;
   quick1Time = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;
   //printf("%lf\n", quick1Time);




   gettimeofday(&start, NULL);

   selectionSort(A, count1);

   gettimeofday(&stop, NULL);
   double selection1Time;
   selection1Time = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;
   //printf("%lf\n", selection1Time);




   gettimeofday(&start, NULL);

   insertionSort(A, count1);

   gettimeofday(&stop, NULL);
   double insertion1Time;
   insertion1Time = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;
   //printf("%lf\n", insertion1Time);

   //now we test the runtime for B[100]

   gettimeofday(&start, NULL);

   quicksort(B, 0, count2-1);

   gettimeofday(&stop, NULL);
   double quick2Time;
   quick2Time = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;
   //printf("%lf\n", quick2Time);




   gettimeofday(&start, NULL);

   selectionSort(B, count2);

   gettimeofday(&stop, NULL);
   double selection2Time;
   selection2Time = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;
   //printf("%lf\n", selection2Time);




   gettimeofday(&start, NULL);

   insertionSort(B, count2);

   gettimeofday(&stop, NULL);
   double insertion2Time;
   insertion2Time = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;
   //printf("%lf\n", insertion2Time);

   //then we test the runtime for C[1000]
   gettimeofday(&start, NULL);

   quicksort(C, 0, count3-1);

   gettimeofday(&stop, NULL);
   double quick3Time;
   quick3Time = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;
   //printf("%lf\n", quick3Time);




   gettimeofday(&start, NULL);

   selectionSort(C, count3);

   gettimeofday(&stop, NULL);
   double selection3Time;
   selection3Time = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;
   //printf("%lf\n", selection3Time);




   gettimeofday(&start, NULL);

   insertionSort(C, count3);

   gettimeofday(&stop, NULL);
   double insertion3Time;
   insertion3Time = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;
   // printf("%lf\n", insertion3Time);



   //now we print out the runtime results in a comparison chart
   for(a=0; a<7; a++){

      printf("//");

      if(a==0 || a==2|| a==6){
         //these are the rows that need to draw lines as boundaries
         printf("+");
         int h;
         for(h=0; h<20; h++){
            printf("-");
         }
         printf("+");
         for(h=0; h<20; h++){
            printf("-");
         }
         printf("+");
         for(h=0; h<20; h++){
            printf("-");
         }
         printf("+");
         for(h=0; h<20; h++){
            printf("-");
         }
         printf("+");

      }
      else if(a==1){
         printf("|");
         printf(" Number of Elements |");
         printf("   Selection Sort   |");
         printf("   Insertion Sort   |");
         printf("     Quick Sort     |");
      }
      else if(a==3){
         printf("|");
         printf("               1000 |           %lf |           %lf |           %lf |", selection1Time, insertion1Time, quick1Time);
      }
      else if(a==4){
         printf("|");
         printf("              10000 |         %lf |           %lf |           %lf |", selection2Time, insertion2Time, quick2Time);
      }
      else if(a==5){
         printf("|");
         printf("             100000 |       %lf |           %lf |           %lf |", selection3Time, insertion3Time, quick3Time);
      }

      printf("\n");
   }

   return 0;  
}
	      
//quicksort function sorts out an array in ascending order using method quick sort                                                                                                                         
void quicksort(int number[],int l,int r){

   if(l<r){

      int s;
      s = hoarePartition(number, l, r);

      quicksort( number, l, s-1);
      quicksort( number, s+1, r);

      //printSubArray(number, l, r);
   }

}
//quicksort function sorts out an array in ascending order using method quick sort                                                                                                                          

//this is Hoare partition
int hoarePartition(int number[], int l, int r){

   int pivot = number[l];
   int i = l;
   int j = r+1;
   int swap;

   while(i<j){
      //do this until i>=j
      do{
         i++;
      }while(number[i] < pivot);

      do{
         j--;
      }while(number[j] > pivot);

      swap = number[i];
      number[i]= number[j];
      number[j]= swap;
   }

   swap = number[i];
   number[i]= number[j];
   number[j]= swap;
   //undo swap when i >= j 

   swap = number[l];
   number[l]= number[j];
   number[j]= swap;

   return j;
}

//below is the function for selection sort
void selectionSort(int number[], int count){

   int min;//this integer stores the index for the minimum value                                                                                                                                          
   int j;
   int i;
   int temp;// this value is used as an intermediate temp value in swapping A[i] and A[min]                                                                                                               
   //Then we implement the selection sort                                                                                                                                                                  
   for(i=0; i< count-1; i++){
      min = i;
      for( j = i+1; j < count; j++){
         if( number[j] < number[min]){
         min = j;}
      }

      temp = number[min];
      number[min] = number[i];
      number[i] = temp;

   }

}

//below is the function for insertion sort
void insertionSort(int number[],int count){

   int i;
   int v;
   int j;

   for( i=1; i < count; i++){
      v = number[i];
      j= i-1;
      while(j >=0 && number[j] > v){
         number[j+1]= number[j];
         j--;
      }
      number[j+1]=v;
   }

}



//below is the outputs I get for three tests for the program

//+--------------------+--------------------+--------------------+--------------------+
//| Number of Elements |   Selection Sort   |   Insertion Sort   |     Quick Sort     |
//+--------------------+--------------------+--------------------+--------------------+
//|               1000 |           1.460000 |           0.004000 |           0.060000 |
//|              10000 |         144.697000 |           0.044000 |           0.652000 |
//|             100000 |       14499.135000 |           0.455000 |           7.410000 |
//+--------------------+--------------------+--------------------+--------------------+

//+--------------------+--------------------+--------------------+--------------------+
//| Number of Elements |   Selection Sort   |   Insertion Sort   |     Quick Sort     |
//+--------------------+--------------------+--------------------+--------------------+
//|               1000 |           1.460000 |           0.004000 |           0.060000 |
//|              10000 |         144.783000 |           0.044000 |           0.640000 |
//|             100000 |       14495.026000 |           0.440000 |           7.160000 |
//+--------------------+--------------------+--------------------+--------------------+

//+--------------------+--------------------+--------------------+--------------------+
//| Number of Elements |   Selection Sort   |   Insertion Sort   |     Quick Sort     |
//+--------------------+--------------------+--------------------+--------------------+
//|               1000 |           1.460000 |           0.004000 |           0.059000 |
//|              10000 |         144.692000 |           0.044000 |           0.638000 |
//|             100000 |       14493.344000 |           0.443000 |           7.146000 |
//+--------------------+--------------------+--------------------+--------------------+
