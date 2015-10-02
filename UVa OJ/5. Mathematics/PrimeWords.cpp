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

LL _sieve_size;
bitset<10000010> bs;
vi primes;

// Prima pertama terdapat di primes[1] yah :D
void sieve(LL upperbound){
	_sieve_size = upperbound + 1;
	bs.set();
	bs[0]=bs[1]=0;
	primes.pb(0);
	for(LL i=2; i<= _sieve_size; i++)if(bs[i]){
	for(LL j=i*i; j<= _sieve_size; j+=i)bs[j] = 0;
			primes.pb((int) i);
	}
}

// A good Deterministic Prime Factor
bool isPrime(LL N)
{
	// O(1) for small primes
	if(N <= _sieve_size) return bs[N];
	for(int i = 0; i < primes.size(); i++)
	{
		if(N % primes[i] == 0) return false;
		return true;
	}
}

string besar = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string kecil = "abcdefghijklmnopqrstuvwxyz";

int cariBesar(char kar)
{
	int cou = 1;
	REP(a,26)
	{
		if(besar[a] == kar) return cou;
		
		cou++;
	}
}

int cariKecil(char kar)
{
	int cou = 1;
	REP(a,26)
	{
		if(kecil[a] == kar) return cou;
		
		cou++;
	}
}

int main()
{
	sieve(100000);
	string kata;
	while(cin>>kata)
	{
		int pos;
		LL total = 0;
		
		// Hitung total Num.. :D
		REP(a,kata.size())
		{
			if(isupper(kata[a]))
			{
			   pos = 26 + cariBesar(kata[a]);
			}
			
			else if(islower(kata[a]))
			{
			   pos = cariKecil(kata[a]);	
			}	
			
			//printf("pos[%d] : %d\n",a,pos);
			total += pos;
		}
		
		//printf("total : %lld\n",total);
		// Cek if Prime
		if(total == 1) printf("It is a prime word.\n");
		else if(isPrime(total)) printf("It is a prime word.\n");
		else printf("It is not a prime word.\n");
	}
	
	return 0;
}
