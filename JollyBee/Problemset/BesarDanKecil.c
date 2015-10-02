#include<stdio.h>
#include<string.h>

int main()
  {
   int TC;
   scanf("%d",&TC);
   char kata[101];
   char vokal[11] = "AIUEOaiueo";
   
   int a,n,b,c,count[TC];
   for(a=0; a < TC; a++)
      {
       scanf("%s",&kata);
       //printf("%s",kalimat);
       n = strlen(kata);   
       for(b=0; b < n; b++)
         {
          if(b % 2 == 0)
            {
             kata[b] = kata[b] - 32;
            }
            printf("%c",kata[b]);                     
         }
         printf("\n");
      }              
   return 0;
  }
