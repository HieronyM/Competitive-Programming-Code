// Program      : Procedure
// Programmer   : Hierony Manurung
// Begin        : 11 Juni 2013, 11:36
// Finish       : -

#include<stdio.h>

int main()
{
    long nilai;
    while(scanf("%ld",&nilai)!=EOF)
      {
       if(nilai < 10 )
         {
          printf("satuan\n");      
         }
       else if(nilai >= 10 && nilai < 100)                           
         {
          printf("puluhan\n");      
         }
       else if(nilai >= 100 && nilai < 1000)                           
         {
          printf("ratusan\n");      
         }
       else if(nilai >= 1000 && nilai < 10000)                           
         {
          printf("ribuan\n");      
         }    
       else
         {
          printf("puluhribuan\n");                         
         }
      }

 return 0;   
}
