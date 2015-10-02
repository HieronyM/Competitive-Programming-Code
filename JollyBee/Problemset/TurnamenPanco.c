#include<stdio.h>

int main()
 {
  int TC;
  scanf("%d",&TC);
  
  int nData,a,b;
  int nPeserta,max,pesertaTerkuat,kekuatanPeserta;
  for(a=1; a<=TC; a++)
    {
     nPeserta =1;
     max = 0;
     scanf("%d",&nData);
     for(b=1; b<= nData; b++)
       {
        nPeserta *= 2;      
       }
     for(b=1; b<= nPeserta; b++)
     {
      scanf("%d",&kekuatanPeserta);
      if(max < kekuatanPeserta)
        {
         max = kekuatanPeserta;
         pesertaTerkuat = b;    
        }
     }
     printf("%d\n",pesertaTerkuat);    
    }
    
  return 0;        
 }
