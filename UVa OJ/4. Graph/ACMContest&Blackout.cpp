/* Description
	Program ini adalah program untuk mencari 'Second best Spanning Tree' pada graph yang connected, weighted, dan undirected. Menggunakan
	Union - Find Disjoint untuk mengetahui bahwa node itu berada dalam set yang sama atau tidak, jika node itu tidak 
	satu set, maka edge yang menghubungkan node tersebut bisa dimasukkan ke dalam MST.
	
	STEP() :
	1. Masukkan datanya kedalam EdgeList.          //  vector <int, pair <int,int> > w,u,v;
	2. Sort data di edgenya.
	3. Generate MST nya.
	4. untuk setiap edge yang berada di MST, disable satu persatu lalu tambahi yang lain..
*/

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

int n,m;
vector < pair<int, pii> > EdgeList;
vector <int> pSet;		// To store the Set Parent
vector <int> flagEdge;

/// -------- Union Find Disjoint Method -------//
void initSet(int n)
{	
	int j;
	pSet.assign(n+1,0);
	for(j = 1; j <=n; j++) pSet[j] = j;		
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

int findMST()
 {
 	int mstLength = 0;
 	initSet(n);
 	
 	REP(i,m)
 	{
 		pair<int,pii> temp = EdgeList[i];
 		
		if(!isSameSet(temp.second.first, temp.second.second))
 		{
 			unionSet(temp.second.first,temp.second.second);
 			mstLength += temp.first;			// Set Edge yang dipakai
 			flagEdge.pb(i);
			//printf("temp.first : %d, i : %d\n",temp.first,i);
		}
 	}
 	
	 return mstLength;	
 }
 
pii findMST2(int flagged)
 {
 	int mstLength = 0;
 	int counter = 0;
 	initSet(n);
 	
 	REP(i,m)
 	{
 		pair<int,pii> temp = EdgeList[i];
 		
		if(!isSameSet(temp.second.first, temp.second.second) && i != flagged)
 		{
 			unionSet(temp.second.first,temp.second.second);
 			mstLength += temp.first;			// Set Edge yang dipaka
			//printf("temp.first : %d, i : %d\n",temp.first,i);
			counter++;
		}
 	}
 	
 	 pii temp = make_pair(counter,mstLength);
	 return temp;	
 }
  
int findSBST()
 {
 	//printf("masuk printf fE size : %d\n ",flagEdge.size());
 	int minx = INT_MAX;
 	pii tempMin;
 	//printf("\n\n");
	REP(j,flagEdge.size())
	 {
	 	//printf("flagEdge[%d] : %d\n",j,flagEdge[j]);
		tempMin = findMST2(flagEdge[j]);
		
		if(tempMin.first == n-1) minx = min(minx,tempMin.second);
		//printf("minx : %d\n",minx);
	 }	
	
	return minx; 
 }
 
int main()
 { 	
 	int TC;
 	sI(TC);
 	
 	while(TC--)
 	{
 		int u,v,w;
 		scanf("%d %d",&n,&m);
 		
 		// Input Edge
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
 		
 		printf("%d",findMST());	// Find the minimum spanning tree  
 		printf(" %d\n",findSBST()); // Find the second best spanning tree
 		
		// Refresh
		EdgeList.clear();
		flagEdge.clear();
	}
		 	
 	return 0;
 }

