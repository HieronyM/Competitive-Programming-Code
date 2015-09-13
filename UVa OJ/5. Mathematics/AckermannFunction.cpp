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


LL l,r,temp;
map <LL,LL> precompute;

long long tigaNtambah1 (long long nilai)
    {
           
    	if(nilai == 1)
        {
            return 1;
        }
             
		else if(nilai % 2 == 0)
        {
            return 1L + tigaNtambah1(nilai/2);
        }
        
		else
        {
        	return  1L + tigaNtambah1((nilai*3)+1);
        }   
    }

int main()
{
	while(1)
	{
		scanf("%lld %lld",&l,&r);
		
		LL idxMax = 1,maks = 0;
		if(!l && !r) break;
		
		// swap
		if(l > r)
		{
			temp = l;
			l = r;
			r = temp;
		}
		
		for(int a = l; a <= r; a++)
		{
			LL hasil;
			
			if(a == 1) hasil = 3;
			
			else
			{
				if(precompute[a] == 0) hasil = tigaNtambah1(a) - 1;
						
				else	hasil = precompute[a];
			}
			
			// Penentuan
			if(maks < hasil)
			{
				idxMax = a;
				maks = hasil;
			}
			
		}
		
		printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",l,r,idxMax,maks);
	}
	
	return 0;
}
