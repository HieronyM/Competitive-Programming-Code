#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long ll;
ll Data[10000];


int main()
 {
 	int count = 1,j; 
 	ll temp;
 	while(scanf("%lld",&Data[count-1]) != EOF)
 	{
 		/* //Debugging
 		printf("Count : %d\n",count);
		 for(j = 0; j < count; j++)
 		{
 			printf("----%d---\n",Data[j]);
 		}
 		*/
 		
		 sort(Data, Data + count);
 		if(count == 1)
 		{
 			printf("%lld\n",Data[0]);
 		}
 		
 		else if(count % 2 == 0)
 		{
 			temp = Data[count/2] + Data[(count/2) - 1];
 			printf("%lld\n",temp / 2);
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
