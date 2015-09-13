#include<stdio.h>

int Data[100];
int a= 0,total,b,status,nSpace;
int pembagi;
int main()
 {
 	printf("PERFECTION OUTPUT\n");
 	while(1)
 	{
 		status = 0;
 		pembagi = 1;
 		nSpace = 0;
 		total = 0;
 		scanf("%d",&Data[a]);
 		if(!Data[a]) break;
 		else
 		{
 		  	for(b = 1; b < Data[a]; b++)
 		  	{
 		  		if(Data[a] % b == 0)
 		  		{
 		  			total += b;
 		  		}
 		  		
 		  		if(total > Data[a]) 
				{
					status = 1;	
				   	break;
				}
 		  	}
		
			while(Data[a] / pembagi > 0)
			{
				nSpace++;
				pembagi*=10;
			}
			  	
			nSpace = 5 - nSpace;
			
			for(b = 1; b <= nSpace; b++)
			{
				printf(" ");
			}
			
			printf("%d  ",Data[a]);
			if(status == 1) printf("ABUNDANT\n");
			else
			{
				if(total < Data[a]) printf("DEFICIENT\n");
				else printf("PERFECT\n");
			}	
 		  	a++;
 		}
 	}
 	
 	printf("END OF OUTPUT\n");
 	return 0;
 }
