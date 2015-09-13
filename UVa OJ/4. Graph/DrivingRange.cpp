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
#define sID(n,m) scanf("%d %d",&n,&m);
#define RESET(arr,val) memset(arr,val, sizeof(arr))

int n,m;
vector < pair<int, pii> > EdgeList;
vector <int> pSet;		// To store the Set Parent

/// -------- Union Find Disjoint Method -------//
void initSet(int n)
{	
	int j;
	pSet.assign(n,0);
	for(j = 0; j <n; j++) pSet[j] = j;		
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
	while(1)
	{
		sID(n,m);
		if(!n && !m) break;
		
		int v1,v2,w;
		vector < pair <int , pii> > mst;
		pii temp;
		
		REP(a,m)
		{
			scanf("%d %d %d",&v1,&v2,&w);
			temp = mp(v1,v2);
			
			mst.pb(mp (w, temp));
		}
		
		sort(ALL(mst));
		
		// 	Debugging
		/*REP(a,m)
		{
			printf("mst[%d] : %d, (%d,%d)\n",a,mst[a].first,mst[a].second.first,mst[a].second.second);
		}
		*/
		
		initSet(n);					// Buat parent setiap node masih dirinya sendiri
		
		int wLastEdge;
		int status = 0;
		REP(a,mst.size())
		{
			pii temp2 = mst[a].second;
			
			//printf("FS1 : %d  FS2 : %d\n",findSet(temp2.first),findSet(temp2.second));
			if(!isSameSet(temp.first,temp.second))
			{
				//printf("masuk[%d]\n",a);
				unionSet(temp2.first,temp2.second);
				wLastEdge = mst[a].first;
			}
		}
		
		int cou = 0;
		REP(a,n)
		{
			if(pSet[a] ==  a) cou++;
			
			if(cou >= 2) status = 1;
		}
		if(status) printf("IMPOSSIBLE\n");
		else   printf("%d\n",wLastEdge);	
	}
	
	return 0;
}
