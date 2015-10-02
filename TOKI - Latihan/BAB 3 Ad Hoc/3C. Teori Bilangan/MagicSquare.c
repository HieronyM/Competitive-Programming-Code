        /*
          Program     :  Magic Square (Latihan 3C TOKI)
          Programmer  :  Hierony Manurung
          Start Date  :  6 November 2013, 14:47
          Finish Date :  6 November 2013, 15:20
        */
long long data[1000005];
#include<stdio.h>
int main()
 {
  int T;
  scanf("%d",&T);
  
  long long total;
  long long a,b;
  for(a=0; a<T; a++)
    {
    total = 0;
     scanf("%lld",&data[a]);
     for(b=1; b<=data[a]; b++)
        {
          total = total + b;    
        }
     for(b=data[a]*data[a]; b > ((data[a]*data[a]) - data[a]); b--)      
        {
         total = total + b;    
        }
     printf("%lld\n",total/2);
    }
   
  return 0;        
 }
