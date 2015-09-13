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

int findIndex(char kar)
{
	string hur = "abcdefgh";
	
	REP(a,8)
	{
		if(kar == hur[a])
		{
			return a+1;
		}
	}
}

int findIndex2(char kar)
{
	string hur = "12345678";
	
	REP(a,8)
	{
		if(kar == hur[a])
		{
			return a+1;
		}
	}
}

int x1,x2,y2;
int y12;
int peta[10][10];

int BFS()
{
	queue<pii> Q;
	if(x1 == x2 && y12 == y2) return 0;
	
	Q.push(mp(x1,y12));
	
	int layer = 0;
	int a1[8] = {2,1,-1,-2,-2,-1,1,2};
	int b2[8] = {1,2,2,1,-1,-2,-2,-1};
	while(!Q.empty())
	{
		layer++;
		int size = Q.size();
		
		REP(a,size)
		{
			pii pos = Q.front();
			Q.pop();
			
			int tempX,tempY;
			REP(b,8)
			{
				tempX = pos.first + a1[b];
				tempY = pos.second + b2[b];
				
				//printf("tempX : %d tempY : %d\n",tempX,tempY);
				if(tempX >= 1 && tempX <= 8 && tempY >= 1 && tempY <= 8 && peta[tempX][tempY] == 0)
				{
					peta[tempX][tempY] = 1;
					Q.push(mp(tempX,tempY));
					
					if(tempX == x2 && tempY == y2)
					{
						//printf("MASUK\n");
						return layer;	
					} 
				}
			}
		}
	}
}

int main()
{
	string pos1,pos2;
	while(cin>>pos1>>pos2)
	{
		RESET(peta,0);
		x1 = findIndex(pos1[0]);
		y12 = findIndex2(pos1[1]);
		
		x2 = findIndex(pos2[0]);
		y2 = findIndex2(pos2[1]);
			
		//printf("x1 : %d y1 : %d\n",x1,y12);
		//printf("x2 : %d y2 : %d\n",x2,y2);
		
		printf("To get from %s to %s takes %d knight moves.\n",pos1.c_str(),pos2.c_str(),BFS());
	}
	
	return 0;
}
