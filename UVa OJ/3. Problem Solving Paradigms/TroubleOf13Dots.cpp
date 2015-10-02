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
	int money, nItem;
	while(sID(money,nItem) == 2)
	{
		vii data;
		// Masukkan dummy
		data.pb(mp(0,0));
		
		int v,price;
		REP(a,nItem)
		{
			sID(price,v);
			data.pb(mp (price,v));
		}
		
		// Processing -- Knapsack Table
		int knTable[nItem + 5][money + 220];
		RESET(knTable,0);
		
		// Knapsack Processing
		int v1,v2;
		int maks  = 0;
		for(int i = 1; i <= nItem; i++)
		{
			v1 = data[i].first;
			v2 = data[i].second;
			
			if(v1 <= money + 200)
			{
				knTable[i][v1] = v2;
				if(v1 <= money) maks = max(maks,knTable[i][v1]);	
				else if(v1 > 2000)
				{
					if(money + 200 >= v1) maks = max(maks,knTable[i][v1]);	
				} 
			}
				
			for(int j = 1; j <= money+200; j++)
			{
				if(knTable[i-1][j] != 0)
				{
					knTable[i][j] = max(knTable[i][j],knTable[i-1][j]);
					
					// Penentuan Max
					if(j <= money) maks = max(maks,knTable[i][j]);	
					else if(j > 2000)
					{
						if(money + 200 >= j) maks = max(maks,knTable[i][j]);	
					}	 
					
					
					if( (j + v1) > money+200)   continue;	  
					else
					{
						knTable[i][j+v1] = knTable[i-1][j] + v2;
						
						// Penentuan Max
						if(j+v1 <= money) maks = max(maks,knTable[i][j+v1]);	
						else if( (j+v1) > 2000)
						{
							if(money + 200 >= (j + v1) ) maks = max(maks,knTable[i][j+v1]);	
						}	 
					} 

				}
			}
		}
		
		printf("%d\n",maks);
	}
	
	return 0;
}
