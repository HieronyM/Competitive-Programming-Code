#include<cstdio>

long long int nilai;
int temp;
int main()
 {
 	while(1)
 	{
 		scanf("%lld",&nilai);
 		if(!nilai) break;
 		
 		 temp = nilai % 9;
         if( temp == 0 ) temp = 9;
 		
 		printf("%d\n",temp);
 	}
 
 	return 0;	
 }
