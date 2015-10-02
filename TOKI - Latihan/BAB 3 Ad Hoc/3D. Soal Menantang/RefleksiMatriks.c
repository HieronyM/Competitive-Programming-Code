//  Program     :   Refleksi Matriks
//  Programmer  :   Hierony Manurung
//  Begin       :   07 November 2013, 23:12
//  Finish      :   -

#include<stdio.h>
typedef unsigned long long int l;

int main()
{
 int A,B;                   // Banyak baris dan kolom Matriks 1
 int C,D;                  // Banyak baris dan kolom matriks 2
 scanf("%d %d",&A,&B);

 int W,X;                  // Variabel loopingan untuk meminta inputan
 int Matriks1[A][B];       // Variabel penampung matriks1 
 l totalValueM1 = 0;
 
 for(W=0; W<A; W++)
    {
     for(X=0; X<B; X++)    // Proses pemasukan inputan data
      {
       scanf("%d",&Matriks1[W][X]);        
       totalValueM1 += Matriks1[W][X];
      }
     }
 
 scanf("%d %d",&C,&D);
 int Matriks2[C][D];   
 l totalValueM2 = 0;
 
 for(W=0; W<C; W++)
    {
     for(X=0; X<D; X++)    // Proses pemasukan inputan data
      {
       scanf("%d",&Matriks2[W][X]);        
       totalValueM2 += Matriks2[W][X];
      }
     }
     
/********** Memulai proses pengecekan *************/
     
     int putar=0,temp=0,statusSalah =0;
          
     
    /*  if(A != C || B !=D)
        {
         printf("tidak identik\n");
         //tidaksama=1;     
        }
    */
     if(totalValueM1 != totalValueM2)
       {
         printf("tidak identik\n");                   
       }     
      else
       {
          /* Untuk 0 derajat Coy (Identik )*/
          for(W=0; W<A; W++)
          {
           if(putar != temp)
            {
             temp++;
             break;       
            }
           for(X=0; X<B; X++)    
            {
             if(Matriks1[W][X] != Matriks2[W][X])
             {
              putar++;
              statusSalah = 1;
              break; 
             }
            }
          }
          
          /* Untuk Horizontal Coy (Nyaris Identik )*/
        if(temp == putar && statusSalah == 1)
        { 
         for(W=0; W<A; W++)
          {
           if(putar != temp)
            {
             temp++;
             break;       
            }
           for(X=0; X<B; X++)    
            {
            //printf("\n%d %d",Matriks1[W][X],Matriks2[((A-1) - W)][X]);
             if(Matriks1[W][X] != Matriks2[((C-1) - W)][X])
             {
              putar++;
              statusSalah = 2;
              break;
             }
            }
          }
        }
        
        /* Untuk Vertikal Coy (Nyaris Identik )*/
        if(temp == putar && statusSalah == 2)
        { 
         for(W=0; W<A; W++)
          {
           if(putar != temp)
            {
             temp++;
             break;       
            }
           for(X=0; X<B; X++)    
            {
             //printf("\n%d %d",Matriks1[W][X],Matriks2[W][((B-1)-W)]);
             if(Matriks1[W][X] != Matriks2[W][((D-1) - X)])
             {
              putar++;
              statusSalah = 3;
              break;
             }
            }
          }
        }
       
        /* Untuk Diagonal kanan bawah Coy (Nyaris Identik )*/
        if(temp == putar && statusSalah == 3)
        { 
         for(W=0; W<A; W++)
          {
           if(putar != temp)
            {
             temp++;
             break;       
            }
           for(X=0; X<B; X++)    
            {
             if(Matriks1[W][X] != Matriks2[X][W])
             {
              putar++;
              statusSalah = 4;
              break;
             }
            }
          }
        }
        
         /* Untuk Diagonal kiri bawah Coy (Nyaris Identik )*/
        if(temp == putar && statusSalah == 4)
        { 
         for(W=0; W<A; W++)
          {
           if(putar != temp)
            {
             temp++;
             break;       
            }
           for(X=0; X<B; X++)    
            {
             if(Matriks1[W][X] != Matriks2[((C-1) - X)][((D-1)-W)])
             {
              putar++;
              statusSalah = 5;
              break;
             }
            }
          }
        }       
      } 
   
   if(putar == 0 && totalValueM1 == totalValueM2)
     {
      printf("identik\n");      
     }
   else if(putar == 1 )
     {
      printf("horisontal\n");      
     }
  else if(putar == 2 )
     {
      printf("vertikal\n");      
     }
  else if(putar == 3 )
     {
      printf("diagonal kanan bawah\n");      
     }
 else if(putar == 4 )
     {
      printf("diagonal kiri bawah\n");      
     }
 else if(putar == 5 )
     {
      printf("tidak identik\n");      
     }                
  return 0;   
}
