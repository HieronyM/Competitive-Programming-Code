#include<cstdio>

char input[8];
int counter;
int main()
 {
 	counter = 1;
 	while(1)
 	{
 		scanf("%s",&input);
 		if(input[0] == '*') break;
 		else if(input[0] == 'H') printf("Case %d: Hajj-e-Akbar\n",counter);
 		else printf("Case %d: Hajj-e-Asghar\n",counter);
 		
 		counter++;
 	}
 	return 0;
 }
