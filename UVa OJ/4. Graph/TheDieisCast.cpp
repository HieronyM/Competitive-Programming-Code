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
int dr[]={1,-1,0,0};
int dc[]={0,0,1,-1};


int R,C;
string data[105];
queue< pair <int,int> > Q;

void Flood(int r,int c, char pattern)
{
	if(pattern == '*') data[r][c] = '#';					// Set as Visited
	for(int i = 0; i < 4; i++)
	{
		int tempR = r + dr[i];
		int tempC = c + dc[i];
		
		// Tidak melewati bound
		if(tempR >= 0 && tempR < R && tempC >= 0 && tempC < C)
		{
			// Bisa ngeflood
			if(data[tempR][tempC] == 'X')
			{
				Q.push( mp(tempR,tempC) );
			}
			else if(data[tempR][tempC] == '*')
			{
				Flood(tempR,tempC,'*');
			} 
		}
	}
}

void Flood2(int r,int c)
{
	data[r][c] = 'x';					// Set as Visited
	for(int i = 0; i < 4; i++)
	{
		int tempR = r + dr[i];
		int tempC = c + dc[i];
		
		// Tidak melewati bound
		if(tempR >= 0 && tempR < R && tempC >= 0 && tempC < C)
		{
			// Bisa ngeflood
			if(data[tempR][tempC] == 'X')
			{
				Flood2(tempR,tempC);	
			}
		}
	}
}

int main()
{
	int TC = 1;
	while(1)
	{
		if(TC > 1) printf("\n");
		vi cou;
		sID(C,R);
		if(!R && !C) break;
		
		REP(a,R)
		{
			string temp = GetString();
			data[a] = temp;
		}
		
		// Processing
		REP(a,R)
		{
			REP(b,C)
			{
				if(data[a][b] == '*')
				{
					Flood(a,b,'*');
					
					int size = Q.size();
					int jum = 0;
					
					REP(j,size)
					{
						pii temp= Q.front();
						Q.pop();
						
						// Belum divisit
						if(data[temp.first][temp.second] == 'X')
						{
							jum++;
							Flood2(temp.first,temp.second);
						}
					}
					
					cou.pb(jum);	
				} 
			}
		}
		
		sort(ALL(cou));
		
		printf("Throw %d\n",TC);
		REP(a,cou.size())
		{
			if(a > 0)
			{
				printf(" ");
			}
			
			printf("%d",cou[a]);
		}
		
		printf("\n");
		
		TC++;
	}
	
	
	return 0;
}
