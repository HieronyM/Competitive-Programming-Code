#include<stdio.h>

typedef long long ll;
ll Data[10000];
int count = 1; 

int main()
 {
 	while(scanf("%lld",&Data[count]) != EOF)
 	{
 		sort(Data, Data + count);
 		if(count == 1)
 		{
 			printf("%lld\n",Data[count]);
 		}
 		
 		else if(count % 2 == 0)
 		{
 			printf("%lld\n",Data[count/2] + Data[(count/2) -1]);
 		}
 		else
 		{
 			printf("%lld\n",Data[count/2]);
 		}
 		
 		count++;
 	}
 	int a;
 	
 	return 0;
 }
