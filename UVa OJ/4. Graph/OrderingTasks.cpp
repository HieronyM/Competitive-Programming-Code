/* Description
	Program ini digunakan untuk menemukan Topological Sort di dalam suatu DAG (Directed Acyclic Graph).
	Dimana DAG adalah graph yang tidak ada 'directed cycle' (Ada cycle di graph yang directed).
	
	Program ini mennggnakan algoritma DFS, dimana dia akan terus mencari sampai ke kedalaman.
	dan apabila sudah tidak ada childnya, maka node itu dimasukkan ke dalam toposort.
	Setelah itu reverse kan, toposortnya.
	
	Topological Sort Problem : Ada n tasks, namun untuk menyiapkan task ke-i dia harus menyelesaikan task ke-j dahulu.
*/

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <limits.h>

using namespace std;

typedef long long ll;
typedef pair <int,int> pii;
typedef vector <int> vi;
#define REP(a,n) for(int (a) = 0; (a) < n; a++) 
#define pb push_back
#define mp make_pair
#define ALL(var) var.begin(),var.end()

int n,m;
vi Data[105];
vi toposort;
int dfs_num[105];		// Status visited
 		
// Toposort Algorithm - Just a little modify of DFS
void dfs2(int u)
{
	dfs_num[u] = 1; // Set as Visited
	
	int j;
	REP(j, Data[u].size())
	{
		int temp = Data[u][j];
		if(dfs_num[temp] == 0) dfs2(temp); 
	}
	
	toposort.pb(u);
}

int main()
 { 	
 	while(1)
 	{
 		int a;
 		int u,v;
 		scanf("%d %d",&n,&m);
 		if(!n && !m) break;
 	
 		// Initialization
 		for(a = 1; a <= n; a++) dfs_num[a] = 0; 
		 
		REP(a,m)
		 {
		 	scanf("%d %d",&u,&v);
		 	Data[u].pb(v);
		 }	
		 
		 // Processing
		 for(a = 1; a <= n; a++)
		 {
		 	if(dfs_num[a] == 0) dfs2(a);
		 }
		 
		 reverse(ALL(toposort));
		 
		 // Print the toposort
		 REP(a,n)
		 {
		 	if(!a) printf("%d",toposort[a]);
		 	else printf(" %d",toposort[a]);
		 }
		 
		 printf("\n");
		 
		 // Refresh
		 toposort.clear();
 	}
 	
 	return 0;
 }

