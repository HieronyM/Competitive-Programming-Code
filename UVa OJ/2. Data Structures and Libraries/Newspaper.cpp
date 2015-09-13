#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>

using namespace std;
int TC,nCost,letterCost,nLines;
int a,b;
char cost[10];

double total;

int main()
 {
 	char command;
 	int i;
 	scanf("%d",&TC);
 	for(a = 0; a < TC; a++)
 	{
 		// Refresher
 		i = 0;
 		total = 0;
 		scanf("%d",&nCost);
 		map<char, int> costDetail;
 		
 		// Tampung Karakter Dari Cost
 		for(b = 0; b < nCost; b++)
 		{
 			//printf("B : %d\n",b);
 			scanf("%s %d",&cost,&letterCost);
			costDetail[cost[0]] = letterCost;	
		}
 		scanf("%d",&nLines);
 		
 		// Tampung Command
 		for(;;)
 		{
		  scanf("%c",&command);
		  total += costDetail[command];
		  if(command == '\n') nLines--;
		  
		  //printf("NLines saat ini : %d\n",nLines);
		  // Kondisi Berakhir
		  if(nLines == -1) break;
		}
		
		//printf("Total sebelum dibagi : %lf\n",total);
		printf("%.2lf$\n",total/100);
		
		// Refresh
 	}
 	return 0;
 }
