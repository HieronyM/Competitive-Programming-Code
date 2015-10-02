#include<stdio.h>
#include<string.h>
typedef long long ll;
ll hasil;
int modulus = 1000000;

ll PangkatBesar(int base, int pangkat)
 {
 	if(pangkat == 1) return base;
 	
	else
	{
		if(pangkat % 2 == 0)
		{
		  hasil = PangkatBesar(base,pangkat/2);
		  return (hasil % modulus) * (hasil % modulus) % modulus;	
		}
		else if(pangkat % 2)
		{
			 hasil = PangkatBesar(base,pangkat/2);
		  	return (hasil % modulus) * (hasil % modulus) * (base % modulus) % 1000000; 
		}
	}
	  
 }

int main()
 {
 	ll A,B,temp;
 	scanf("%lld %lld",&A,&B);	
 	//printf("%lld\n",PangkatBesar(A,B));
 	temp = PangkatBesar(A,B);
    
    if(temp == 0) printf("000000");
    
	else if(temp <= 999999)
	{
		printf("%lld\n",temp);
	}
	
	
	return 0;
 }
