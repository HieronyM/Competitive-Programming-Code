// Program    : Cek Bilangan Prima
// Programmer : Hierony Manurung
// Begin      : 6 June 2013, 16:01
// Finish     : 6 June 2013, 16:16

#include<stdio.h>
int main()
{
   int input;
   
   while(scanf("%d",&input)!=EOF)
     {
      if(input <=0)               // Pengecekan bilangan negatif
        {
         printf("TIDAK\n");      
        }  
      else if(input > 0)
        {
         if(input <=3 && input !=1)           // Bilangan <=3 (Untuk negatif sudah ditangani di if pertama)
           {
            printf("YA\n");      
           }
        else if(input <=3 && input ==1)           // Bilangan <=3 (Untuk negatif sudah ditangani di if pertama)
           {
            printf("TIDAK\n");      
           }
         
         
         else if(input > 3)
           {
            if(input%2 ==0)
              {
               printf("TIDAK\n");        
              }
            
            else if(input%2 !=0 && input%3 !=0 && input%5 !=0)
              {
               printf("YA\n");             
              }
            
             else 
              {
               printf("TIDAK\n"); 
              }            
           }
        }                        
     } 
    
 return 0;   
}
