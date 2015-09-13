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
	primes.pb(0);
	for(LL i=2; i<=upperbound+1; i++)if(bs[i]){
	for(LL j=i*i; j<= upperbound+1; j+=i)bs[j] = 0;
			primes.pb((int) i);
	}
}

// Fenwick Tree Library
#define LSOne(S) (S & (-S))
vi ft;
		
void ft_create(vi &t, int n)
{
	t.assign(n+1,0);
}

// Returns  RSQ(1, b)
int ft_rsq(const vi &t, int b){
	int sum = 0;
	for(; b; b-= LSOne(b)) sum += t[b];	
	return sum;
}

// Returns RSQ(a,b)
int ft_rsq(const vi &t, int a, int b){
	return ft_rsq(t,b) - (a == 1 ? 0 : ft_rsq(t,a-1));
}

// Adjust value of k-th element (+/-)
void ft_adjust(vi &t, int k, int v){
	for(; k <= (int)t.size(); k+= LSOne(k))
		t[k] += v;
}

// Set the value in an index
void set_val(vi &t, int k, int v){
	int jum = ft_rsq(ft,k,k);
	//printf("jum : %d\n",jum);
	for(; k <= (int)t.size(); k+= LSOne(k))
	{
		t[k] = (t[k] - jum) + v;	
	} 
}

int main()
{
	int N;
	int cou = 0;
	while(1)
	{
		sI(N);
		if(!N) break;
		
		ft_create(ft,N);
		
		// Set Initial Value
		int val;
		for(int i = 1; i <= N; i++)
		{
			sI(val);
			ft_adjust(ft,i,val);
			//set_val(ft,i,val);
		}
		
		// Debugging
		/*
		printf("{ ");
		for(int i = 1; i <= N; i++)
		{
			printf("%d, ",ft[i]);
		}
		printf("}\n");
		*/
		
		char op[10];
		int l,r;
		
		if(cou) printf("\n");
		printf("Case %d:\n",cou+1);
		
		while(scanf("%s",&op))
		{
			if(op[0] == 'E') break; 
			scanf("%d %d",&l,&r);
			
		//	printf("Debug OP : %c L : %d R : %d\n",op[0],l,r);
			// if M, then Print RSQ(l,r)
			
			if(op[0] == 'M') printf("%d\n",ft_rsq(ft,l,r));
			else if(op[0] == 'S')
			{
				set_val(ft,l,r);
				// Debugging
				/*
				printf("{ ");
				for(int i = 1; i <= N; i++)
				{
					printf("%d, ",ft[i]);
				}
				printf("}\n");
				*/
			} 
		}
		
		cou++;
	}
	return 0;
}
