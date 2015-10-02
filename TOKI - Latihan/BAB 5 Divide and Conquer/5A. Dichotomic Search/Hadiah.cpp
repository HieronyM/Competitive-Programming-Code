#include <cstdio>

typedef unsigned long long int ULL;

using namespace std;

ULL A,B,C,N;

ULL kalikan(ULL base, ULL pangkat)
 {
 	ULL res= 1;
 	while(pangkat > 0)
 	{
 		if(pangkat % 2) res = (res * base) % N;
 		base = (base*base) % N;
 		pangkat /= 2;
 	}
 	return res;
 }

int main()
 {	
 	ULL hasil,a;
	scanf("%llu %llu %llu %llu",&A,&B,&C,&N);
 	
 	
 	hasil = A;
 	for(a = 1; a <= C; a++)
 	{
 		hasil = kalikan(hasil,B);
 		hasil %= N;
 	}
 	
 	printf("%llu\n",hasil+1);
 	return 0;
 }
