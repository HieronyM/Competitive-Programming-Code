#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <limits.h>
#include <cstring>

#include <map>
using namespace std;

typedef long long ll;
typedef pair <int,int> pii;
#define REP(a,n) for(int (a) = 0; (a) < n; a++) 
#define pb push_back
#define mp make_pair
#define ALL(var) var.begin(),var.end()
#define sI(n) scanf("%d",&n);
#define RESET(arr,val) memset(arr,val, sizeof(arr))

inline string GetString(void){
	char x[1000005];
	scanf("%s",x); string s = x;
	return s;
}

int n,m;
#define Inf 1000000000
int dis[205][205];

void Floyd()
{
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
			{
				if( i == j || k == i || j == k ) continue ;
				dis[i][j] = max(dis[i][j], min(dis[i][k],dis[k][j]) );
			}
}
  
int main()
 { 	
 	int counter  = 1;
 	while(1)
 	{
 		string kota1,kota2;					// String kota, sama val
 		int n1,n2,w;						// Nampung hasil mapping
 		int idxNow = 1;						// Index now
 		map <string,int>  mapKota;			// Nyimpan mappingnya
 		scanf("%d %d",&n,&m);
 		
 		if(!n && !m) break;
 		RESET(dis,0);							//	Make initial
 		
 		// Input Edge
		REP(a,m)
 		{
 			kota1 = GetString();
 			kota2 = GetString();
 			scanf("%d",&w);
 			
 			// Bagian Kota Pertama
 			
			if(mapKota[kota1] == 0)
 			{
 				n1 = idxNow;
 				mapKota[kota1] = n1;
 				idxNow++;
 			}
 			else n1 = mapKota[kota1];
 			
 			// Bagian Kota Kedua
 			if(mapKota[kota2] == 0)
 			{
 				n2 = idxNow;
 				mapKota[kota2] = n2;
 				idxNow++;
 			}
 			else n2 = mapKota[kota2];
 			
 			//printf("w : %d n1 : %d n2 : %d\n",w,n1,n2);
 			
 			dis[n1][n2] = w, dis[n2][n1] = w;
 		}
 		
 		int s,d;			// source and destination
 		kota1 = GetString();
 		kota2 = GetString();
 		s = mapKota[kota1];
 		d = mapKota[kota2];
 		
 		//printf("source : %d  Destination : %d\n",s,d);
 		Floyd();
 	
 		printf("Scenario #%d\n",counter);
 		printf("%d tons\n\n",dis[s][d]);
		 
		 counter++;	
	}
		 	
 	return 0;
 }

