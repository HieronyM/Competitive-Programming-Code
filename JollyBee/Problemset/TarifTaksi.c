#include<stdio.h>

int main()
 {
   int TC;
   scanf("%d",&TC);
   
   int a,biaya2KM,biaya100M,jarak;
   int subbiaya;
   for(a=1; a <= TC; a++)
     {
      scanf("%d %d %d",&biaya2KM, &biaya100M, &jarak);
      if(jarak <= 2000)
        {
         printf("%d\n",biaya2KM);      
        }
      else
        {
          subbiaya =  ((jarak - 2000)/100) * biaya100M;
          printf("%d\n",biaya2KM+subbiaya);                             
        }      
     }
   
   return 0;        
 }
