        /*
          Program     :  Median (Latihan 3B TOKI)
          Programmer  :  Hierony Manurung
          Start Date  :  2 November 2013, 21:00
          Finish Date :  3 November 2013, 06:30
        */
        
#include<stdio.h>
int main()
  {
   /* Store the array block data */
   long N;
   scanf("%ld",&N);
   
   /* Store Data Array */
   
   int data[N];                    
   short int a;
   for(a=0; a<N; a++)              
     {
      scanf("%d",&data[a]);      
     }
   
   /* Proses Sorting (Insertion sort (Ascending) ) */
   int key,i;
   for(a=1; a<N;a++)
     {
      key = data[a];
      i = a-1;
      
      while(i >=0 && data[i] > key)
           {
             data[i+1] = data[i];
             i = i-1;
             data[i+1] = key;       
           }
     }
   
   /* To Test that the Sort is succesfull 
   
   for(a=0; a<N; a++)              
     {
      printf("%d ",data[a]);      
     }
   
   */
   
   /* Calculate the median */
   
   float median;
   if(N % 2 == 1)                 //      Number of data is Odd
     {
        median = data[N/2];  
     }     
   else
     {
       median = data[N/2] + data[(N/2)-1];
       median = median/2;       
     }  
     
   /* Print the median of the collection data */
   
   printf("%.2f\n",median);  
   return 0;       
  }
