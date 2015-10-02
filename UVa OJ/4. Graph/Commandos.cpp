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
#define INF 1000000000


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
int s,d;	// source, destination

int AdjMat[105][105];

void floydWarshall()
{
	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				AdjMat[i][j] = min(AdjMat[i][j], (AdjMat[i][k] + AdjMat[k][j]) );
}

int main()
{
	int TC;
	sI(TC);
	REP(a,TC)
	{
		sI(n);
		sI(m);
		
		// Set to 1 B, if there is no exists edge
		REP(b,n)
			REP(c,n)
				AdjMat[b][c] = 10000000;
		
		
		int n1,n2;
		REP(b,m)
		{
			AdjMat[b][b] = 0;	// itself, set as zero
			sID(n1,n2);
			
			// Masukan
			AdjMat[n1][n2] = 1;
			AdjMat[n2][n1] = 1;
			
		}
		
		
		// source and Destination
		sID(s,d);
		
		// Check Adjacency Matriks <Before Floyd Warshall>
		/*printf("-- Sebelum Floyd Warshall dipanggil -- \n");
		REP(b,n)
		 {
		 	REP(c,n)
		 	{
		 		printf("%d ",AdjMat[b][c]);
		 	}
		 	printf("\n");
		 }
		*/
		
		floydWarshall();
		int maks = 0;
		
		// Check Adjacency Matriks <After Floyd Warshall>
		/*printf("-- Setelah Floyd Warshall dipanggil -- \n");
		REP(b,n)
		 {
		 	REP(c,n)
		 	{
		 		printf("%d ",AdjMat[b][c]);
		 	}
		 	printf("\n");
		 }
		*/
		
		if(n == 2) printf("Case %d: 1\n",a+1);
		
		else
		{
			REP(b,n)
			{
				int temp = 0;
				if(b == s || b == d) continue;
				else
				{
					temp += AdjMat[s][b];
					temp += AdjMat[b][d];
				
					maks = max(maks,temp);
				}
			}
		
			printf("Case %d: %d\n",a+1,maks);
		
		}
	}
}
