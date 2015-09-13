#include <stdlib.h>
#include <stdio.h>

int main()
  {
     int T;                
     scanf("%d",&T);
     
     int input[T][3];   
     int a,b;
     
     for(a=0; a<T; a++)
        {
         for(b=0; b<3; b++)
            {
             scanf("%d",&input[a][b]);     
            }     
        }
        
     int temp,counter;
     for(a=0; a<T; a++)
        {
          counter=0;
          for(b=0; b<3-1 ;b++)
             {
              if(input[a][b] > input[a][b+1] ) 
                {
                  temp= input[a][b];
                  input[a][b] = input[a][b+1];
                  input[a][b+1]= temp;           
                }
                counter++;
                
              if(counter==2)
                {
                 if(input[a][0] > input[a][1])
                   {
                    temp=input[a][0];
                    input[a][0]=input[a][1];
                    input[a][1]=temp;
                   }        
                }      
             }    
        }
     
     a=0;
     while(a!=T)
         {
          printf("Case %d: %d\n",a+1,input[a][1]);      
          a++;
         }
              
     return 0;     
  }
