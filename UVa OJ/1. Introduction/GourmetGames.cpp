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

int TC,a,n,m;

int main()
 {
 	int nMatch,status;
 	scanf("%d",&TC);
 	for(a = 0; a < TC; a++)
 	{
 		nMatch = status = 0;
 		scanf("%d %d",&n, &m);
		if(n == m )	printf("1\n");
		else
		{
			nMatch = n / m;
			n = nMatch + (n % m);
			
			//printf("n Sebelum diproses : %d\n",n);
			while(1)
			{
				nMatch += n / m;
				if(n % m == 0 && n / m == 1) break;
				
				else if(n < m)
				{
					status = 1;
					break;
				}
				
				n = n/m;
				
				//else n = (n / m) + (n % m);
				 
			}
			if(status) printf("cannot do this\n");
			else printf("%d\n",nMatch);
		}
 	}
 	
 	return 0;
 }
