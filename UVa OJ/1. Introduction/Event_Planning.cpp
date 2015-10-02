#include<cstdio>
#include<algorithm>

using namespace std;
int N,B,H,W;
int Data[18][18],price[18];

int main()
 {
 	int a,b,min,status;
 	while(scanf("%d %d %d %d",&N,&B,&H,&W) != EOF)
 	{
 		min = 500001;
 		status = 0;
 		// Proses Penampungan
 		for(a = 0; a < H; a++)
 		{
 			scanf("%d",&price[a]);
 			for(b = 0; b < W; b++)
 			{
 				scanf("%d",&Data[a][b]);
 			}
 		}
 		
 		// Proses Pemrosesan
 		for(a = 0; a < H; a++)
 		{
 			for(b = 0; b < W; b++)
 			{
 				if(B >= price[a] * N && Data[a][b] >= N)
 				{
 					status = 1;
 					if(min > price[a] * N) 
					 {
					   min = price[a] * N;	
					 }
 				}
 			}
 		}
 		
 		if(status) printf("%d\n",min);
 		else printf("stay home\n");
 	}
 	
 	return 0;
 }
