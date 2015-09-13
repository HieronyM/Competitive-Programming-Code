#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <cmath>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

#define pb push_back
#define REP(i,n) for(int(i) = 0; i < (n); i++)
#define sI(n) scanf("%d",&n);
#define ALL(vec) vec.begin(),vec.end()

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
typedef vector <int> vi;


int main()
 {
 	int TC;
 	scanf("%d",&TC);
 	getchar(); getchar();
 	
 	char name[3500];
 	
 	REP(a,TC)
 	{
 		map <string, int> countTree;
 		vstr pohon;
 		int counter = 0;
 		//scanf("\n");
 		while(gets(name))
 		{
			if(strlen(name) == 0) break;
			
			pohon.pb(string(name));
			countTree[string(name)]++;
			counter++;	
 		}
 		
 		sort(ALL(pohon));
 		string temp = "";
 		REP(b,pohon.size())
 		{
 			if(temp == pohon[b]) continue;
 			
 			else
 			{
 				temp = pohon[b];
 				//printf("countTree[%s] : %d\n",pohon[b].c_str(),countTree[pohon[b]]);
				double hasil = ((double) 100.0 * countTree[pohon[b]]) / (double)counter;
 				
				printf("%s %0.4lf\n",pohon[b].c_str(),hasil); 
 			}
		}
 		
 		if(a > 0)
		 {
		 	printf("\n");
		 } 
 	}
 		
	return 0;
 }
