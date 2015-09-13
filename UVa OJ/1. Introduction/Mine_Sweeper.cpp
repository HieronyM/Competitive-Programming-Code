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

int TC,n,a,b,c;
pair <string,int> Data[100];
string str;
vector <string> pattern,click;

void cekMine(int idxY,int idxX)
 {
 	int counter = 0;
 	int tempX,tempY,c;
 	// Kiri - Atas - Kanan - Bawah - 
	// KiriAtas - KananAtas - KiriBawah - KananBawah
 	
	int x[8] = {-1,0,1,0,-1,1,-1,1};
 	int y[8] = {0,-1,0,1,-1,-1,1,1};
 	
 	for(c = 0; c < 8; c++)
	 {
	 	tempY = idxY + y[c];
		tempX = idxX + x[c];
		
		if(tempX < 0 || tempY < 0 || tempX >= n || tempY >= n) continue;
		
	 	else if(pattern[tempY][tempX] == '*') 
		 {
		 //	printf("Terjadi di titik (%d,%d)\n",tempY,tempX);
		 	counter++;	
		 }
	 }
	 
	 //printf("Terjadi di titik (%d,%d) -- Counter : %d\n",idxY,idxX,counter);
 	
	 click[idxY][idxX] = (char)(((int)'0')+counter);
 }

// Cari semua mine
void findMine()
 {
 	int d,e;
 	REP(d,n)
 	{
 		REP(e,n)
 		{
 			if(pattern[d][e] == '*') click[d][e] = '*';
 		}
 	}
 }

int main()
 {
 	scanf("%d",&TC);
 	int status;
 	
 	REP(c,TC)
 	{
 		if(c != 0) printf("\n");
 		status = 0;
 		// Refresh, Bersihkan
 		pattern.erase (pattern.begin(),pattern.end());
 		click.erase (click.begin(),click.end());
 		
 		// Nampung banyak inputan
 		
 		getline(cin,str);
 		scanf("%d",&n);
 		
 		// Pattern Mine
		REP(a, n)
 		{
 			pattern.pb(GetString());
 		}	
 		
 		// Pattern Titik yang ditekan
 		REP(a, n)
 		{
 			click.pb(GetString());
 		}
 		
 		// Mencari Output
 		REP(a, n)
 		{
 			REP(b,n)
 			{
 				if(click[a][b] != 'x') continue;
 				else 
				 {
				 	if(pattern[a][b]=='*') 
					 {
					 	click[a][b] = '*';
					 	findMine();        // Cari semua mine 
					 	status = 1;        // break
						continue;
					 }
				 	else cekMine(a,b);	
				 }
 			}
 		}
 		
 		// Print Hasil
 		REP(a, n)
 		{
 			printf("%s\n",click[a].c_str());
 		}
 	}
 	
 	return 0;
 }
