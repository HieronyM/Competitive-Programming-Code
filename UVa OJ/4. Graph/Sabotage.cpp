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

int N,M;
int s = 1, t = 2;			// Set in Problem
int cap[55][55];
vi adjList[505];
vi sComp,tComp;
int visited[55];
int f,mf;
vi p;					// Stores the parent, find path s-> t

void addFlow(int n1, int n2, int w)
{
	cap[n1][n2] += w;
	cap[n2][n1] += w;
	
	adjList[n1].pb(n2);
	adjList[n2].pb(n1);
}
// CP's Library
void augment(int v,int minEdge)			// Traverse spanning tree from s -> t
{
	if(v==s) 
	{
		f = minEdge; 
		return; 
	}
	
	else if(p[v] != -1)
	{
		augment(p[v], min(minEdge, cap[p[v]][v]));
		
		cap[p[v]][v] -= f;
		cap[v][p[v]] += f;
	} 
}

void maxFlow()
 {
 	//mf = 0;
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
 	
 	//return mf;
 }

// Find S-Component and T-Component
void traverse(int u)
{
	//printf("u : %d\n",u);
	visited[u] = 1;
	sComp.pb(u);
	for(int j = 0; j < adjList[u].size();j++)
	{
		int nodex = adjList[u][j];
		
		//printf("cap[%d][%d] : %d   visited[%d] : %d\n",u,nodex,cap[u][nodex],nodex,visited[nodex]);
		if(cap[u][nodex] > 0 && visited[nodex] == 0)
		{
			traverse(nodex);
		}
	}	
}

void minCut()
{
	REP(a,sComp.size())
	{
		int vertex = sComp[a];
		REP(b,adjList[vertex].size())
		{
			int vertex2 = adjList[vertex][b]; 	
			if(visited[vertex2] == 0) printf("%d %d\n",vertex,vertex2);
		}
	}
}

int main()
{
	while(1)
	{
		RESET(cap,0);
		sID(N,M);
		if(!N && !M) break;
		
		REP(a,M)
		{
			int n1,n2,w;
			scanf("%d %d %d",&n1,&n2,&w);		
			addFlow(n1,n2,w);
		}
		
		maxFlow();
		
		RESET(visited,0);	//	 Set as Unvisited
		traverse(s);
		
		for(int j = 0; j < N; j++)
		{
			if(visited[j] == 0) tComp.pb(j); 
		}
		
		/* 
		 //Debugging
		// Printf sComp
		REP(a,sComp.size()) printf("%d ",sComp[a]);	
		printf("\n");
		
		// Printf tComp
		REP(a,tComp.size()) printf("%d ",tComp[a]);
		printf("\n");
		*/
		
		minCut();
		printf("\n");
		
		// Clear
		sComp.clear();
		tComp.clear();
		
		REP(v,505) adjList[v].clear();
	}
	
	return 0;
}
