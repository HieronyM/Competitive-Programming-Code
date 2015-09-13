// Ideafuse Mikroskill
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

string kata;
int data[100];
int TC;

int total,a,cek;
string karakter1 = "abcdefghijklmnotuv";
string karakter2 = "pqrswxyz";

int hitungKetik(char dicari)
 {
 	int counter = 0;
 	REP(a, 18)
 	{
 		if(dicari == karakter1[a])
 		{
 			cek = 0;
 			return counter;
 		}
 		counter++;
 	}
 	
 	counter = 0;
 	REP(a, 8)
 	{
		if(dicari == karakter2[a])
 		{
 			cek = 1;
 			return counter;
 		}
 		counter++;
	}
 }

int main()
 {
 	int c = 1,b,temp;
 	scanf("%d",&TC);
	while(TC--)
	{
		total = 0;
		
		if(c == 1) getline(cin,kata);
 		
		getline(cin,kata);
		b = 0;
		while(kata[b] != '\0')
		{
			//if(kata == "\n") break;
			
			if(kata[b] == ' ')
			{
				b++;
				total++;
				//printf("MASUK\n");
				continue;
			}
			
			temp = hitungKetik(kata[b]);
			//printf("---a : %d = %d---\n",a,temp);
			
			if(cek == 0) total = total + (( temp % 3) + 1 );
			else if(cek == 1) total = total + (( temp % 4) + 1 );
			b++;
			//printf("Total : %d\n",total);
		}
		printf("Case #%d: %d\n",c,total);
		c++;
	} 	
 	return 0;
 }
 
