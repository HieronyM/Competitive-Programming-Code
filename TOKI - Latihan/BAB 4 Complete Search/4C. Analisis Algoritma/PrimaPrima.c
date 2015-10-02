#include<stdio.h>
#include <math.h>

typedef long long int ll;
ll totalConcat;

int cekPrima(x)
 {
 	int a;
 	if(x == 1)return 0;
 	else if (x == 2 || x == 3) return 1;
 	else if (x % 2 == 0 || x % 3 == 0 ) return 0;
 	else
 	   {
 	   	for(a = 2*a <= x; a++)
 	   	  {
 	   	  	if(x % a == 0)
 	   	  	  {
 	   	  	  	return 0;
 	   	  	  }
 	   	  }
 	   	   return 1; 
 	   }
 }

int main()
 {
 	int A,B;
 	scanf("%d %d",&A,&B);
 	
 	int j,k,status = 0,pembagi;
 	for(j = A; j <= B; j++)
 	  {
 	  	pembagi = 10;
 	  	if(!cekPrima(j))continue;
		// Kondisi A tidak prima, jangan lanjut ke B
 	  	for(k = A; k <= B; k++)
 	  	  {
 	  	  	// Kondisi A prima B tidak
 	  	    if(!cekPrima(k))continue;
 	  	    
 	  	    // Kondisi A dan B adalah Prima, maka alkukan penggabungan
 	  	    else
 	  	    {
 	  	       while(k % pembagi != k)
				 {
				 	pembagi *= 10;
				 }
				totalConcat = (j * pembagi) + k;
				if(cekPrima(totalConcat))
				{
					status = 1;
					printf("%d %d\n",j,k);
				}
 	  	    }
 	  	  }
 	  }
 	
 	if(!status)printf("TIDAK ADA\n");
 	return 0;
 }
