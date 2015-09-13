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

int N;
int s,t,m;
vi adjList[1000];		// node2, weight
int cap[1000][1000];		// The flow
int mf,f;
vi p;					// Stores the parent, find path s-> t


void addFlow(int n1, int n2, int w)
{
	// Tambahkan flow
	cap[n1][n2] += w;
	cap[n2][n1] += w;
	
	adjList[n1].pb(n2);
	adjList[n2].pb(n1);
	
}

// CP's Library
void augment(int v,int minEdge)			// Traverse spanning tree from s -> t
{
	//printf("masuk4\n");
	if(v==s) 
	{
		//printf("masuk5\n");
		f = minEdge; 
		return; 
	}
	
	else if(p[v] != -1)
	{
		//printf("masuk6\n");
		augment(p[v], min(minEdge, cap[p[v]][v]));
		
		cap[p[v]][v] -= f; cap[v][p[v]] += f;
		
		//printf("1.capacity[%d][%d] : %d\n",p[v],v,cap[p[v]][v]);
		//printf("2.capacity[%d][%d] : %d\n",v,p[v],cap[v][p[v]]);
	} 
}

int maxFlow()
{
	mf = 0;
 	while(1)
 	{
 		queue <int> q;
 		f = 0;
		p.assign((N + 5),-1);
		q.push(s);						// Cari Dari source
 		p[s] = s;
 		
 		while(!q.empty())
 		{
 			int u = q.front();
 			//printf("u : %d\n",u);
			q.pop();
 			if(u == t) break;	// Setelah dapat sink, break
 			
 			REP(v,adjList[u].size())
 			{
 				int node = adjList[u][v];
				  
				 //printf("\tcapacity[%d][%d] : %d\n",u,node,capacity[u][node]); 
 				if(cap[u][node] > 0 && p[node] == -1)
 				{
 					//printf("\tMasuk : %d\n",node);
 					q.push(node);
 					p[node] = u;
 				}
 			}
 		}
 		
 		augment(t,INF);   // Cari lagi minimum edge weight
 		if(f == 0) break;
 		mf += f;
 		//printf("mf saat ini : %d\n",mf);
 	}
 	
 	return mf;
}

int main()
{
	int counter = 1;
	while(1)
	{
		RESET(cap,0);
		sI(N);
		if(!N) break;
		
		scanf("%d %d %d",&s,&t,&m);
		
		REP(a,m)
		{
			int n1,n2,w;
			scanf("%d %d %d",&n1,&n2,&w);
			
			addFlow(n1,n2,w);
		}
		
		printf("Network %d\n",counter);
 		printf("The bandwidth is %d.\n\n",maxFlow());
 		
 		counter++;
 		
 		// Refresh
 		REP(a,110) adjList[a].clear();
	}
	
	return 0;
}
