#include<cstdio>
#include<algorithm>
#include<string.h>

using namespace std;

int main()
 {
 	while(1)
 	{
 		char kata[55];
 		scanf("%s",&kata);
 		int n = strlen(kata);
 		if(kata[0] == '#') break;
 		else
 		{
 			if(next_permutation(kata,kata+n))
 			{
 				printf("%s\n",kata);
 			}
 			
 			else printf("No Successor\n");
 		}
 	}
 	
 	return 0;
 }
