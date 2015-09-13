// Program    : Bilangan agak Prima
// Programmer : Hierony Manurung
// Begin      : 6 June 2013, 16:17
// Finish     : -


#include<stdio.h>
int main()
{
 int T;          
 scanf("%d",&T);             // banyaknya Percobaan
 long N[T];                  // Variabel Penampung Input
 
 int a;
 for(a=0; a < T; a++)
   {
    scanf("%d",&N[a]);      
   }
 
 for(a=0; a < T; a++)
    {
       if(N[a] <=1)               // Pengecekan bilangan negatif dan 0 dan 1
        {
         printf("TIDAK\n");      
        }  
      
       else if(N[a] <= 11)
        {
          printf("YA\n");
        } 
       else 
         {
           if(N[a] %2 != 0 && N[a] %3 != 0 && N[a] %5 != 0)      // Pengecekan bila nilai == bilangan prima
            {
              printf("YA\n");           
            }
           else if(N[a]%4 ==0)
            {
             printf("TIDAK\n");   
            }
           else if(N[a]%6 ==0)
            {
             printf("TIDAK\n");   
            }
           else if(N[a]%10==0)
            {
             printf("TIDAK\n");
            }
            else
            {
             int b;
             int count=0;
             for(b=2; b < N[a]; b++)
                {
                 if(N[a]%b ==0)
                  {
                   count++;           
                  }
                  
                  if(count > 2)
                     {
                      printf("TIDAK\n");
                      break;      
                     }     
                }
               printf("YA\n");                  
            }
        }                 
    }

  getch();
  return 0;   

}

