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
typedef unsigned long long ULL;
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

#define REP(i,n) for(int (i) = 0; (i) < (int)(n); (i)++)
#define READ_int(data) scanf("%d",&data); 
#define RESET(c,v) memset(c, v, sizeof(c))
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define pb push_back
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

vi marble;
int N;

void binser(int val)
{
	int found = 0,idxMin = N;
	int l = 0,mid;
	int r = N;
	
	while(l < r)
	{
		mid = (l+r) / 2;
		
		//printf("marble[%d] : %d\n",mid,marble[mid]);
		if(marble[mid] < val) l = mid+1; 
		else if(marble[mid] >= val) r = mid;
		
		if(marble[mid] == val)
		{
			found = 1;
			if(idxMin > mid) idxMin = mid;
		}
	}
	
	if(found) printf("%d found at %d\n",val,idxMin+1);
	else printf("%d not found\n",val);
}
int main()
{
	int Q,counter = 1;
	while(1)
	{		
		int temp;
		
		sID(N,Q);
		if(!N && !Q) break;
		
		// Insert marble
		REP(a,N)
		{
			sI(temp);
			marble.pb(temp);
		}
		
		sort(ALL(marble));
		
		printf("CASE# %d:\n",counter);
		// Query
		REP(a,Q)
		{
			sI(temp);
			binser(temp);
		}
		
		counter++;
		marble.clear();
	}
	
	return 0;
}
