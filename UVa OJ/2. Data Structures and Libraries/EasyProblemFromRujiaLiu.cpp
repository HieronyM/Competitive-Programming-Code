#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

#define REP(a,n) for((a) = 0; (a) < n; a++)
#define pb push_back
#define vi vector <int>

vi adjList[1000007];
int n,m; 		
int main()
 {
 	int a;
 	int angka;
 	while(scanf("%d %d",&n,&m) != EOF)
 	{
 	
 		for(a = 1; a <= n; a++)
 		{
 			scanf("%d",&angka);
 		
 			// Insert to adjList
 			adjList[angka].pb(a);
 		}
 	
 		int k,v;
 		REP(a,m)
 		{
 			scanf("%d %d",&k,&v);
 			//printf("AdjList[%d] : %d\n",v,adjList[v].size());
 			if(adjList[v].size() < k) printf("0\n");
 			else printf("%d\n",adjList[v][k-1]);
 		}
	}
	
	return 0;
 }
