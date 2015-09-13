// Program      : Perkalian Matriks
// Programmer   : Hierony Manurung
// Begin        : 12 Juni 2013, 19:54
// Finish       : 13 Juni 2013, 17:12

#include<stdio.h>
int main()
{
 int A,B;
 scanf("%d %d",&A,&B);
 
 int matriks1[A][B];            // Bagian Matriks 1
 int w,x;
 for(w=0; w<A; w++)
    {
    for(x=0; x<B; x++)
      {
       scanf("%d",&matriks1[w][x]);      
      }      
    }
 
 int C,D;                        
 scanf("%d %d",&C,&D);

 int matriks2[C][D];           // Bagian Matriks 2
 for(w=0; w<C; w++)
    {
    for(x=0; x<D; x++)
      {
       scanf("%d",&matriks2[w][x]);      
      }      
    }

  /********** Debug apakah Matriks berhasil ditampung *******/
/*
printf("\n Proses melihat hasil penampungan matriks1 : \n");
// Matriks 1
for(w=0; w<A; w++)
   {
    for(x=0; x<B; x++)
       {
        printf("%d ",matriks1[w][x]);     
       }
       printf("\n");     
   }

printf("\n Proses melihat hasil penampungan matriks2 : \n");
// Matriks 2
for(w=0; w<C; w++)
   {
    for(x=0; x<D; x++)
       {
        printf("%d ",matriks2[w][x]);     
       }
       printf("\n");     
   }

/**** Hasil Jawaban ****/
/*
printf("Hasil perkalian matriks1 dan matriks2 : \n");
  printf("\n\n");  
*/
  
  int y;
  int hasil[A][D];  
  int total=0;
  int counter=0;
   for(w=0; w<A; w++)
      {
       for(x=0; x<D; x++)
          {
           for(y=0; y<C; y++)
              {
               counter++;     
               total = total + (matriks1[w][y] * matriks2[y][x]);                     
              }
            hasil[w][x]= total;
           
           if(x!= D-1)
              {
               printf("%d ",hasil[w][x]);
              }
           else
              {
               printf("%d",hasil[w][x]);           
              }   
            total=0;
            counter=0;  
          }
        printf("\n");       
      }   
 return 0;   
}
