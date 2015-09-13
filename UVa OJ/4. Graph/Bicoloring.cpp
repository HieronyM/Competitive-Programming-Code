/* ----- Bipartite Graph Check Using Adjacency List (Unweighted) ---

	Step
	1. Initialisasi warna awal semua node, misal 0.		// for (i =0 -> i < n) nodeColor[i] = 0;
	2. Set warna node awal misal 1.   					// nodeColor[root] = 1;
	3. Untuk setiap child dari node berikan warna yang berbeda dari warna node itu.
	    Ada 2 kondisi
	     - Jika warna yang akan diberikan sama dengan warna yang dipunyainya tidak sama maka
	        itu TIDAK BIPARTITE
	     - Jika warnanya sama, cari sampai ke pencarian selanjutnya.
*/

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

#define REP(a,n) for(int (a) = 0; (a) < n; a++)
#define pb push_back

int v,e;
vector <int> adjList[100007];

bool isBipartite()
{
	queue<int> q;
	q.push(0);
	map<int,int> dist;				// Check has been Processed or not
	dist[0] = 0;
	bool isBipartite = true;
	
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		REP(j,adjList[u].size())
		{
			int v = adjList[u][j];
			if(!dist.count(v))         // Not Processed Yet
			{
				dist[v] = 1 - dist[u];			// Just record 2 colors
				q.push(v);
			}
			
			else if(dist[v] == dist[u])
			{
				return false;
			}
		}
	}
	
	return true;
}

int main()
 {
 	int a,b,n1,n2;

 	while(1)
 	{
 		scanf("%d",&v);
 		if(!v) break;
 	
 		scanf("%d",&e);
 		
 		REP(a,e)
 		{
 			scanf("%d %d",&n1,&n2);
 			
 			// Masukan Adjacency list nya
			adjList[n1].pb(n2);
 			adjList[n2].pb(n1);
 		}
 		
 		bool status = isBipartite();
 		
 		if(!status) printf("NOT BICOLORABLE.\n");
 		else printf("BICOLORABLE.\n");
 		
 		// Refresher
 		REP(a,v)
 		{
 			adjList[a].clear();
 		}
 	}
 }
