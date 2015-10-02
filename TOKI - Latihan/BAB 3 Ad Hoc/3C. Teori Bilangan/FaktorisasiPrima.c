        /*
          Program     :  Faktorisasi Prima (Latihan 3C TOKI)
          Programmer  :  Hierony Manurung
          Start Date  :  3 November 2013, 22:40
          Finish Date :  
        */
#include<stdio.h>
                
int main()
  {
    long N;
    scanf("%ld",&N);                      // Nampung nilainya
    
    if(N == 1)
    {
     printf("2^0\n",N);    
    }
    
    else{
     int count=0,nilai;                    //  nilai = Factors ,  Count = Banyak pembagian yang dilakukan dengan Factor    
        /* When the N is can be mod by 2 */
        if(N % 2 ==0)
         {
           while(N %2 ==0)
            {
               N = N /2;
               nilai = 2;
               count++;          
            }
            if(count == 1)
              {
                if(N == 1)
                {
                   printf("%d\n",nilai);
                }
                else
                {
                  printf("%d x ",nilai);   
                }      
              }
            else
              {
                if(N == 1)
                {       
                 printf("%d^%d\n",nilai,count);            
                }
                else
                {
                 printf("%d^%d x ",nilai,count);   
                }
              }
             count = 0;                
          }
         
         /* When the N is can be mod by 3 */
         if(N % 3 ==0)
         {
           while(N % 3 ==0)
            {
               N = N / 3;
               nilai = 3;
               count++;         
            }
            if(count == 1)
              {
                if(N == 1)
                { 
                  printf("%d\n",nilai);
                }
                else
                {
                  printf("%d x ",nilai); 
                }      
              }
            else
              {
                if(N == 1)
                {        
                  printf("%d^%d\n",nilai,count);            
                }
                else
                {
                  printf("%d^%d x ",nilai,count);  
                }
              }
              count = 0;                
          }
         
         /* When the N is can be mod by 5 */
         if(N % 5 == 0)
         {
           while(N % 5 ==0)
            {
               N = N / 5;
               nilai = 5;
               count++;          
            }
            if(count == 1)
              {
                if(N == 1)
                {
                  printf("%d\n",nilai);      
                }
                else
                {
                  printf("%d x ",nilai);  
                }
              }
            else
              {
                if(N == 1)
                {  
                  printf("%d^%d\n",nilai,count);            
                }
                else
                {
                  printf("%d^%d x ",nilai,count);  
                }
              }
              count = 0;                
          }
          
          /* Untuk pangkat */
          int kuadrat = sqrt(N);
         if(N % kuadrat == 0)
           {
             while(N % kuadrat == 0)
             {
              N = N / kuadrat;
              nilai = kuadrat;
              count++;
             }
             if(count == 1)
              {
                if(N == 1)
                {
                  printf("%d\n",nilai);      
                }
                else
                {
                  printf("%d x ",nilai);  
                }
              }
            else
              {
                if(N == 1)
                {  
                  printf("%d^%d\n",nilai,count);            
                }
                else
                {
                  printf("%d^%d x ",nilai,count);  
                }
              }
              count = 0;     
           } 
         
         /* When the N is 1 or N itself(cannot mod by 2,3,5) */
         if(N % N == 0 && N!= 1)
          {
                printf("%d\n",N);                      
          }
   }  
  getch(); 
  return 0;
  }
