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
 
#define REP(i,n) for((i) = 0; (i) < (int)(n); (i)++)
#define READ_INT(data) scanf("%d",&data); 
#define RESET(c,v) memset(c, v, sizeof(c))
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define pb push_back
#define mp make_pair
#define ALL(j) j.begin(),j.end()
 
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
 
int R,C;
vstr data;

// Fungsi untuk mencek 1 line itu penuh
int cek(int row)
{
	int y,status = 0;
	
	for(y = 0; y < C; y++)
	{
		if(data[row][y] != '1')
		{
			status = 1;
			return 0;
		}
	}
	
	if(status == 0) 
	{
		return 1;	
	}
}

// prosedur untuk merubah semua nilai baris penuh menjadi 0
void ubah(int row)
{
	int z;
	
	for(z = 0; z < C; z++)
	{
		data[row][z] = '0';
	}
}

// Prosedur untuk menurunkan
void turun(int baris,int kolom)
{
	int j,k,l;
	
	for(j = baris; j < R-1; j++)
	{
		if(data[j+1][kolom] == '1') break;
		
		else if(data[j+1][kolom] == '0')
		{
			data[j][kolom] = '0';
			data[j+1][kolom] = '1';
		}
	}
}

int main()
 {
 	int a,b,ben = 0;
 	string temp;
	scanf("%d %d",&R,&C);
	
	// Input
	REP(a,R)
	{
		temp = GetString();
		data.pb(temp);
	}
	
	// Processing
	for(a = R-1; a >= 0; a--)
	{
		// Jika ada 1 line yang penuh lakukan perubahan
		if(cek(a))
		{
			if(ben == 0) ben = a;		
			ubah(a);
		}
	}
	
	// Lakukan operasi
	for(a = ben-1; a >= 0; a--)
	{
		for(b = 0; b < C; b++)
		{
			// Jika dia 1, lakukan operasi turun
			if(data[a][b] == '1')  turun(a,b);
		}
	}
	
	// Cek dlu
	//printf("\n ------Hasil----- \n");
	REP(a,R)
	{
		printf("%s\n",data[a].c_str());
	}
	
 	return 0;
 }
