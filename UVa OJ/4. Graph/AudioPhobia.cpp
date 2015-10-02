#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <limits.h>
#include <cstring>

using namespace std;

typedef long long ll;
typedef pair <int,int> pii;
#define REP(a,n) for(int (a) = 0; (a) < n; a++) 
#define pb push_back
#define mp make_pair
#define ALL(var) var.begin(),var.end()
#define sI(n) scanf("%d",&n);
#define RESET(arr,val) memset(arr,val, sizeof(arr))
#define INF 1000000000

int n,m,q;
int d[105][105];

void FW()   // Floyd Warshall
{
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
			{		
				d[i][j] = min(d[i][j], max(d[i][k],d[k][j]) );
				//printf("d[%d][%d] : %d\n",i,j,d[i][j]);		
			}
}

int main()
 { 	
 	int counter = 0;
 	while(1)
 	{
 		int u,v,w;
 		scanf("%d %d %d",&n,&m,&q);
 		
 		if(!n && !m && !q) break;
 		
 		// Set to 1 B, if there is no exists edge
		for(int b = 1; b <=n; b++)
			for(int c = 1; c <=n; c++)
				d[b][c] = 1000000000;
 		
		// Input Edge
		REP(a,m)
 		{
 			scanf("%d %d %d",&u,&v,&w);
 			d[u][v] = w;
 			d[v][u] = w;
  		}	
 	
		FW();
		
		if(counter) printf("\n");
		printf("Case #%d\n",counter+1);
		
		// Query
		REP(a,q)
		{
			int s,t;
			scanf("%d %d",&s,&t);
			
			if(d[s][t] == 1000000000) printf("no path\n");
			else printf("%d\n",d[s][t]);
		}
		counter++;
	}
		 	
 	return 0;
 }

