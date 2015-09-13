#include<stdio.h>

int main()
{
  long N;
  scanf("%ld",&N);
  
  if(N == 0)
  {
   printf("nol\n");    
  } 
  
  else if(N < 0)
  {
   printf("negatif\n");    
  }
   
   else
  {
   printf("positif\n");    
  }
  
    
 return 0;   
}
