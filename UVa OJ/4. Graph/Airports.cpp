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
	int TC;
	sI(TC);
	
	int n,m,c;
	REP(a,TC)
	{
		scanf("%d %d %d")
	}
	
	return 0;
}
