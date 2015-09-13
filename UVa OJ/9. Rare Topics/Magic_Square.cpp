
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

int main()
{
	int n;
	int TC = 1;
	while(scanf("%d",&n) != EOF)
	{
		int val = 1;
		int data[n+5][n+5];			// Dynamically
		RESET(data,0);
		data[1][(n/2) + 1] = val;
		
		int x,y;		// Posisi awal
		x = 1;
		y = (n/2) + 1;
		
		val++;
		
		// For Spacing
		int maks[n+15];
		RESET(maks,0);
		
		while(val <= n*n)
		{
			int tempX = x;
			int tempY = y;
			
			x--;
			y++;
			
			if(x == 0) x = n;
			if(y > n) y = 1;
			
			// Penentuan Lokasi
			if(data[x][y] == 0) data[x][y] = val;
			else
			{
				// Balikkan lagi, wakakkakakka
				x = tempX;
				y = tempY;
				
				data[x+1][y] = val;
				x++;
			}
			
			val++;
		}
		
		// For Spacing
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				// For Spacing
				string panjang = IntToString(data[i][j]);
				if(maks[j] < panjang.size()) maks[j] = panjang.size();
			}	
		}
		
		// Cetak Hasil
		if(TC > 1) printf("\n");
		
		int sum = 0;
		for(int i = 1; i <= n; i++) sum += data[1][i];
	
		printf("n=%d, sum=%d\n",n,sum);
		
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				string panjang2 = IntToString(data[i][j]);
				//printf("size1 : %d   size2 : %d\n",maks[j],panjang2.size());
				
				for(int k = panjang2.size(); k <= maks[j]-1; k++) printf(" ");
				printf(" %d",data[i][j]);
			}
			
			printf("\n");
		}
		
		TC++;
	}
	return 0;
}
