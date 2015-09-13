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
vstr Data;
int DataPattern[132][132];
string temp;
int R,C;
int v = 1; 
 
int Rawal, Rakhir,Cawal,Cakhir;
 
void refresh()
 {
    Rawal = 0;
    Rakhir = v;
    Cawal  = 0;
    Cakhir = v;
 }
 
void carilah(char kar)
 {
     int tempA = ( Rakhir - ( (Rakhir-Rawal) / 2) );
     int tempB = ( Cakhir - ( (Cakhir-Cawal) / 2) );
     int tempC = ( Cawal + ( (Cakhir-Cawal) / 2) );
     int tempD = ( Rawal + ( (Rakhir-Rawal) / 2) );
      
     if(kar == '0')
     {
        Rakhir = tempA;
        Cakhir = tempB;
     }  
     else if(kar == '1')
     {
        Rakhir = tempA;
        Cawal = tempC;
     }
     else if(kar == '2')
     {
        Rawal = tempD;
        Cakhir = tempB;
     }
     else if(kar == '3')
     {
        Rawal = tempD;
        Cawal = tempC;
     }
 }
 
void isi()
  {
    int j,k;
    for(j = Rawal; j < Rakhir; j++)
    {
        for(k = Cawal; k < Cakhir; k++)
        {
          DataPattern[j][k] = 1;    
        }
    }
  }
 
int main()
 {
    while(1)
    {
        temp = GetString();
        Data.pb(temp);
        if(temp == "END")
        {
            scanf("%d %d",&R,&C);
            break;
        }
    }
      
    RESET(DataPattern,0);
    string cada;
    
	while(R > v || C > v) v <<= 1; 
    if(Data[0] == "END") 
	{
		 for(int a = 0; a < R; a++)
     	{
        	for(int b = 0; b < C; b++)
        	{
            	if(b == C-1) printf("0\n");
            	else printf("0 ");
        	}
     	}		
	} 
    
    else
    {
		for(int a = 0; a < Data.size(); a++)
    	{
      		refresh();
      		if(Data[a] == "END") break;
      			for(int b = 1; b < Data[a].size(); b++)
      			{
        			// Store dulu, trus bawa ke prosedur carilah.
        			cada = Data[a];
        			carilah(cada[b]);
        			//printf("x1 : %d x2 : %d\n y1 : %d y2 : %d\n",Rawal,Rakhir,Cawal,Cakhir);
      			} 
     			
				 isi();
    	}
     
    	// Isi hasil Terakhir
    	for(int a = 0; a < R; a++)
     	{
        	for(int b = 0; b < C; b++)
        	{
            	if(b == C-1) printf("%d\n",DataPattern[a][b]);
            	else printf("%d ",DataPattern[a][b]);
        	}
     	}
	}
    return 0;
 }
