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

int TC,D,Q,n,temp,temp2;
string maker; 
 
// Vector String dan Pair int,int
vector <pair<string, pii> > Data;
pii tempData;

int que[1005],a,b,j;

int main()
 {
 	
 	int counter,pos;
 	scanf("%d",&TC);
 	for(j = 1; j<= TC; j++)
 	{
 		if(j != 1) printf("\n");
 		scanf("%d",&D);	
		REP(a,D)
 	 	{
 	 	  maker = GetString();
		  scanf("%d %d",&temp,&temp2);
 	 	  tempData = mp(temp,temp2);
		  Data.pb(mp(maker,tempData));
 	 	}
 	 	
 	 	// Ambil Queries
 	 	scanf("%d",&Q);
 	 	
		REP(a,Q)
		{
			scanf("%d",&que[a]);
		}
 	 	
 	 	REP(a,Q)
		{
			counter = 0;
			REP(b,D)
			{
				/* Debugging */
				//printf("Que[%d] : %d\n",a,que[a]);
				//printf("Data[%d].second.first : %d\n",b,Data[b].second.first);
				//printf("Data[%d].second.second : %d",b,Data[b].second.second);
				if(que[a] <= Data[b].second.second && que[a] >= Data[b].second.first)
				{
					/* Debugging
					printf("MASUK!\n");
					printf("Que[%d] : %d\n",a,que[a]);
					printf("Data[%d].second.first : %d\n",b,Data[b].second.first);
					printf("Data[%d].second.second : %d",b,Data[b].second.second);
					*/
					counter++;
					
					if(counter > 1 ) break;
					pos = b;
				}
			}
			
			//printf("Counter[%d] : %d\n",a,counter);
			
			if(counter == 1) printf("%s\n",Data[pos].first.c_str());
			else printf("UNDETERMINED\n");
		}
		 Data.erase (Data.begin(),Data.begin()+D);
 	}
 	
 	return 0;
 }
