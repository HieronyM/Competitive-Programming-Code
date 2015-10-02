#include <stdio.h>

int prim[77779];
int cekprim[999999]; 
int main()
  {
    int i,j,k=1;
    for(i = 1; i < 1000000; i++)cekprim[i] = 1;
    for(i = 2; i < 1000000; i++)
          if(cekprim[i]== 1)
          {
                     prim[k] = i;
                     for(j = i; j < 1000000; j=j+i) 
                     {
                           cekprim[j] = 0;
                     }
                     k++;
          }
                     
    long N;
    scanf("%ld",&N);                      // Nampung nilainya
   
    
    if(N == 1)
    {
     printf("2^0\n");    
    }
     
   int h=1,count,status;
  
   if(N != 1)
   {  
    while(N > 1)
    {
      status = 0;
      count = 0; 
      while(N % prim[h] == 0)
      {
        count++;
        N = N / prim[h];
        status = 1;      
      }
       if(N != 1)
       {
          if(count > 1)
            {
             printf("%ld^%d x ",prim[h],count);      
            }
          else if(status  == 1)
            {
             printf("%ld x ",prim[h]);               
            }     
       }
        else
        {
          if(count > 1)
            {
             printf("%ld^%d\n",prim[h],count);      
            }
          else if(status == 1)
            {
             printf("%ld\n",prim[h]);               
            }
        }
        h++;
    }
  }
   return 0;            

}
