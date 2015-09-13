// Program     : While + Counter
// Programmer  : Hierony Manurung
// Begin       : 6 June 2013, 15:26
// Finish      : 6 June 2013, 15:54

#include<stdio.h>
int main()
{
 int  jumlah=0,bil;
 while(scanf("%d",&bil)!=EOF)
     {
      jumlah = jumlah + bil;            
     }
     
 printf("%d\n",jumlah);
 return 0;   
}
