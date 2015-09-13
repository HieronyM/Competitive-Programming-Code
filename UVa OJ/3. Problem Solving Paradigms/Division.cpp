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

string generatePattern(string bil)
 {
 	int j;
 	int counter = 1;
	string s ("00000");
	
	if(bil.length() != 5)
	{
		for(j = 4; j > (4-bil.length()); j--)
		{
			s[j] = bil[bil.length()-counter];
			counter++;
		}	
		return s;
	}
	
	else return bil;
	
 }
 
 int berbeda(string bil1, string bil2)
  {
  	int j,status2 = 1;
	char digit[35] = "0123456789";
  	
	map<char, int> jlh;
  	
  	REP(j, 5)
  	{
  		jlh[bil1[j]]++;
  		jlh[bil2[j]]++;
  	}
  	
  	REP(j,10)
  	{
  		if(jlh[digit[j]] > 1)
  		{
  			status2 = 0;
  			return 0;
  		}
  	}
  	
  	if(status2) return 1;
  }

int main()
 {
 	int a,status,counter = 0,hasil,test = 0;
 	int number;
 	string pembilang,penyebut;
 	string hasilPembilang,hasilPenyebut;
	while(1)
	{
		status = 0;
		scanf("%d",&number);
		if(!number) break;
		
		else
		{
			if(counter) printf("\n");
			// Processing,  Batasan penyebutnya kita kecilkan 
			for(a = 1; a <= (98765 / number); a++)
			{
				//if(test == 10) break;
				hasil = a * number;
				pembilang = IntToString(hasil);	
				penyebut = IntToString(a);
				
				//printf("Pembilang : %s \t Penyebut : %s\n",pembilang.c_str() ,penyebut.c_str());
				
				hasilPembilang = generatePattern(pembilang);
				hasilPenyebut =  generatePattern(penyebut);
				
				//printf("hasilPembilang : %s \t hasilPenyebut : %s\n",hasilPembilang.c_str() ,hasilPenyebut.c_str());	
				
				if(berbeda(hasilPembilang,hasilPenyebut))
				{
					status = 1;
					printf("%s / %s = %d\n",hasilPembilang.c_str(),hasilPenyebut.c_str(),number);
				} 
				
				//test++;
			}
		}
			
		// Hasil
		
		// Separator untuk setiap kasus
		
		if(!status)
		{
			
				printf("There are no solutions for %d.\n",number);
		} 
		
		counter++;
		
	}
    
 	return 0;
 }
