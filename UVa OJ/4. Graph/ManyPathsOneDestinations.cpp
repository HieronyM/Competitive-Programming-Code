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
#include <set>
#include <bitset>

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
typedef map <int,int> mii;

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


// FPB gan
int gcd(int  a, int b){
	if(b == 0)return a;
    else return gcd(b,a%b);
}

bitset<10000010> bs;
vi primes;

// Prima pertama terdapat di primes[1] yah :D
void sieve(LL upperbound){
	bs.set();
	bs[0]=bs[1]=0;
	primes.pb(0);
	for(LL i=2; i<=upperbound+1; i++)if(bs[i]){
	for(LL j=i*i; j<= upperbound+1; j+=i)bs[j] = 0;
			primes.pb((int) i);
	}
}

int n;
vi adjList[1005];
int dfs_num[1005];
int num_paths[1005];
vi toposort;

void dfs2(int u)
{
	dfs_num[u] = 1;			// Set as visited
	REP(j,adjList[u].size())
	{
		int v = adjList[u][j];
		if(dfs_num[v] == 0) dfs2(v);
	}
	toposort.pb(u);
}

int main()
{
	int count = 0;
	while(sI(n) == 1)
	{
		RESET(dfs_num,0);
		RESET(num_paths,0);
		REP(a,n)
		{
			int nNeigh;
			sI(nNeigh);
			REP(b,nNeigh)
			{
				int node;
				sI(node);
				adjList[a].pb(node);
			}
		}
		
		// Get toposort
		REP(a,n)
		{
			if(dfs_num[a] == 0) dfs2(a);
		}
		
		// Reverse
		reverse(ALL(toposort));
		
		// Cek Toposort <Debugging>
		/*
		REP(a,toposort.size()) printf("%d ",toposort[a]);
		printf("\n");
		*/
		
		// Hitung Number differents path
		num_paths[0] = 1;
		REP(a,toposort.size())
		{
			int cur = toposort[a];
			REP(b,adjList[cur].size())
			{
				int v = adjList[cur][b];
				num_paths[v] += num_paths[cur];
			}
		}
		
		int total = 0;
		for(int i = toposort.size()-1; i >= 0; i--)
		{
			int ver = toposort[i];
			if(adjList[ver].size() == 0) total += num_paths[ver];
			else
			{
				//printf("toposort[%d] : %d\n",i,toposort[i]);
				break;	
			} 
		}
		
		if(count) printf("\n");
		printf("%d\n",total);
		
		// Clear
		REP(a,1005) adjList[a].clear();
		toposort.clear();
		count++;
	}
	
	return 0;
}
