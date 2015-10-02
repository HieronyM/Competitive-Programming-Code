#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int Data[1001];
int main()
  {
   int TC;
   scanf("%d",&TC);
   int a,nData,b;
   for(a=0; a < TC; a++)
      {
       scanf("%d",&nData);
       for(b = 0 ; b < nData; b++)
       {
        scanf("%d",&Data[b]);     
       }
       sort(Data,Data + nData);
       
       for(b = nData-1; b >=0; b--)
        {
         if(b == 0)
           {
            printf("%d\n",Data[b]);
            break;     
           }
         printf("%d ",Data[b]);    
        }     
      }
      
   return 0;       
  }
