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
#define mp make_pair

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

typedef unsigned long long ULL;

int TC;

int main()
 {
 	int a,frek,wave;
 	int b,c,d;
	scanf("%d",&TC);
 	
 	REP(a,TC)
 	{
 		scanf("\n");
 		
 		scanf("%d %d",&wave,&frek);
 		
 		REP(d,frek)
 		{
 		
			 // Top
 			for(b = 1; b <= wave; b++)
 			{
 				for(c = 1; c<=b; c++)
 				{
 					printf("%d",b);
 				}
 			
				 printf("\n");
 			}
 			
 			// Down
 			for(b = wave-1; b >= 1 ;b--)
 			{
 				for(c = 1; c<=b; c++)
 				{
 					printf("%d",b);
 				}
 				
				 printf("\n");
 			}
 			
			 if(d != frek-1) printf("\n");
 		}
 		if(a != TC-1) printf("\n");
 	}
	return 0;
 }
