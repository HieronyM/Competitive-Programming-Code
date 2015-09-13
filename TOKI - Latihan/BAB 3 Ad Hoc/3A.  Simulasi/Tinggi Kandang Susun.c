        /*
          Program     :  Tinggi Kandang Susun (Latihan 3A TOKI)
          Programmer  :  Hierony Manurung
          Start Date  :  2 November 2013, 10:02
          Finish Date :  2 November 2013, 10:59
        */
        
#include<stdio.h>
//#include<conio.h>

int main()
  {
   long N,K;             //  Banyak kucing dan jumlah kucing di 1 kandang
   scanf("%ld %ld",&N,&K);
   
   int tinggiKandang[N],a;
   for(a=0; a<N; a++)                      //Meminta masukan tinggi kandang maksimal yang diinginkan kucing
     {
      scanf("%d",&tinggiKandang[a]);                 
     }
   
   int count=0,max=0,totalTinggi = 2;
   for(a=0; a<N; a++)
      {
          if(max < tinggiKandang[a])       // Mencari permintaan tinggi kandang yang maksimum
            {
             max = tinggiKandang[a];    
            }
           count++;
           if(count == K)
             {
              totalTinggi = totalTinggi + max;
             // printf("\n\nTotal tinggi : %d",totalTinggi);
              max = 0;
              count=0;     
             }       
      }
         int banyaksisi = (N-1)/K;
         totalTinggi = totalTinggi  + max + banyaksisi;     

      printf("%d\n",totalTinggi); 
   getch();
   return 0;       
  }
