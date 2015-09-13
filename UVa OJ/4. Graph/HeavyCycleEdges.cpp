/* Description
	Program ini adalah program untuk mencari 'Minimum Spanning Tree' (Graph dimana semua nodenya sudah terhubung dengan
	jumlah weight dari edge yang seminimal mungkin ) pada graph yang connected, weighted, dan undirected. Menggunakan
	Union - Find Disjoint untuk mengetahui bahwa node itu berada dalam set yang sama atau tidak, jika node itu tidak 
	satu set, maka edge yang menghubungkan node tersebut bisa dimasukkan ke dalam MST.
	
	STEP() :
	1. Masukkan datanya kedalam EdgeList.          //  vector <int, pair <int,int> > w,u,v;
	2. Sort data di edgenya.
	3. Mulai dari edge paling kecil, lihat apakah node yang dihubungkan itu satu set.
	4. Tambahkan weight dari edge yang tidak bermasalah itu.
*/

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <limits.h>

using namespace std;

typedef long long ll;
typedef pair <int,int> pii;
#define REP(a,n) for(int (a) = 0; (a) < n; a++) 
#define pb push_back
#define mp make_pair
#define ALL(var) var.begin(),var.end()

int n,m;
vector < pair<int, pii> > EdgeList;
vector <int> pSet;		// To store the Set Parent

/// -------- Union Find Disjoint Method -------//
void initSet(int n)
{	
	pSet.assign(n,0);
	REP(i,n) pSet[i] = i;		
}

int findSet(int i)
{
	return (pSet[i] == i) ? i : pSet[i] = findSet(pSet[i]);
}

bool isSameSet(int i, int j)
{
	return findSet(i) == findSet(j);
}

void unionSet(int i,int j)
{
	pSet[findSet(i)] = findSet(j);
}

void findST()
 {
 	int maks = 0,stat = 0;
 	initSet(n);
 	
 	REP(i,m)
 	{
 		pair<int,pii> temp = EdgeList[i];
 		maks = max(maks,temp.first);
 		
		if(!isSameSet(temp.second.first, temp.second.second))
 		{
 			unionSet(temp.second.first,temp.second.second);
 		}
 		else
 		{
 			if(!stat) printf("%d",maks);
 			else printf(" %d",maks);
 			stat++;
 		}
 		
 	}
 	
	 if(!stat) printf("forest");
 	
 	printf("\n");	
 }
int main()
 { 	
 	while(1)
 	{
 		int u,v,w;
 		scanf("%d %d",&n,&m);
		if(!n && !m) break;
		REP(a,m)
 		{
 			scanf("%d %d %d",&u,&v,&w);
 			EdgeList.pb(mp(w,pii(u,v)));
 		}	
 		
 		//sort(EdgeList.begin(), EdgeList.end());			// Greedy Strategy Kruskal's Algorithm
 		sort(ALL(EdgeList));
 		
 		/* Debugging EdgeList
		 
		 printf("\n----EdgeList---\nw u v\n");
		 REP(i,EdgeList.size())
 		{
 			pair <int, pii> store = EdgeList[i];
 			printf("%d %d %d\n",store.first,store.second.first,store.second.second);
 		}
 		*/
 		
 		findST();	// Find the spanning tree
 		
 		
		// Refresh
		EdgeList.clear();
	}
		 	
 	return 0;
 }

