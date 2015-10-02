        /*
          Program     :  Bola & Gelas (Latihan 3A TOKI)
          Programmer  :  Hierony Manurung
          Start Date  :  2 November 2013, 05:55
          FInish Date :  -
        */
int temp;

void swap(int Data[],int x , int y)
 {
 	temp = Data[x];
 	Data[x] = Data[y];
 	Data[y] = temp;
 }


#include<stdio.h>
//#include<conio.h>

int main()
 {
   int N,M;                        //   Variabel penampung banyak bola & banyak perubahan gelas        
   scanf("%d %d",&N,&M);
   
   int b,c;      //    Variabel penampung Perubahan gelas yang dilakukan         
   
   int a,Data[N+1];
   for(a = 1 ; a <= N; a++)
     {
       Data[a] = a;
     }
   
   for(a = 0; a < M; a++)
     {
       scanf("%d %d",&b, &c);
	   swap(Data,b,c);      
     }
     
   int Q,e;                         // Variabel penampung banyak pertanyaan
   scanf("%d",&Q);  
   
   int Ans[Q];
   for(a=0; a<Q; a++)
     {
      scanf("%d",&e);
	  printf("%d\n",Data[e]);  
     }
   
   /*for(a=0; a<Q; a++)
     {
      printf("%d\n",Ans[a]);   
     }  
   */   
   return 0;
 }
