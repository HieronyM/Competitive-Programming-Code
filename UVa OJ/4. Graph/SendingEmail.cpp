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

vii AdjList[20005];		//	node relasi, weight
int n,m,s,t;
vi dist;

void dijkstra()
{
	dist.assign(n,INF);
	dist[s] = 0;			// Jarak dari source ke source = 0
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push(mp(0,s));
	
	// Processing
	while(!pq.empty())
	{
		pii temp = pq.top();
		//if(temp.second == t) break;					// Pruning
		//printf("(%d,%d)\n",temp.first,temp.second);
		pq.pop();
		
		int d = temp.first;
		int u = temp.second;
		
		if(d == dist[u])		// Mencegah double Relax
		{
			for(int j = 0; j < (int) AdjList[u].size(); j++)
			{
				pii v = AdjList[u][j];					//	Semua edge yang keluar dari node
				if(dist[u] + v.second < dist[v.first])
				{
					dist[v.first] = dist[u] + v.second;
					pq.push(mp(dist[v.first], v.first));
				}
			}
		}		
	}
}

int main()
{
	int TC;
	sI(TC);
	REP(a,TC)
	{
		scanf("%d %d %d %d",&n,&m,&s,&t);
		REP(b,m)
		{
			int u1,u2,w;
			scanf("%d %d %d",&u1,&u2,&w);
			
			AdjList[u1].pb(mp(u2,w));
			AdjList[u2].pb(mp(u1,w));
		}
		
		// Do dijkstra algorithm
		dijkstra();
		
		if(dist[t] == INF) printf("Case #%d: unreachable\n",a+1);
		else printf("Case #%d: %d\n",a+1,dist[t]);
		
		// Clear
		REP(b,n) AdjList[b].clear();
	}
	
	return 0;
}
