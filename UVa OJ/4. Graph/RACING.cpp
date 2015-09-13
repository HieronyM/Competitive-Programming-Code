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
#define sI(n) scanf("%d",&n)
#define sID(n,m) scanf("%d %d",&n,&m)
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

int main()
{
	int TC;
	sI(TC);
	REP(a,TC)
	{
		sID(n,m);
		vector <pair <int, pii> > edgeList;
		
		int v1,v2,w;
		int sumWeight = 0;
		REP(b,m)
		{
			scanf("%d %d %d ",&v1,&v2,&w);
			sumWeight += w;
			
			pii tempPair = mp(v1,v2);
			edgeList.pb(mp (w, tempPair) );
		}
		
		// Dummy
		/*int temp;
		scanf("%d",&temp);
		*/
		////////
		
		sort(ALL(edgeList));
		initSet(n);
		
		// Debugging <Correct>
		/*for(int i = edgeList.size() -1; i >= 0; i--)
		{
			printf("edgeList[%d] : (%d, (%d,%d) )\n",i,edgeList[i].first,edgeList[i].second.first,edgeList[i].second.second);
		}
		*/
		
		int MaxST = 0;
		for(int i = edgeList.size() -1; i >= 0; i--)
		{
			//printf("masuk\n");
			pii temp2 = edgeList[i].second;
			//printf("edgelist[%d].first : %d edgelist[%d].second : %d",i,edgeList[i].second.first,i,edgeList[i].second.second);
			if(!isSameSet(temp2.first, temp2.second))
			{
				//printf("masuk2\n");
				unionSet(temp2.first, temp2.second);
				MaxST += edgeList[i].first;
			}
		}
		
		printf("%d\n",sumWeight-MaxST);
	}
	
	return 0;
}
