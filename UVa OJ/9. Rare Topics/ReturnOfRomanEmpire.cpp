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
#include <set>
#include <bitset>

using namespace std;

typedef unsigned long long ULL;
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
typedef map <int,int> mii;

double PI = acos(-1);

#define REP(i,n) for(int (i) = 0; (i) < (int)(n); (i)++)
#define READ_int(data) scanf("%d",&data); 
#define RESET(c,v) memset(c, v, sizeof(c))
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define pb push_back
#define mp make_pair
#define ALL(vec) vec.begin(),vec.end()
#define sI(val) scanf("%d",&val)
#define sID(val,val2) scanf("%d %d",&val,&val2)
#define INF 2123123123

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


// FPB gan
int gcd(int  a, int b){
	if(b == 0)return a;
    else return gcd(b,a%b);
}

bitset<10000010> bs;
vi primes;

// Prima pertama terdapat di primes[1] yah :D
void sieve(LL upperbound){
	bs.set();
	bs[0]=bs[1]=0;
	primes.pb(0);
	for(LL i=2; i<=upperbound+1; i++)if(bs[i]){
	for(LL j=i*i; j<= upperbound+1; j+=i)bs[j] = 0;
			primes.pb((int) i);
	}
}

// Roman Numberal
int th,h,t,o;
string thousands[] = {"", "M", "MM", "MMM", "MMMM"};
string hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

int roman2decimal(string roman) //assume roman is uppercase
{
   int result = 0;
   int LEN = roman.length();

   for (int i = 0; i < LEN; ++i)
   {
      if (roman[i] == 'I' && i != LEN-1)
      {
         if      (roman[i+1] == 'V') { result +=    4; ++i; } //IV leap V char
         else if (roman[i+1] == 'X') { result +=    9; ++i; } //IX leap X char
         else                        { result +=    1;      }
      }
      else if (roman[i] == 'X' && i != LEN-1)
      {
         if      (roman[i+1] == 'L') { result +=   40; ++i; } //XL leap L char
         else if (roman[i+1] == 'C') { result +=   90; ++i; } //XC leap C char
         else                        { result +=   10;      }
      }
      else if (roman[i] == 'C' && i != LEN-1)
      {
         if      (roman[i+1] == 'D') { result +=  400; ++i; } //CD leap D char
         else if (roman[i+1] == 'M') { result +=  900; ++i; } //CM leap M char
         else                        { result +=  100;      }
      }
      else if (roman[i] == 'I')      { result +=    1; }
      else if (roman[i] == 'V')      { result +=    5; }
      else if (roman[i] == 'X')      { result +=   10; }
      else if (roman[i] == 'L')      { result +=   50; }
      else if (roman[i] == 'C')      { result +=  100; }
      else if (roman[i] == 'D')      { result +=  500; }
      else if (roman[i] == 'M')      { result += 1000; }
   }
   return result;
}

string intToRoman(int j)
{
	int tempJ = j;
	string romanNumber = "";
	th = tempJ / 1000;
	tempJ = tempJ % 1000;
	h = tempJ / 100;
	tempJ = tempJ % 100;
	t = tempJ / 10;
	tempJ = tempJ % 10;
		
	o = tempJ % 10;
	romanNumber = romanNumber + thousands[th] + hundreds[h] + tens[t]  + ones[o];
	
	//printf("%s\n",romanNumber.c_str());
	return romanNumber;
}

int main()
{
	string input;
	char y[1000005];
	while(scanf("%s",&y) == 1)
	{
		input = y;
		
		int hasil = roman2decimal(input);
		if(hasil > 4000) printf("This is not a valid number\n");
		else
		{
			string hasil2 = intToRoman(hasil);	
			if(input == hasil2) printf("%d\n",hasil);
			else printf("This is not a valid number\n");
		}
	}
	return 0;
}
