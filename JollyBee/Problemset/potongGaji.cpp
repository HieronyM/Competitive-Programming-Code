#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

unsigned long long int gajiKar[10000];

int main()
 {
  int TC;
  scanf("%d",&TC);
  
  int nKaryawan,a,b,count;
  
  unsigned long long int gajiMax,totalGaji,gajiStandard;
  for(a=0; a < TC; a++)
    {
     count = 0;
     totalGaji = 0;
     scanf("%d %lld",&nKaryawan, &gajiMax);
     for(b=0; b < nKaryawan; b++)
       {
        scanf("%d",&gajiKar[b]);      
        totalGaji += gajiKar[b];
       }
     sort(gajiKar,gajiKar+nKaryawan);
     
     // Ketika kondisi gaji ga perlu dikurangi
     if(totalGaji <= gajiMax)
     {
      printf("-1\n");            
     }    
     
     // Ketika perlu dilakukan pengurangan gaji
     else
     {
      for(b=0; b < nKaryawan; b++)
       {
        gajiStandard = gajiMax / (nKaryawan-count);
      //printf("Gaji Standard[%d] : %lld\n",b,gajiStandard);
        if(gajiKar[b] <= gajiStandard)
          {
           count++;
           gajiMax -= gajiKar[b];           
          }
       }
       printf("%lld\n",gajiMax/(nKaryawan-count));
      }
    }

//system("pause");
 return 0;
 
}
