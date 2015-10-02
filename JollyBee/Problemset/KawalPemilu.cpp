
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

int nodeParent[1000005];
int sum1[1000005];	
int sum2[1000005];
	
int main()
{
	int M;
	sI(M);
	
	for(int i=0 ; i <= 1000000; i++)
	{
		nodeParent[i] = 0;
		sum1[i] = 0;
		sum2[i] = 0;
	}
	
	//map <int,int> nodeParent;		// Mapping suatu node berada di parent mana
	//map <int, int> sum1;		// Mapping suatu region itu total nya berapa
	//map <int, int> sum2;		// Mapping suatu region itu total nya berapa
	
	REP(a,M)
	{
		// Scanf idRegion
		int idRegion;
		sI(idRegion);
		
		// n-Sub
		int nSub;
		sI(nSub);
		REP(b,nSub)
		{
			int idSub;
			sI(idSub);
			nodeParent[idSub] = idRegion;
		}
	}
		
	// Mulai Query
	int Q;
	sI(Q);
	REP(b,Q)
	{
		int op;
		int jum1,jum2;
		sI(op);
			
		// Query type 1
		if(op > -1)
		{
			sID(jum1,jum2);
			while(nodeParent[op] != 0)
			{
				sum1[op] = sum1[op] + jum1;
				sum2[op] = sum2[op] + jum2;	
				op = nodeParent[op];
			}		
			
			sum1[op] = sum1[op] + jum1;
			sum2[op] = sum2[op] + jum2;
				
			op = nodeParent[op];	
			sum1[op] = sum1[op] + jum1;
			sum2[op] = sum2[op] + jum2;
		}
			
		else
		{
			int idCari;
			sI(idCari);
			printf("%d %d\n",sum1[idCari],sum2[idCari]);
		}
	}
	
	return 0;
}
