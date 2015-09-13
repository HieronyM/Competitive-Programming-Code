#include<stdio.h>

int main()
 {
 	int TC;
 	long long nilai;
 	scanf("%d",&TC);
 	
 	int a;
 	for(a = 0; a < TC; a++)
 	{
 		scanf("%lld",&nilai);
 		if(nilai % 6 == 0) printf("TIDAK\n");
 		else  printf("YA\n");
 	} 
 	
 	return 0;
 }
