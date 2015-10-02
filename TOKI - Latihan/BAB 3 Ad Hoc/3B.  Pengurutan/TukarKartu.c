        /*
          Program     :  TukarKartu (Latihan 3B TOKI)
          Programmer  :  Hierony Manurung
          Start Date  :  3 November 2013, 06:35
          Finish Date :  3 November 2013, 06:37  (Fast, because I using the Insertion sort Algorithm in Previous Program)
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
   int key,i,sortAmount=0;
   for(a=1; a<N;a++)
     {
      key = data[a];
      i = a-1;
      
      while(i >=0 && data[i] > key)
           {
             data[i+1] = data[i];
             i = i-1;
             data[i+1] = key;
             sortAmount++;       
           }
     }
   
   /* To Test that the Sort is succesfull 
   
   for(a=0; a<N; a++)              
     {
      printf("%d ",data[a]);      
     }
   
   */
   
   /* Print the minimum sort of the collection data */
   printf("%d\n",sortAmount);  
   return 0;       
  }
