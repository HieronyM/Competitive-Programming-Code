// Program      : Matriks
// Programmer   : Hierony Manurung
// Begin        : 12 Juni 2013, 18:58
// Finish       : 12 Juni 2013, 19:53

int main()
{
 int M,N;
 scanf("%d %d",&M,&N);
 
 int input[M][N];
 int a,b;
 for(a=0; a<M; a++)
    {
     for(b=0; b<N; b++)
        {
         scanf("%d",&input[a][b]);     
        }     
    }
    
 for(a=0; a<N; a++)
    {
     for(b=M-1; b>=0; b--)
        { 
          if(b!=0)
          {           
           printf("%d ",input[b][a]);
          }
          else
           {
           printf("%d",input[b][a]);          
           }    
        }
        printf("\n");     
    }
       
 return 0;   
}
