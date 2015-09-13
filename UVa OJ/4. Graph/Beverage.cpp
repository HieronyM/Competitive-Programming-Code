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

vstr beve;
int nB,nE;
string temp,temp2;
vi AdjList[205];
int n1,n2;

int dfsNum[105];
vi toposort;

void dfs2(int u)
{
	dfsNum[u] = 1;
	REP(j,AdjList[u].size())
	{
		int node = AdjList[u][j];
		if(dfsNum[node] == 0) dfs2(node);
	}
	
	toposort.pb(u);
}

int main()
{
	int counter = 1;
	while(scanf("%d",&nB) == 1)
	{
		RESET(dfsNum,0);		// Set as Unprocessed
		REP(a,nB)
		{
			temp = GetString();
			beve.pb(temp);
		}
		
		sI(nE);
		REP(a,nE)
		{
			temp = GetString();
			n1 = find(beve.begin(), beve.end(), temp) - beve.begin();
  			//printf("n1 : %d\n",n1);
  			
  			temp2 = GetString();
			n2 = find(beve.begin(), beve.end(), temp2) - beve.begin();		
			//printf("n2 : %d\n",n2);
			
			// Masukkan
			AdjList[n1].pb(n2);	
		}
		
		// Processing
		REP(b,nB)
		{
			if(dfsNum[b] == 0) dfs2(b);
		}
		
		reverse(ALL(toposort));
		
		printf("Case #%d: Dilbert should drink beverages in this order:",counter);
		REP(b,toposort.size())
		{
			printf(" %s",beve[toposort[b]].c_str());
		}
		printf(".\n\n");
		
		counter++;
	}
	
	return 0;
}
