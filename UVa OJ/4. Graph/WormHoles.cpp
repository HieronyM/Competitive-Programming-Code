// Ideafuse Mikroskill
// Template by Hierony

#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <iostream>

#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <limits.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<pii,pii> ppi;
typedef pair<LL,LL> pll;
typedef pair<string,string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<LL> vl;
typedef vector<vl> vvl;
typedef vector<string> vstr;
typedef vector<char> vc;

double PI = acos(-1);

#define REP(i,n) for(int (i) = 0; (i) < (int)(n); (i)++)
#define READ_int(data) scanf("%d",&data); 
#define RESET(c,v) memset(c, v, sizeof(c))
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define pb push_back
#define mp make_pair
#define ALL(vec) vec.begin(),vec.end()
#define sI(val) scanf("%d",&val)
#define sID(val,val2) scanf("%d %d",&val,&val2)
#define INF 2123123123


inline string IntToString(int a){
    char x[100];
    sprintf(x,"%d",a); string s = x;
    return s;
}

inline int StringToInt(string a){
    char x[100]; int res;
    strcpy(x,a.c_str()); sscanf(x,"%d",&res);
    return res;
}

inline string GetString(void){
	char x[1000005];
	scanf("%s",x); string s = x;
	return s;
}

int n,m;
vii AdjList[2005];
vi dist;

void BellmannFord()
{
	dist.assign(n,INT_MAX);
	dist[0] = 0;
	
	for(int i = 0; i < n-1; i++)		// Relax all Edges V-1 Times
	{
		for(int u = 0; u < n; u++)
		{
			for(int j = 0; j < AdjList[u].size(); j++)
			{
				pii v = AdjList[u][j];
				dist[v.first] = min(dist[v.first], (dist[u] + v.second) ); 
			}
		}
	}
}

void hasNegativeCycle()
{
	bool hNC = false;
	for(int u = 0; u < n; u++)
	{
		for(int j = 0; j < AdjList[u].size(); j++)
		{
			pii v = AdjList[u][j];
			if(dist[v.first] > dist[u] + v.second)
			{
				hNC = true;
			}
		}
	}
	
	printf("%s\n",hNC ? "possible" : "not possible");
}

int main()
{
	int TC;
	sI(TC);
	
	REP(a,TC)
	{
		scanf("%d %d",&n,&m);
		
		int n1,n2,w;
		
		// insert data to AdjList
		REP(b,m)
		{
			scanf("%d %d %d",&n1,&n2,&w);
			AdjList[n1].pb(mp(n2,w));
		}
		
		// Processing
		BellmannFord();
		hasNegativeCycle();
		
		// Clear
		dist.clear();
		REP(b,n) AdjList[b].clear();
	}
	
}
