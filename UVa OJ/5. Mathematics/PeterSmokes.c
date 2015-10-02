#include<stdio.h>

int n,k;
long total,abu,temp;

int main()
 {
 	while(scanf("%d %d",&n,&k) != EOF)
 	{
 		total = n;
 		abu = n;
 		while(abu >= k)
 		{
 			total = total + (abu / k);
 			temp = (abu / k);
			 abu %= k;
 			abu = abu + temp;
 		}
 		printf("%ld\n",total);
 	}
 	
 	return 0;
 }
