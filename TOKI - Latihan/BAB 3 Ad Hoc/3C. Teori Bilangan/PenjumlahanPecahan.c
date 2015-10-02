        /*
          Program     :  Penjumlahan Pecahan (Latihan 3C TOKI)
          Programmer  :  Hierony Manurung
          Start Date  :  7 November 2013, 18:00
          Finish Date :  
        */
#include<stdio.h>
int main()
 {
 unsigned long long int A,B,C,D;
  scanf("%lld %lld %lld %lld",&A,&B,&C,&D);
  
 unsigned long long int penyebut = B * D;
 unsigned long long int pembilang = ((penyebut/B)*A) + ((penyebut/D)*C);
  
 unsigned long long int temp1 = pembilang,temp2 = penyebut;
 unsigned long long int R,temp;
  /*if(penyebut > pembilang )                        //  Tukar nilai B ke A jika nilai B lebih besar dari A
    {
       temp = penyebut;                      
       penyebut = pembilang;
       pembilang = temp;  
    }
*/

   // printf("\n");
    while(penyebut != 0)
    {
   //    printf("%ld = %ld x %ld + %ld \t\t gcd(%ld,%ld)\n",pembilang,pembilang/penyebut,penyebut,pembilang%penyebut,penyebut,pembilang%penyebut);
       R = pembilang % penyebut;
       pembilang = penyebut;
       penyebut = R;     
    }
 unsigned long long int GCD = pembilang; 
 // printf("\n Maka GCD = %ld",pembilang);
  
  printf("%lld %lld\n",temp1/GCD,temp2/GCD);      
  return 0;
 }
