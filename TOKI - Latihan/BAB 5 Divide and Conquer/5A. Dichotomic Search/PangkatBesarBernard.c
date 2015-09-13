#include <stdio.h>

typedef long long lld;
lld hasil;

lld pangkat(lld base, lld pang){
	
	if(pang == 1){
		//printf("Masuk 1\n");
		//printf("%d\n",hasil);
		return base % 1000000;
	}
	else{
		if(pang %2 == 0){
			//printf("Masuk 2\n");
			hasil = pangkat(base,pang/2);
			if(hasil < 1000000) hasil %= 100000;
			//printf("%d\n",hasil);
			return (hasil * hasil)% 1000000;
		}
		
		else if (pang % 2){
			//printf("Masuk 3\n");
			hasil = pangkat(base,pang/2);
			if(hasil < 1000000) hasil %= 100000;
			//printf("%d\n",hasil*base);
			return ((hasil * hasil) * base) % 1000000;
		}
	}
	
}
int main(){
	lld A,B;
	lld hasil;
	scanf("%lld %lld",&A,&B);
	hasil = pangkat(A,B);
	printf("%d\n",hasil);
	return 0;
}
