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

int visited[2505];
vi adjList[2505];

void BFS(int s)
{
	int dayMax = 0, MaxBoom = 0;
	queue<int> Q;
	Q.push(s);
	visited[s] = 1;
	int layer = 0;
	
	int couMax;
	while(!Q.empty())
	{
		layer++;
		couMax = 0;
		//printf("HABIS\n");
		int size = Q.size();
		for(int j = 0; j < size; j++)
		{
			int u = Q.front();
			Q.pop();
			//printf("u : %d\n",u);
			for(int k = 0; k < adjList[u].size(); k++ )
			{
				int neigh = adjList[u][k];
				if(visited[neigh] == 0)
				{
					couMax++;
					visited[neigh] = 1;	
					Q.push(neigh);
				} 
			}
		}
		
		//printf("MaxBoom : %d\n",MaxBoom);
		//printf("couMax : %d\n",couMax);
		if(MaxBoom < couMax)
		{
			MaxBoom = couMax;
			dayMax = layer;
		}
	}
	
	if(!MaxBoom) printf("0\n");
	else  printf("%d %d\n",MaxBoom,dayMax);
}

int main()
{
	int n;
	sI(n);
	REP(a,n)
	{
		int nfriend;
		sI(nfriend);
		REP(b,nfriend)
		{
			int node;
			sI(node);
			adjList[a].pb(node);
		}
	}
	
	// Debugging (Cek Data)
	/*
	REP(a,n)
	{
		printf("Data[%d] : { ",a);
		REP(b,adjList[a].size())
		{
		   printf(" %d,",adjList[a][b]);
		}
		printf(" }\n");
	}
	*/
	
	int nQuery;
	sI(nQuery);
	REP(a,nQuery)
	{
		int source;
		sI(source);
		RESET(visited,0);
		
		BFS(source);
	}
	
	return 0;
}
