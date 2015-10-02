#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

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
    sort(Data,Data+nData);
     
     // Proses menghitung Total 5 nilai terbesar
      totalNilai = 0;
      for(b=nData-1; b >= nData-5; b--)
        {
         totalNilai += Data[b];      
        }
      printf("%lld\n",totalNilai);  
     }
   
  return 0;        
 }
