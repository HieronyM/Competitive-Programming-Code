#include <stdio.h>

int main()
  {
    char input[1000];
    gets(input);      
    
    int a=0,n=0;
    while(input[a]!='\0')
        {
         n++;
         a++;                
        }
    
    for(a=n-1; a>=0; a--)
       {
        printf("%c",input[a]);     
       }
    printf("\n");
    return 0;   
  }
