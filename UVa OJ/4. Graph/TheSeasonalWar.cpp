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

// Flood fill gan
int dr[]={1,1,0,-1,-1,-1, 0, 1};
int dc[]={0,1,1, 1, 0,-1,-1,-1};

string data[35];
int n;
	
void flood(int row, int column)
{
	data[row][column] = '2';
	
	for(int i = 0; i < 8; i++)
	{
		int tempR = row + dr[i];
		int tempC = column + dc[i];
		
		//printf("tempR : %d  tempC : %d\n",tempR,tempC);
		// It's valid
		if( (tempR >= 0 && tempR < n) && (tempC >= 0 && tempC < n) )
		{
			if(data[tempR][tempC] == '1') flood(tempR,tempC);
		}
	}
}

int main()
{
	int TC = 1;
	while(scanf("%d",&n) == 1)
	{
		REP(a,n)
		{
			string pattern = GetString();
			data[a] = pattern;	
		}
		
		int cou = 0;
		REP(a,n)
		{
			REP(b,n)
			{
				if(data[a][b] == '1')
				{
					//printf("Terjadi di a : %d dan b : %d\n",a,b);
					cou++;
					flood(a,b);
				} 
			}
		}	
		
		printf("Image number %d contains %d war eagles.\n",TC,cou);
		
		TC++;
	}
	
	return 0;
}
