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

ULL angka,desimal;
string l;

int hitung1(ULL angka)
{
	l = "";
	int temp = 0;
	while(angka > 0)
	{
		if(angka % 2 == 1)
		{
			l+='1';
			temp++;
		}
		
		else l+='0';
		angka /= 2;
	}
	
	return temp;
}

int main()
 {
 	int counter;
 	string kata;
 	while(1)
 	{
 		scanf("%llu",&angka);
 		if(!angka) break;
 		else
 		{
 			counter = hitung1(angka);
 			reverse(l.begin(),l.end());
 			printf("The parity of %s is %d (mod 2).\n",l.c_str(),counter);
 		}
 	}
 	
 	return 0;
 }
