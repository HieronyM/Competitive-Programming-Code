#include <stdio.h>

void hasil(long long int *x,int y);
int main()
{
    int t,j;
    long long int arr[100000];
    scanf("%d",&t);
    for(j=1;j<=t;j++)
       {
          scanf("%lld",&arr[j]);            
       }
    hasil(arr,t);
    return 0;
}
void hasil(long long int *x,int y)
{
    int i,t,p=0,k,l;
    long long int s[100000];
   for(i=1;i<=y;i++)
       {
         t=x[i];
         l=x[i];
         for(k=1;k<=t;k++)
            {
              p=(p*10)+(l%10);
              l=l/10;
              if(l==0)
                {
                  break;    
                }               
            }
         s[i]=p;
         p=0;
       }
   for(i=1;i<=y;i++)
      {
        printf("%d\n",s[i]);            
      }
}
