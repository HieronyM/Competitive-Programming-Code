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

int Data[10],a;
vector <string> binPack;

string str;
int main()
 {
 	int pos;
 	unsigned long long nilaiTerkecil,mini[6];

 	while(scanf("%d %d %d %d %d %d %d %d %d",&Data[0],&Data[1],&Data[2],&Data[3],&Data[4],&Data[5],&Data[6],&Data[7],&Data[8]) != EOF)
 	{
 		nilaiTerkecil = 20000000000;
 		// GCB - GBC - CGB - CBG - BCG - BGC
 		// 5 - 4 - 3 - 2 - 1 - 0
 		
 		//printf("Masuk\n");
 		
 		// GCB
 		mini[5] = Data[0] + Data[2] + Data[3] + Data[4] + Data[7] + Data[8]; 
 	    binPack.pb("GCB");
 	    
 	    // GBC
 	    mini[4] = Data[0] + Data[2] + Data[4] + Data[5] + Data[6] + Data[7];  
 	    binPack.pb("GBC");
 	   
		 // CGB
 	    mini[3] = Data[0] + Data[1] + Data[3] + Data[5] + Data[7] + Data[8]; 
 	    binPack.pb("CGB");
 	    
		// CBG
 	    mini[2] = Data[0] + Data[1] + Data[4] + Data[5] + Data[6] + Data[8];  
 	    binPack.pb("CBG");
 	    
		// BGC
 	    mini[1] = Data[1] + Data[2] + Data[3] + Data[5] + Data[6] + Data[7];  
 	    binPack.pb("BGC");
 	       
 	    // BCG
 	    mini[0] = Data[1] + Data[2] + Data[3] + Data[4] + Data[6] + Data[8];  
 	    binPack.pb("BCG");
 	       
 	     //  printf("Masuk 2\n");
 	    //pos = 6;
		sort(binPack.begin(), binPack.end());
		//Debugging
		/*REP(a,6)
		{
			printf("%s : %d\n",binPack[a].c_str(),mini[a]);
		}
		*/
		
		for(a = 5; a >= 0; a--) 
		 {
		 	
		 	if(nilaiTerkecil >= mini[a])
		 	{
		 		//printf("Masuk di [%d] !\n",a);
		 		nilaiTerkecil = min(nilaiTerkecil, mini[a]);
		 		str = binPack[a];
		 	}
		 }
		 
		 //printf("Pos : %d\n",pos);
		 // Cetak hasil
		 printf("%s %d\n",str.c_str(),nilaiTerkecil);
		 binPack.erase (binPack.begin(),binPack.end());
	}
 	return 0;
 }
