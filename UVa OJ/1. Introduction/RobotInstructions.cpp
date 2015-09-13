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

int TC,n,a,b,pos;
string temp;
int idx;
vstr Data;

void sameAs(int row, int index)
{
	while(Data[row][0] != 'L' || Data[row][0] != 'R')
	{
		row = index - 1;
		if(Data[row][0] == 'L')
		{
			pos--;
			break;	
		}
		
	   else if(Data[row][0] == 'R')
	    {
	   	    pos++;
	   	    break;
	    }
	   
	    index = Data[row][8] - '0';
	}
}

int main()
 {
 	scanf("%d",&TC);
 	while(TC--)
 	{
 		// erase all elements:
        Data.erase (Data.begin(),Data.end());
 		
 		pos = 0;
 		scanf("%d",&n);
 		REP(a,n)
 		{
 			if(a == 0) getline(cin,temp);
 			getline(cin,temp);
 			
 			// Masukkan ke vector
			Data.pb(temp);
			
			// Debugging
			//cout << Data[a] << endl;
			if(Data[a][0] == 'L') pos--;
			else if(Data[a][0] == 'R')pos++; 
			
			// Jika sama
			else if(Data[a][0] == 'S')
			{
				idx = Data[a][8] - '0';
				
				// Debugging
				//printf("Index : %d\n",index);
				 
				if(Data[idx - 1][0] == 'L') pos--;
				else if(Data[idx - 1][0] == 'R') pos++;
				
				// Jika dapat Same As lagi
				else
				{
					sameAs(a,idx);
				}
			}
 		}
 		printf("%d\n",pos);
 	}
 	
 	return 0;
 }
