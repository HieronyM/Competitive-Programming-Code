#include<cstdio>
#include<iostream>
using namespace std;

char denah[105][105];				
int n,m;							// nRow dan nColumn di denahnya							
int a;							
int counter;						// Counter Mine di suatu titik
int i,j,k,nDenah=0;
int idX[8] = {-1,1,0,0,-1,-1,1,1};
int idY[8] = {0,0,-1,1,-1,1,-1,1};
int p;


// Hitung Mine di suatu titik
void countMine(int x,int y)
{
	counter = 0;
		/*if(denah[x-1][y] == '*') 	counter++;			// Atas
		if(denah[x+1][y] == '*') 	counter++;			// Bawah		
		if(denah[x][y-1] == '*') 	counter++;			// Kiri
		if(denah[x][y+1] == '*') 	counter++;			// Kanan
		if(denah[x-1][y-1] == '*') 	counter++;			// Diagonal Kiri Atas
		if(denah[x-1][y+1] == '*') 	counter++;			// Diagonal Kiri Bawah
		if(denah[x+1][y-1] == '*') 	counter++;			// Diagonal Kanan Atas
		if(denah[x+1][y+1] == '*') 	counter++;			// Diagonal Kanan bawah
	// Well Tested
	//printf("\tCounter : %d \t idX = %d \t idY = %d\n",counter,x,y);
	//return counter;
	*/
	
	for(p = 0; p < 8; p++)
	 {
	 	if(denah[x+idX[p]] [y + idY[p]] == '*') ++counter;
	 }
	denah[x][y] = (char)(((int)'0')+counter);
}

int main()
 {
 	while(1)
 	{
 		nDenah++;
 		scanf("%d %d",&n,&m);
 		if(!n && !m) break;
 		
		 else
 		{
 			for(a =0; a < n; a++)
 			{
 				scanf("%s",&denah[a]);
		 	} 
 			 
 			for(j = 0; j < n; j++)
 			{
 				for(k = 0; k < m; k++)
 				{
 					if(denah[j][k] == '*')
					 {
					 	//printf("Yang di-continue, IdX = %d, idY = %d\n",j,k);
					 	continue;
					 } 	 
 					else
 					{
 						countMine(j,k);
 						//printf("\tCounter : %d \t idX = %d \t idY = %d\n",counter,j,k);
 					}
 				}
 			}
 		}
 		
 		if(nDenah == 1) printf("Field #%d:\n",nDenah);
 		else printf("\nField #%d:\n",nDenah);
 		
		 for(j =0; j < n; j++) printf("%s\n",denah[j]);
		 
		 for(j =0; j < n; j++)
		 {
		 	for(k = 0; k < m; k++)
		 	{
		 		denah[j][k] = '.';
		 	}
		 }
 	}
 	return 0;
 }
