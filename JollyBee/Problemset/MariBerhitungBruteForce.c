#include<stdio.h>

int main()
  {
   int TC;
   scanf("%d",&TC);
   
   int p,status;
   unsigned long long int A,B,N,M;
   unsigned long long int Total,cekNilai,subTotal;
   for(p=1; p<=TC; p++)
     {
      Total = 0;
      scanf("%lld %lld %lld %lld",&A,&B,&N,&M);
      cekNilai = A;
      status = 0;
      
      while(status == 0)
      {
        printf("Cek Nilai : %lld\n",cekNilai);
        printf("Total : %lld\n",Total);
        if(cekNilai > B)
          {
           status = 1;         
          }              
       if(cekNilai / N > 0)
         {
            subTotal = (cekNilai/N) * N;
            Total += subTotal;      
         }
       
       cekNilai = cekNilai + A;              
      }
      printf("%lld\n",Total);
   }
 getch();
 return 0;   
}
