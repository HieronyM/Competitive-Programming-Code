#include<stdio.h>

char kalimat [10003];
char kata [203];

int main()
  {
   gets(kalimat);
   //printf("%s",kalimat);
   int i,a,status,j=0,nilaiPertama=0;
   while(kalimat[j] != '\0')
    {
     i =0;
     status = 1;
     while(kalimat[j] != ' ' && kalimat[j] != '\0')
     {
      kata[i] = kalimat[j];
      i++;
      j++;                 
     }
     j++;
    for(a=0; a < (i/2) ; a++)
       {
        if(kata[a] != kata[(i-1)-a])
          {
           status = 0;
           break;        
          }                   
       }
    if(status == 1 && nilaiPertama == 0)
      {
        for(a=0; a<i ; a++)
        {      
         printf("%c",kata[a]);
        }
      kata[i] = '\0';
      nilaiPertama++;
      //printf("(1)");                     
    }
    
     else if(status == 1)
      {
        printf(" ");
        for(a=0; a<i ; a++)
        {      
         printf("%c",kata[a]);
        }
       kata[i] = '\0';
      //nilaiPertama == 1;                     
       //printf("(2)");
    }
  }  
    printf("\n");
    return 0;
}
  
