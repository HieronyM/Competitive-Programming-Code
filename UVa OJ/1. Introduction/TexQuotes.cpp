#include<cstdio>

int main()
 {
 	char input;
 	int status = 0;
 	while(scanf("%c",&input) != EOF)
 	{
 			if(input == '"' && status == 0)
 			{
 				printf("``");
 				status = 1;
 			}
 			
			 else if(input == '"' && status == 1)
 			{
 				printf("''");
 				status = 0;
 			}
 			
 			else
 			{
 				printf("%c",input);
 			}
 	}
 	
 	return 0;
 }
