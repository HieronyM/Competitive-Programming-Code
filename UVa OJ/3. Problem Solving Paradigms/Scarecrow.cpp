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

int TC,a,b;
int n,counter;

int main()
 {
 	scanf("%d",&TC);
 	for(a = 1; a <= TC; a++)
 	{
 	  string temp;
 	  counter = 0;
 	  scanf("%d",&n);
	  temp = GetString();
	  b = 0;
	  while(temp[b] != '\0')
	  {
	  	if(b >= n) break;
	  	
		if(temp[b] == '.')
		{
			//printf("Ketemu di B : %d\n",b);
			counter++;
			b += 2;
		}
		b++;	  	
	  }	
	  printf("Case %d: %d\n",a,counter);
 	}
 	
 	return 0;
 }
