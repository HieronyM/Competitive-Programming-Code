#include<stdio.h>
 
int jaw[27][27];
int row,column,bola,nBola=0;
 
 // The recursion lies here
void FloodBola(int x,int y)
 {
    nBola++;
    jaw[x][y] = 0;
    if (x > 0 || x < row+1 || y > 0 || y < column+1)
     { 
      if(jaw[x][y-1] == bola)
        {
            FloodBola(x,y-1);
        }
         
      if(jaw[x][y+1] == bola)
        {
            FloodBola(x,y+1);
        }
         
      if(jaw[x-1][y] == bola )
        {
            FloodBola(x-1,y);
        }
      
      if(jaw[x+1][y] == bola)
        {
            FloodBola(x+1,y);
        }
         
    }
 }
 
int main()
  {
    short int b,c;
 
        scanf("%hd%*c %hd%*c",&row,&column);
        for(b = 0; b < row; b++)
          {
            for(c = 0; c < column; c++)
            {
                scanf("%d",&jaw[b][c]);
            }
          }
         
        // Start Recursion
        int max = 0,d,e;
        for(b = 0; b < row; b++)
          {
            for(c = 0; c < column; c++)
            {
                if(jaw[b][c] != 0)
                 {
                    bola = jaw[b][c];
                    nBola = 0;
                    FloodBola(b,c);
                     
                    if(max < nBola)
                      {
                        max = nBola;
                      }
                 }
             }
          }
              
         int nilai = max * (max - 1);       
                              
            /*  Debugging
         printf("\n");
          
        // Hasil Rekursi
        for(b = 0; b < row; b++)
          {
              for(c = 0; c < column; c++)
            {
                printf("%d ",jaw[b][c]);
            }
            printf("\n");
          }
          */
         
          printf("%d\n",nilai);
           
    return 0;    
  }
