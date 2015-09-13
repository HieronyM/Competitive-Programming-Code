#include <stdlib.h>
#include <stdio.h>

int main()
  {
   int t;
   scanf("%d",&t);
   
   long a[t],b[t];
   int c;
   for(c=0; c<t; c++)
      {
       scanf("%ld %ld",&a[c],&b[c]);     
      }
      
   for(c=0; c<t; c++)
      {
       if(a[c] < b[c])
         {
          printf("<\n");     
         }
       else if(a[c] > b[c])
         {
         printf(">\n");
         }
       else
         {
          printf("=\n");             
         }  
                 
      }
      
     getch();
     return 0;      
  }
