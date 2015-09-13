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

double PI = acos(-1);

#define REP(i,n) for((i) = 0; (i) < (int)(n); (i)++)
#define READ_INT(data) scanf("%d",&data); 
#define RESET(c,v) memset(c, v, sizeof(c))
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define pb push_back

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

int TC,n,a;
int mile,juice,duration;

int main()
 {
 	scanf("%d",&TC);
 	REP(a, TC)
 	{
 		mile = juice = 0;
	 	scanf("%d",&n);
 		while(n--)
 		{
 			scanf("%d",&duration);
 			mile = mile + (( (duration / 30) + 1) * 10);
			juice = juice + (( (duration / 60) + 1) * 15);  
 		}
 		if(mile < juice) printf("Case %d: Mile %d\n",a+1,mile);
   else if(mile > juice) printf("Case %d: Juice %d\n",a+1,juice);
	 	else printf("Case %d: Mile Juice %d\n",a+1,juice);
	}
 	return 0;
 }
