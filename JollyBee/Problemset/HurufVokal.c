#include<stdio.h>
#include<string.h>


char kalimat[100000];
int main()
  {
   int TC;
   scanf("%d",&TC);
   char vokal[11] = "AIUEOaiueo";
   
   int a,n,b,c,count[TC];
   for(a=0; a < TC; a++)
      {
       gets(kalimat);
       //printf("%s",kalimat);
       n = strlen(kalimat);
       count[a] = 0;     
       for(b=0; b < n; b++)
         {
            for(c=0; c < 10; c++)
              {
               if(kalimat[b] == vokal[c])
                {
                 count[a]++;
                }      
              }                    
         }
      }
      
   // Print the amount
   for(a=0; a < TC; a++)
      {
       printf("%d\n",count[a]);
      }       
   getch();       
   return 0;
  }
