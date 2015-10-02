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
vi AdjList[100005];

void bipartite()
{
	int j;
	int nodeColor[n + 5];
	
	// Set semua dengan -1 (Unprocess Yet)
	REP(j,n) nodeColor[j] = -1;
	
	// This is updated (For Unconnected & Connected)
	int ans = 0;
	int status = 0;
	for (int s = 1; s <= n; s++)
	{
		if(nodeColor[s] != -1 ) continue;
		
		nodeColor[s] = 1;
		// Create a queue (FIFO) of vertex numbers and enqueue source vertex
    	// for BFS traversal
		queue <int> q;
    	q.push(s);
		// Run while there are vertices in queue (Similar to BFS)
		while(!q.empty())
		{
			int u = q.front();
			//printf("u : %d\n",u);
			q.pop();
		
			for(int v = 0; v < AdjList[u].size(); v++)
			{
				if (nodeColor[ AdjList[u][v] ]  == -1)
           	 	{
                	// Assign alternate color to this adjacent v of u
                	nodeColor[ AdjList[u][v] ] = 1 - nodeColor[u];
                	q.push( AdjList[u][v] );
            	}
 
            	//  An edge from u to v exists and destination v is colored with
            	// 	same color as u
           
           		// Kondisi salah
		    	else if (nodeColor[ AdjList[u][v] ] == nodeColor[u])
           		{
           			//printf("U : %d \t v : %d\n",u,v);
           			printf("NO\n");
           			status = 1;
           			break;
           		}
       	 	}
        
        	if(status) break;
    	}
		
		if(status) break;	
	}
	
    if(!status) printf("YES\n");
}

int main()
{
	while(1)
	{
		sI(n);
		if(!n) break;
		
		int n1,n2;
		while(1)
		{
			sID(n1,n2);
			if(!n1 && !n2) break;
			AdjList[n1].pb(n2);
			AdjList[n2].pb(n1);
		}
		
		/*Debugging - Check Adjacency list (Correct)
 		REP(b,n)
 		{
 			printf("AdjList[%d]  : { ",b);
 			REP(c,AdjList[b].size())
 			{
 				printf("%d, ",AdjList[b][c]);
 			}
 			printf("} \n");
 		}
		*/
		
		bipartite();
		
		// Clear
		for(int c = 1; c <= n; c++) AdjList[c].clear();
	}
	
	return 0;
}
