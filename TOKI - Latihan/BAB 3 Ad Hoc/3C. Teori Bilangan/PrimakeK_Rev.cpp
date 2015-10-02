        /*
          Program     :  Kelipatan 4 atau 7 (Latihan 3C TOKI)
          Programmer  :  Hierony Manurung
          Start Date  :  4 November 2013, 17:53
          Finish Date :  -
        */

#include <cstdio>
#include <iostream>
#include <algorithm>
 
using namespace std;

bool isPrime (int n)
 {
   int faktor = 0;
   if (n == 1) 
   {
     return false;
   }
   
   for (int i = 2; i*i <= n; i++)
   {
    if ((n % i) == 0) 
    {  
       return false;
    }
   }
   
   return true;
}

int prime[7777];

int main()
 {
  
  int T;
  scanf("%d",&T);
  
  int data[T],a;
  for(a=0; a<T; a++)
    {
     scanf("%d",&data[a]);    
    }
    
  int nPrime = 1;
  prime[1] = 2; 
  int i = 3;
  //for (int i = 1; i <= n; i++){
	while(nPrime != 1000)
	{
        if (isPrime(i)) 
        {
		 nPrime++;
		 prime[nPrime] = i;
	    }
	    i = i + 2;
    }


 /* Menampilkan nilai Primanya */
 for(a=0; a<T; a++)
    {
      printf("%d\n",prime[data[a]]);
    }

  return 0;        
}
