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

int main()
{
	int n;
	sI(n);
	
	int temp;

	int data[105][105];
	
	// Generate Sum Table
	REP(a,n)
	{
		REP(b,n)
		{
			sI(data[a][b]);
			if(a > 0) data[a][b] += data[a-1][b];
			if(b > 0) data[a][b] += data[a][b-1];
			if(a > 0 && b > 0 ) data[a][b] -= data[a-1][b-1];		// Inclusion - Exclusion Principle
		}
	}
	
	// Debugging - Cek Sum Table (Correct)
	/*printf("\nTabel Sum\n");
	REP(a,n)
	{
		REP(b,n)
		{
			printf("%d ",data[a][b]);
		}
		printf("\n");
	}
	*/
	
	int MaxSum = -127 * 100 * 100; // 100 is N constraint
	// Hitung Max Sum
	
	int subRect;		// Variabel penampung sum  sub rectangular
	REP(a,n)
	{
		REP(b,n)
		{
			for(int c = 0; c <= a; c++)
			{
				for(int d = 0; d <= b; d++)
				{
					subRect = data[a][b];
					
					// Inclusi - Exclusi again
					if(c > 0) subRect -= data[c-1][b];
					if(d > 0) subRect -= data[a][d-1];
					if(c > 0 && d > 0) subRect += data[c-1][d-1];
					
					MaxSum = max(subRect, MaxSum);
				}
			}	
		}
	}
	
	printf("%d\n",MaxSum);
	return 0;
}
