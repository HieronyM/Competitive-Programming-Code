#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

int main()
  {
   int TC;      // Banyaknya Testcase
   scanf("%d",&TC);
   
   int a,b,c;
   int N,M,BallNumber[100],count,Q1,Q2;
   for(a=0; a < TC; a++)
     {
        scanf("%d %d",&N,&M);
        for(b=0; b < N; b++)
          {
             scanf("%d",&BallNumber[b]);     
          }
        sort(BallNumber,BallNumber+N);  
        for(b=0; b < N; b++)
          {
          //   printf("[%d]%d\n",b,BallNumber[b]);     
          }
        
        printf("Kasus #%d:\n",a+1);  
        for(b = 0; b < M; b++)
           {
             c=0;
             count = 0;
             scanf("%d %d",&Q1,&Q2);
             while(c != N)
               {
                if(BallNumber[c] > Q2)
                 {
                  break;
                 }
                else if(BallNumber[c] > Q1 && BallNumber[c] < Q2)
                {
                 count++;    
                } 
                 //printf("Nilai yang dicek : %d\n",BallNumber[c]);
              //   printf("Count saat ini : %d\n",count);
                 c++; 
               }
               printf("%d\n",count);   
           }      
     } 
     return 0;      
  }
