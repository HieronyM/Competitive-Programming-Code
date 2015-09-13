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


/* SUFFIX ARRAY LIBRARY */
// Second approach O(n log n)
#define MAX_N 100010

char T[MAX_N];
int n;
int RA[MAX_N], tempRA[MAX_N];
int SA[MAX_N], tempSA[MAX_N];
int c[MAX_N];

// LCP
int PLCP[MAX_N];
int LCP[MAX_N];
int Phi[MAX_N];

void countingSort(int k)
{
	int i,sum,maxi = max(300,n);
	memset(c, 0, sizeof c);
	for(i = 0; i < n; i++)
		c[i + k < n ? RA[i + k] : 0]++;
	for(i = sum = 0; i < maxi; i++){
		int t = c[i];	
		c[i] = sum;
		sum += t;
	}
	
	for(i = 0; i < n; i++)
		tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
	for(i = 0; i < n; i++)
		SA[i] = tempSA[i];
}

void constructSA(){
	int i,k,r;
	for(i = 0; i < n; i++) RA[i] = T[i] - '.';
	for(i = 0; i < n; i++) SA[i] = i;
	for(k = 1; k < n; k <<= 1){
		countingSort(k);
		countingSort(0);
		tempRA[SA[0]] = r = 0;
		for(i = 1; i < n; i++)
			tempRA[SA[i]] =
				(RA[SA[i]] == RA[SA[i-1]] && RA[SA[i] + k] == RA[SA[i-1] + k]) ? r : ++r;
		for(i = 0; i < n; i++)
			RA[i] = tempRA[i];
	}
	
}

// Compute LCP (Longest Common Prefix)
// Use to find Longest Repeated String
// ex : S1 : GATAGACA  S2 : GAYA LCP : 2 (GA)
void computeLCP()
{
	int i,L;
	Phi[SA[0]] = -1;
	for(i = 1; i < n; i++)
		Phi[SA[i]] = SA[i-1];
	for(i = L = 0; i < n; i++)
	{
		if(Phi[i] == -1) 
		{
			PLCP[i] = 0;
			continue;	
		}
		
		while(T[i + L] == T[Phi[i] + L]) L++;
		PLCP[i] = L;
		L = max(L-1,0);
	}
	
	for(i = 1; i < n; i++)
		LCP[i] = PLCP[SA[i]];
}

int main(){
	
	int TC;
	scanf("%d\n",&TC);
	REP(a,TC)
	{
		n = (int) strlen(gets(T));
		constructSA();
		computeLCP();
		
		// Cek Longest Repeated
		int maks = 0;
		string kata;
		int cou = 0;
		for(int i = 0; i < n; i++)
		{
			string temp2 = T + SA[i];
			string ekstrak2 (temp2,0,LCP[i]);
					
			if(maks < LCP[i])
			{
				if(LCP[i] < n) 
				{
					maks = LCP[i];
					kata = ekstrak2;
					cou = 1;	
				}
			}	
			
			else if(maks == LCP[i])
			{
				if(kata == ekstrak2)
				{
					//printf("masuk3 di [%d]\n",i);
					cou++;	
				} 
					
				else if(kata > ekstrak2 )
				{
					//printf("masuk4 di [%d]\n",i);
					kata = ekstrak2;
					cou = 1;
				}
			}
		}
		
		if(kata == "") printf("No repetitions found!\n");
		else printf("%s %d\n",kata.c_str(),cou+1);
		
		 //Debugging
		//Print Suffix Array
		for(int i = 0; i < n; i++) printf("%2d\t%s\n",SA[i],T + SA[i]);
		
		printf("\n");
		//Print LCP
		for(int i = 0; i < n; i++) 
		{
			string temp = T + SA[i];
			//printf("Temp : %s\n",temp.c_str());
			string ekstrak (temp,0,LCP[i]);
			printf("%2d\t%s\n",LCP[i],ekstrak.c_str());	
		}
		
	}	
}
