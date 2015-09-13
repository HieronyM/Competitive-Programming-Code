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
	for(LL i=2; i<=upperbound+1; i++)if(bs[i]){
	for(LL j=i*i; j<= upperbound+1; j+=i)bs[j] = 0;
			primes.pb((int) i);
	}
}

// Untuk menghitung Sum dari semua Divisors dari N
LL sumDiv(LL N)
{
	//printf("masuk\n");
	LL PF_idx = 0;
	LL PF = primes[PF_idx];
	LL ans = 1;
	while(N != 1 && (PF * PF <= N))
	{
		//printf("masuk1\n");
		LL power = 0;
		while(N % PF == 0)
		{
			//printf("masuk2\n");
			N /= PF;
			power++;
		}
		
		//printf("masuk3\n");
		ans *= ((LL) pow( (double)PF, power + 1.0) -1) / (PF-1);
		PF = primes[++PF_idx]; 
	}
	
	//printf("masuk4\n");
	if(N != 1) ans *= ((LL) pow( (double)N, 2.0) -1) / (N-1);
	return ans;
}

int main()
{
	sieve(10000);
	LL num;
	int caseNo = 1;
	while(1)
	{
		scanf("%lld",&num);
		if(num == 0) break;
		
		int found = 0;
		for(LL j = num; j >= 1; j--)
		{
			//printf("-\n");
			//printf("sumDiv[%lld] : %lld\n",j,sumDiv(j));
			if(sumDiv(j) == num)
			{
				found = 1;
				printf("Case %d: %lld\n",caseNo,j);	
				break;
			} 
		}
		
		if(!found) printf("Case %d: -1\n",caseNo);	
		caseNo++;
	}
	
	return 0;
}
