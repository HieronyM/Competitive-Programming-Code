        /*
          Program     :  Kelipatan 4 atau 7 (Latihan 3C TOKI)
          Programmer  :  Hierony Manurung
          Start Date  :  3 November 2013, 22:40
          Finish Date :  3 November 2013, 22:51
        */
#include<stdio.h>
                
int main()
  {
   int T;                //    Nampung jumlah masukan
   scanf("%d",&T);
   
   long N[T],hasilbagi;
   long long total = 0;
   int a,b;
   for(a=0; a<T; a++)
     {
      scanf("%ld",&N[a]);
      
      /* Untuk Kelipatan 4 */
      hasilbagi = N[a] / 4;
      if(hasilbagi % 2 == 0)
      {
        hasilbagi = ((hasilbagi/2) * (1 + hasilbagi));
        total = total + (4 * hasilbagi);
      }
      else
      {
        hasilbagi = (hasilbagi * ((1 + hasilbagi)/2));
        total = total + (4 * hasilbagi); 
      } 
      
      /* Untuk kelipatan 7 */         
       hasilbagi = N[a] / 7; 
       if(hasilbagi % 2 == 0)
       {
        hasilbagi = ((hasilbagi/2) * (1 + hasilbagi));
        total = total + (7 * hasilbagi);
       }
       else
       {
        hasilbagi = (hasilbagi * ((1 + hasilbagi)/2));
        total = total + (7 * hasilbagi); 
       }
      
      /* Untuk kelipatan 4 dan 7 (total dikurangi) */ 
       hasilbagi = N[a] / 28;
       if(hasilbagi % 2 == 0)
      {
        hasilbagi = ((hasilbagi/2) * (1 + hasilbagi));
        total = total - (28 * hasilbagi);
      }
      else
      {
        hasilbagi = (hasilbagi * ((1 + hasilbagi)/2));
        total = total - (28 * hasilbagi); 
      }   
      printf("%lld\n",total);
     }
  //    printf("%ld\n",total);
  
   return 0;       
  }
