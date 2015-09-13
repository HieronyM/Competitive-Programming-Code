
// Template by Hierony

#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <limits.h>

#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <bitset>

using namespace std;

typedef unsigned long long ULL;
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

int v,e;
vector < pair<int, pii> > EdgeList;
vector <int> pSet;		// To store the Set Parent

/// -------- Union Find Disjoint Method -------//
void initSet(int n)
{	
	int j;
	pSet.assign(n+1,0);
	for(j = 1; j <=n; j++) pSet[j] = j;		
}

int findSet(int i)
{
	return (pSet[i] == i) ? i : pSet[i] = findSet(pSet[i]);
}

bool isSameSet(int i, int j)
{
	return findSet(i) == findSet(j);
}

void unionSet(int i,int j)
{
	pSet[findSet(i)] = findSet(j);
}

vi flagEdge;		
int status;
int mstLength;

void findMST(int flagedEdge, int cond)
{
	initSet(v);
 	
 	int edgeUsed = 0;
 	
 	int mst = 0;
	REP(i,e)
 	{
 		pair<int,pii> temp = EdgeList[i];
 		
		if(!isSameSet(temp.second.first, temp.second.second) && i != flagedEdge)
 		{
 			mst += temp.first;
 			unionSet(temp.second.first,temp.second.second);
 			if(cond) flagEdge.pb(i);
 			
 			edgeUsed++;
			//printf("temp.first : %d, i : %d\n",temp.first,i);
		}
 	}
 	
 	if(edgeUsed == v-1)
	 {
	 	//printf("edgeUsed : %d\n",edgeUsed);
 		//printf("mst : %d\n",mst);
 	
	   mstLength = mst;
	   status = 1;
	 } 
 	else
	{
	 	status = 0;	
	} 
}

int main()
{
	int TC;
	sI(TC);
	REP(a,TC)
	{
		mstLength = 0;
		status = 0;				// Status if MST found
		sID(v,e);
		
		REP(b,e)
		{
			int n1,n2,val;
			scanf("%d %d %d",&n1,&n2,&val);
			EdgeList.pb(mp(val, mp(n1,n2)));
		}
		
		// Important part
		sort(ALL(EdgeList));
		
		// Find the MST First
		findMST(e,1);
		
		//printf("MstLength Found : %d\n",mstLength);
		// First Search : No shortest Path, and it concludes that second path is not exist
		if(!status) printf("Case #%d : No way\n",a+1);
		
		
		// Find the second best Spanning tree
		else
		{
			int sbMST = INT_MAX;
			
			// Tries for each flagged edge
			REP(b,flagEdge.size())
			{
				mstLength = 0;
				findMST(flagEdge[b],0);
				if(mstLength != 0) sbMST = min (sbMST, mstLength);
			}
			
			// Second Best Not Found
			if(sbMST == INT_MAX) printf("Case #%d : No second way\n",a+1);
			
			else printf("Case #%d : %d\n",a+1,sbMST);
		}
		
		// Clear
		flagEdge.clear();
		EdgeList.clear();
	}
	
	return 0;
}
