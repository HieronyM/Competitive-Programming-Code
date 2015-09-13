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

vii knights;
int n,m,a,b;
vi dragons;


void doGreedy()
 {
 	int cek;
 	LL total = 0;
 	// SOrt dlu
 	sort(dragons.begin(), dragons.end());
 	sort(knights.begin(), knights.end());
 	
 	REP(a,n)
 	{
 		cek = 0;
 		REP(b,m)
 		{
 			//printf("dragon : %d \n",dragons[a]);
 			
 			// Ga bisa dipake lagi
 			if(knights[b].second == 1) continue;
 			
 			if(knights[b].first >= dragons[a] )
 			{
 				//printf("KILL by : %d\n",knights[b].first);
 				cek = 1;
 				total += knights[b].first;
 				knights[b].second = 1;
 				break;
 			}
 		}
 		if(!cek)
 		{
 			break;
 		}
 	}
 	
 	if(!cek) printf("Loowater is doomed!\n");
 	else printf("%lld\n",total);
 }

int main()
{
	int temp1,temp2;
	while(scanf("%d %d",&n,&m) == 2)
	{		
	    
		if(!n && !m) break;
		
		// Ambil Inputan
		// Untuk dragons
		REP(a,n)
		{
		   scanf("%d",&temp1);
		   dragons.pb(temp1);
		} 
		
		// Untuk knights 
		REP(a,m) 
		{
		  scanf("%d",&temp2); 
		  knights.pb(make_pair( temp2 ,0)); 
		}
		
		// Jika jumlah knights lebih kecil
		if(m < n)
		{
			printf("Loowater is doomed!\n");
		}
		
		else
		{
			// Lakukan Greedy
			doGreedy();
		}
		
		// Bersihkan
		dragons.erase (dragons.begin(),dragons.begin()+n);
		knights.erase (knights.begin(),knights.begin()+m);
	}
	
	return 0;
}
