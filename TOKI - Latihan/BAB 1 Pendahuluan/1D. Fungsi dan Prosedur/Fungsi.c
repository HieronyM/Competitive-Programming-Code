#include <stdio.h>

int factorial(int n);
int main()
{
    int n;
    scanf("%d",&n);
    
  if(n < 0 | n > 10)
   {
     printf("ditolak\n");
   }
  else
   {
    printf("%d\n",factorial(n));                     
   }
}

int factorial(int n)
{
     int a,total=1;   
     for(a=1; a<=n; a++)
        {
          total = total*a;    
        }
        return total;
       
    
}
