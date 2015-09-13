        /*
          Program     :  Kelipatan 4 atau 7 (Latihan 3C TOKI)
          Programmer  :  Hierony Manurung
          Start Date  :  4 November 2013, 17:53
          Finish Date :  -
        */
        
#include<stdio.h>
long long prima[7777];
int main()
 {
   int T;
   scanf("%d",&T);
   int data[T],max=0;
   
   short int a;
   for(a=0; a<T; a++)
     {
       scanf("%d",&data[a]);
       if(max < data[a])
         {
          max = data[a];    
         }     
     }
 int nPrime =3;
 prima[0] = 2;
 prima[1] = 3;
 prima[2] = 5;
 long long nilai = 7;
 while(nPrime != max)
  {
   if(nilai % 2 != 0 && nilai % 3 != 0 && nilai % 5 != 0)
    {
     nPrime++;
     prima[nPrime-1] = nilai;       
    }
    nilai += 2;            
  }  
  
  for(a=0; a<T; a++)
     {
      printf("%lld\n",prima[data[a]]);     
     }
  getch();
  return 0;
 }
