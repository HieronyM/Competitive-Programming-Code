#include <stdio.h>

int main()
{
    long N;
    scanf("%ld",&N);
    
    if(N > 0)
    {
     printf("%ld %ld\n",N,N+1);
    }
    
    else if(N < 0)
      {
        printf("%ld %ld\n",N-1,N);      
      }
      
    return 0;
}
