#include<cstdio>

int n, input, counter,TC,counter2;
int main()
 {
 	TC=1;
 	while(1)
 	{
 		counter = counter2 = 0;
 		scanf("%d",&n);
 		if(!n) break;
 		else
 		{
 			while(n--)
 			{
 				scanf("%d",&input);
 				if(!input) counter++;
 				else counter2++;
 			}
 			
 			printf("Case %d: %d\n",TC,counter2-counter);
 			TC++;
 		}
 	}
 }
