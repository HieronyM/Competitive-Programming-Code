// Ideafuse Mikroskill
// Template by Hierony

#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>

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

int main()
{
	int duration;
	while(sI(duration) == 1)
	{
		int nLagu;
		sI(nLagu);
		vii lagu;
		lagu.pb(mp(0,0));
		
		int temp;
		REP(a,nLagu)
		{
			sI(temp);
			lagu.pb(mp(temp,temp));
		}
		
		int knTable[nLagu + 5][duration + 5];
		int keepTable[nLagu + 5][duration + 5];
		
		RESET(knTable,0);
		RESET(keepTable,0);
		
		// Mulai Pencarian knapsack
		int temp2,status;
		for(int i = 1; i <= nLagu; i++)
		{
			for(int j =1; j <= duration; j++)
			{
				// Bila item itu bisa diinclude
				if(j - lagu[i].first >= 0)
				{
					temp2 = lagu[i].first;
					status = 1;
				}
				
				else
				{
					status = 0;	
				} 
				
				// Ambil dari atas kak
				if(!status)
				{
					knTable[i][j] = knTable[i-1][j];
					keepTable[i][j] = 0;					// Cannot be use	
				}
				
				else
				{
					knTable[i][j] = max(knTable[i-1][j], (knTable[i-1][(j-lagu[i].first)] + lagu[i].second) );
					
					// Penentuan
					if(knTable[i][j] == knTable[i-1][j]) keepTable[i][j] = 0;
					else keepTable[i][j] = 1;
				} 
			}
		}
		 
		// Debugging (Cek knapsack Table dan Keep Table)
		/*
		printf("Cek Knapsack Table\n");
		REP(a,nLagu+1)
		{
			REP(b,duration+1) printf("%d ",knTable[a][b]);
			
			printf("\n");
		}
			
		printf("Cek Keep Table\n");
		REP(a,nLagu+1)
		{
			REP(b,duration+1) printf("%d ",keepTable[a][b]);
			
			printf("\n");
		}
		*/
		
		vi idxSol;
		int copyDur = duration;
		for(int v = nLagu; v >= 1; v--)
		{
			if(keepTable[v][duration] == 1)
			{
				idxSol.pb(v);
				//printf("%d ",lagu[v].first);
				duration -= lagu[v].first;
			}
		}
		
		for(int v = idxSol.size()-1; v >= 0; v--) printf("%d ",lagu[idxSol[v]].first);
		
		printf("sum:%d\n",knTable[nLagu][copyDur]);
	}
	
	return 0;
}
