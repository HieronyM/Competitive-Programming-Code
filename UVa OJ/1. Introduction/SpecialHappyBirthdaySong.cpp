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

int n,a;
pair <string,int> Data[100];
string str;

void Cetak(int ite)
 {
 	REP(a, ite)
		 {
 			if(a % 4 == 0) printf("%s: Happy\n",Data[ (a % n) ].first.c_str());
 			else if(a == 11 || a == 27 || a == 43 || a == 59 || a == 75 || a == 91) printf("%s: Rujia\n",Data[ (a % n) ].first.c_str());
 			else if(a % 4 == 1) printf("%s: birthday\n",Data[ (a % n) ].first.c_str());
 			else if(a % 4 == 2) printf("%s: to\n",Data[ (a % n) ].first.c_str());
 			else if(a % 4 == 3) printf("%s: you\n",Data[ (a % n) ].first.c_str());
 		}
 }

int main()
 {
 	scanf("%d",&n);
 	REP(a,n)
 	{
		cin >> str;                            // Sediakan Temporary
 		Data[a].first = str;
 	}
 	
 	if( n <= 16)
 	{
 		//printf("MAsuk\n");
 		//for(a = 0; a < 16; a++)
 		Cetak(16);
 	}
 	
 	else
 	{
 		int temp = 16;
 		while(temp < n)
 		{
 			temp += 16;
 		}
 		
 		Cetak(temp);
 	}
 	return 0;
 }
