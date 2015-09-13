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

vector <int> morning, evening;
int n,d,r;
int temp,temp3;

int main()
 {
 	
 	int a,total;
 	while(1)
 	{
 		total = 0;
 		scanf("%d %d %d",&n,&d,&r);
 		if(!n && !d && !r) break;
 		
 		else
 		{
 			// Untuk Morning
 			REP(a,n)
			 {
			 	scanf("%d",&temp);
 				morning.pb(temp);
			 }
			 
			// Untuk Evening
			REP(a,n)
			 {
			 	scanf("%d",&temp);
 				evening.pb(temp);
			 } 
			 
			 sort(morning.begin(), morning.begin() + n);	
 			 sort(evening.begin(), evening.begin() + n);
 			 
 			 // Debugging
 			 /*REP(a,n)
 			 {
 			 	printf("Morning[%d] : %d, Evening[%d] : %d\n",a,morning[a],a,evening[a]);
 			 }
 			 */
 			 
 			 REP(a,n)
 			 {
 			 	if( (morning[a] + evening[n-1-a]) > d )
 			 	{
 			 		// Debugging
 			 		/*temp3 = (morning[a] + evening[n-1-a]) -d;
					printf("Morning[%d] : %d, Evening[%d] : %d\n",a,morning[a],(n-1-a),evening[n-1-a]);
					printf("Terjadi di a : %d Temp3 : %d\n",a,temp3);
 			 		*/
					total += r * ((morning[a] + evening[n-1-a]) -d);
 			 	}
 			 }
 			 printf("%d\n",total);
		 }
 		
 		// Refresh
 		morning.erase(morning.begin(), morning.begin() + n);
 		evening.erase(evening.begin(), evening.begin() + n);
 		
 	}
 	
 	return 0;
 }
