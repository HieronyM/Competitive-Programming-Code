#include<stdio.h>

int main()
{
  int N;
  scanf("%d",&N);
  
  if(N >= 0 && N < 10)
  {
   printf("satuan\n");    
  } 
  
  else if(N >= 10 && N < 100)
  {
   printf("puluhan\n");    
  }
   
   else if(N >= 10 && N < 100)
  {
   printf("puluhan\n");    
  }
   else if(N >= 100 && N < 1000)
  {
   printf("ratusan\n");    
  } 
    else if(N >= 1000 && N < 10000)
  {
   printf("ribuan\n");    
  }
  
   else if(N >= 10000 && N < 100000)
  {
   printf("puluhribuan\n");    
  }   
     
 return 0;   
}
