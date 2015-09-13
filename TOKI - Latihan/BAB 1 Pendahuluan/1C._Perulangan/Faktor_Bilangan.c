#include<stdio.h>

int main()
{
    int N,a;
    scanf("%d",&N); 
    for(a=N; a>=1; a--)
       { 
         if(N % a == 0)
           {
            printf("%d\n",a);         
           }         
       }      
    return 0;
}


