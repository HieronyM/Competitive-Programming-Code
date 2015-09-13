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

int nBachelor,nSpinster;

vi Bachelor,Spinster;

int main()
 {
 	int temp,a,counter = 1;
 	while(1)
 	{
 		scanf("%d %d",&nBachelor,&nSpinster);
 		if(!nBachelor && !nSpinster) break;
 		
 		else
 		{
 			// Nampung Bachelor
 			REP(a,nBachelor)
 			{
 				scanf("%d",&temp);
 				Bachelor.pb(temp);
 			}
 			
 			// Nampung Spinster
 			REP(a,nSpinster)
 			{
 				scanf("%d",&temp);
 				Spinster.pb(temp);
 			}
 			
 			sort(Bachelor.begin(), Bachelor.begin() + nBachelor);
 			
 			// Buat Kondisi
 			// Jika jumlah Bachelor <= Spinster
 			if(nBachelor <= nSpinster) printf("Case %d: 0\n",counter);
 			
 			// Jika jumlah Bachelor > Spinster
 			
 			else if(nBachelor > nSpinster) printf("Case %d: %d %d\n",counter,(nBachelor-nSpinster),Bachelor[0]);
 		}
 		// Refresh
 		Bachelor.erase(Bachelor.begin(),Bachelor.begin() + nBachelor);
 		Spinster.erase(Spinster.begin(),Spinster.begin() + nSpinster);
 		
 		counter++;
 	}
 	
 	return 0;
 }
