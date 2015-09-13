#include<stdio.h>

int main()
{
    long N;
    scanf("%ld",&N);
    
    int a,b,nilai=1,pangkat=2;
    for(a=1; a<=20; a++)
       {
        if(N==1)
          {
           printf("TRUE\n");
           break;     
          }     
       
        nilai = nilai*pangkat;
        if(nilai == N)
          {
           printf("TRUE\n");
           break;      
           }
           
         else
           {
            if(a==20 && nilai !=N)
             {
              printf("FALSE\n");       
             }           
           }     
       }
    
      return 0;
}



