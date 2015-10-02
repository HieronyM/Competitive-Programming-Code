#include<stdio.h>

int Data[100000];
int main()
 {
  int TC;
  scanf("%d",&TC);          //  Banyaknya Testcase
  
  int nData,a,b;
  int key,i;                    // Untuk Sorting
  unsigned long long int totalNilai;
  for(a=0; a < TC; a++)
    {
     scanf("%d",&nData);      // Banyak data per Testcase
     Data[nData];
     for(b=0; b < nData; b++)
        {
         scanf("%d",&Data[b]);     
        }
        
        // Proses Sorting
     
     for(b=1; b < nData;b++)
       {
        key = Data[b];
        i = b-1;
      
        while(i >=0 && Data[i] < key)
           {
             Data[i+1] = Data[i];
             i = i-1;
             Data[i+1] = key;       
           }
        }
     
     // Proses menghitung Total 5 nilai terbesar
      totalNilai = 0;
      for(b=0; b<5; b++)
        {
         totalNilai += Data[b];      
        }
      printf("%lld\n",totalNilai);  
     }
   
  return 0;        
 }
