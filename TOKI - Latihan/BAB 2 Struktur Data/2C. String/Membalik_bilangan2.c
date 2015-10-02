#include<stdio.h>
#include<string.h>
 
int main()
  {
   int N;
   char input[10];          //  Penampung Bilangan
   scanf("%d",&N);          //  Banyak Testcase
   
   int b,c,found,bykkarakter,ceknol=0;
   while (N != 0)     
      {
       found =0;
       scanf("%s",&input);
       bykkarakter = strlen(input);
       int A = atoi(input);
        
       /*if(strcmp(input,"0") == 0)
         {
           printf("0\n");
         }
         */
         if(A ==0)
           {
            printf("%d\n",A);      
           }
       else
         {              
           for(b=bykkarakter-1; b>=0; b--)
              { 
                 if(input[b] != '0')
                   {
                     found = 1;      
                   }
                  
                 if(found == 1)
                   {
                     printf("%c",input[b]);     
                   }              
                
                 else
                   {
                    printf("");            
                   }                              
         }
              N--;
              printf("\n");       
      }
   }     
      
   return 0;      
  }
