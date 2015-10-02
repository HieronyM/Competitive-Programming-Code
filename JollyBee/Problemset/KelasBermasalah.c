#include<stdio.h>

int DataSiswa[10000];
int main()
{
 int TC;    // Number testcase
 scanf("%d",&TC);
 
 float rataRata;
 int total,count;
 int a,nSiswa,b;
 for(a=0; a< TC; a++)
   {
     total = 0;
     count = 0;     
     scanf("%d",&nSiswa);
     for(b=0; b<nSiswa; b++)
        {
         scanf("%d",&DataSiswa[b]);
         total += DataSiswa[b];     
        }
        rataRata = (float)total / nSiswa;
     //printf("%f\n",rataRata);
     for(b=0; b<nSiswa; b++)
        {
          if(DataSiswa[b] < rataRata)
             {
              count++;            
             }     
        }
        printf("%d\n",count);        
   }
 //getch();
 return 0;   
}
