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

int main()
 {
 	int n,temp,a;;
 	while(1)
 	{
 		scanf("%d",&n);
 		if(!n) break;
 		
 		// Separator
 		
		// Jika tidak 0, mulai streak 
		while(1)
 		{
 			vi data;
 			scanf("%d",&temp);
 			if(!temp)
			 {
			 	printf("\n");
			 	break;	
			 } 
 			
			data.pb(temp);
				
 			for(a = 1; a < n; a++) 
			{
				scanf("%d",&temp);
				data.pb(temp);	
			}
				 
			// Processing lies here
			int currentCoach = 1, targetData = 0;
			stack <int> S;
				 
			while(currentCoach <= n)
			{
				S.push(currentCoach);
				 	
				while(!S.empty() && S.top() == data[targetData])
				{
				 	S.pop();
				 	targetData++;
				}
				 	
				currentCoach++;
			}
				 
			// Keputusan
			if(!S.empty()) printf("No\n");
			else printf("Yes\n"); 
 		}
 	}
 
	return 0;
 }
