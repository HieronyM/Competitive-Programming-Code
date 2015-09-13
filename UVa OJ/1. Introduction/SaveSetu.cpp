#include<cstdio>
#include<cstring>

using namespace std;

char kata[10];
int input,TC,total = 0;

int main()
 {
 	scanf("%d",&TC);
 	while(TC--)
 	{
 		scanf("%s",&kata);
 		if(kata[0] == 'd')
 		{
 			scanf("%d",&input);
 			total += input;
 		}
 		
 		else
 		{
 			printf("%d\n",total);
 		}
 	}
 	
 	return 0;
 }
