#include<stdio.h>
#include<string.h>

int main()
  {
   int TC;
   scanf("%d",&TC);
  
   char kata[201],temp[201];
   int status,i,count,a,n,b,c;
   char CheckedChar;
   
   for(a=0; a < TC; a++)
    {
     temp[2] = '\0';
     scanf("%s",&kata);
     n = strlen(kata);                  //  Menghitung banyak huruf
     temp[0] = kata[0];                 //  Nampung huruf pertama       
     count = 1;                         //  Minimal huruf unik
     i = 1;                             // Huruf pertama wajib unik
     
    // printf("====Kondisi temp sebelum diisi : %s====\n",temp);
     for(b=1; b < n; b++)
       {
        CheckedChar = kata[b];
        status = 0;        
       // printf("----Huruf yang dicek : %c----\n",kata[b]);
        
        for(c=0; c < i; c++)
        {
          if(kata[b] == temp[c])
          { 
            status = 1;
            break;
          }
         }   
         
         // Jika hurufnya masih unik
         if(status == 0)
          {
           temp[i] = CheckedChar;
         //   printf("******Huruf yang dimasukkan : %c index ke [%d]*****\n",CheckedChar,i);
           count++;
           i++;        
          }   
       }
       printf("%d\n",count);
       //printf("Huruf yang ditampung : %s\n",temp);
       kata[n] = '\0';
    }
    
   //getch();
   return 0;       
  }
