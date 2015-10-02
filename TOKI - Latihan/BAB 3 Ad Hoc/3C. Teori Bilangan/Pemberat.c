        /*
          Program     :  Pemberat (Latihan 3C TOKI)
          Programmer  :  Hierony Manurung
          Start Date  :  6 November 2013, 10:04
          Finish Date :  -
        */

#include<stdio.h>
int main()
  {
   long long B,K;
   scanf("%lld %lld",&B,&K);
   
   long long bedaBerat = K-B;
   long long pangkatPemberat;
   //printf("%d %d %d",B,K,bedaBerat);
   
   while(bedaBerat != 0)
     {
       pangkatPemberat = 1;
       while(pangkatPemberat <= bedaBerat)
       {
        pangkatPemberat = pangkatPemberat * 2;                     
       }
       pangkatPemberat = pangkatPemberat/2;
       bedaBerat = bedaBerat - pangkatPemberat;
       printf("%lld\n",pangkatPemberat);
                     
     }
   return 0;       
  }
