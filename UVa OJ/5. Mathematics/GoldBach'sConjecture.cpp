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

void solve(int val)
{
	int prim1,prim2;
	int stat = 0;
	for(int a =1 ; a < primes.size(); a++)
	{
		// Pruning
		if(primes[a] > val ) break;	
		
		if(primes[a] % 2 == 1) prim1 = primes[a];
		
		for(int b = primes.size()-1; b >= a; b--)
		{
			// Pruning
			if( (prim1 + primes[b]) < val ) break;
			
			if(primes[b] % 2 == 1)
			{
				// Found
				if(prim1 + primes[b] == val)
				{
					stat = 1;
					prim2 = primes[b];
					break;
				}
			}
		}
		
		if(stat) break;
	}
	
	// Jika found
	if(stat) printf("%d = %d + %d\n",val,prim1,prim2);
	
	else printf("Goldbach's conjecture is wrong.\n");
}

int main()
{
	sieve(1000000);
	//printf("%d\n",primes[78400]);
	
	int bil;
	while(1)
	{
		sI(bil);
		if(!bil) break;
		
		solve(bil);
	}
	
	return 0;
}
