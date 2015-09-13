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

int main()
{
	int TC;
	int temp;
	int nBattleF,sG,sB;
	sI(TC);
	REP(a,TC)
	{
		priority_queue<int> pq1,pq2;
		scanf("%d %d %d",&nBattleF,&sG,&sB);
		
		// Green Lemmings
		REP(b,sG)
		{
			sI(temp);
			pq1.push(temp);
		}
		
		// Blue Lemmings
		REP(b,sB)
		{
			sI(temp);
			pq2.push(temp);
		}
		
		int L1,L2;
		
		// Cek Lemmings
		
		/*int s1 = pq1.size(),s2 = pq2.size();
		
		printf("------Green-----\n");
		REP(b,s1)
		{
			printf("%d\n",pq1.top());
			pq1.pop();
		}
		
		printf("------Blue-----\n");
		REP(b,s2)
		{
			printf("%d\n",pq2.top());
			pq2.pop();
		}
		*/
		
		// Processing
		
		queue <int> temp1,temp2;
		while(!pq1.empty() && !pq2.empty())
		{
			int bisa1 = 0;
			int bisa2 = 0;
			int minx;
			
			bisa1 = pq1.size();
			bisa2 = pq2.size();
			
			minx = min(bisa1,bisa2);
			
			if(minx > nBattleF) minx = nBattleF;
			
			REP(b,minx)
			{
				L1 = pq1.top();
				pq1.pop();
				
				L2 = pq2.top();
				pq2.pop();
				
				//printf("L1 : %d L2 : %d\n",L1,L2);
			
				// Store the green & Blue Lemmings
				if(L1 > L2) temp1.push( (L1-L2) );
				else if(L2 > L1) temp2.push( (L2-L1) );
			}
				
			// Store Again to P.queue	
			while(!temp1.empty())
			{
				pq1.push(temp1.front());
				temp1.pop();
			}
			
			while(!temp2.empty())
			{
				pq2.push(temp2.front());
				temp2.pop();
			}
		}
		
		
		// Separator
		if(a > 0) printf("\n");
		
		// Keputusan
		if(pq1.empty() && pq2.empty())
		{
			printf("green and blue died\n");
		}
		
		// Blue Lemmings wins
		else if(pq1.empty() && !pq2.empty())
		{
			printf("blue wins\n");
			
			int size = pq2.size();
			REP(b,size)
			{
				printf("%d\n",pq2.top());
				pq2.pop();
			}
		}
		
		// Green Lemmings wins
		else if(!pq1.empty() && pq2.empty())
		{
			printf("green wins\n");
			
			int size = pq1.size();
			REP(b,size)
			{
				printf("%d\n",pq1.top());
				pq1.pop();
			}
		}
	}
	
	return 0;
}
