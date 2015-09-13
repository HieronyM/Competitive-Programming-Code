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
int r,c;
vi dist;

void dijkstra()
{
	int s = 0;
	dist.assign((r*c),INF);
	dist[s] = 0;			// Jarak dari source ke source = 0
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push(mp(0,s));			// 
	
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
		scanf("%d %d",&r,&c);
		// Inputan
		int node = 0;
		REP(i,r)
		{
			REP(j,c)
			{
				int w;
				scanf("%d",&w);
				
				int val;
				// Cek Kiri
				if(node - 1 >= 0)
				{
					AdjList[node].pb(mp( (node-1) ,w) );
					AdjList[node-1].pb(mp( (node) ,w) );
				}
				
				// Cek atas
				if(node - c >= 0)
				{
					AdjList[node].pb( mp( (node-c) ,w) );
					AdjList[node-c].pb( mp( (node),w) );
				}
				
				node++;
		 	}
		}
		
		// Cek AdjList
		REP(i,(r*c))
		{
			printf("AdjList[%d] : { ",i);
			REP(j,AdjList[i].size())
			{
				pii temp = AdjList[i][j];
				printf("(%d,%d),",temp.first,temp.second);
			}
			printf("}\n");
		}
		
		// Do dijkstra algorithm
		dijkstra();
		
		//if(dist[t] == INF) printf("Case #%d: unreachable\n",a+1);
		printf("%d\n",dist[(r*c) - 1]);
		
		// Clear
		REP(b,(r*c)) AdjList[b].clear();
	}
	
	return 0;
}
