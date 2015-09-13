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

int main()
{
	int oxygen, w;
	int test;
	
	while(sID(oxygen,w) == 2)
	{
		vii data;
		int t;
		sI(t);
		
		// insert dummy (process from 1 in vector)
		data.pb(mp(0,0));
		
		int d,v;
		
		// Insert Item
		REP(b,t)
		{
			sID(d,v);
			data.pb(mp(d,v));
		}
		
		// Processing -- Knapsack Table & KeepTable
		int knTable[t + 5][oxygen + 5];
		int keepTable[t + 5][oxygen + 5];
		
		RESET(knTable,0);
		RESET(keepTable,0);
		
		//printf("Money : %d \t nItem : %d\n",money,nItem);
		// Knapsack Processing
		int stat;
		for(int i = 1; i <= t; i++)
		{
			//printf("masuk1\n");
			for(int j = 1; j <= oxygen; j++)
			{
				int temp;
				
				// Cost
				int des = w * data[i].first;				//  des time
				int asc = 2 * w * data[i].first;			// asc time
				
				// Jika bisa make barang yang di baris ke - i
				if(j - (des+asc) >= 0)
				{
					temp = knTable[i-1][ (j-(des+asc)) ];
					stat = 1;	
				}  
				else stat = 0;
				
				//printf("masuk2\n");
				if(stat == 0)
				{
					knTable[i][j] = knTable[i-1][j];				// Item tidak bisa dipakai, ambil yang dari knapsack table sebelumnya
					keepTable[i][j] = 0;							// Item tidak di-keep , set keep table 0
				}  				
							
				else
				{
					knTable[i][j] = max(knTable[i-1][j], (temp + data[i].second) );
					
					//printf("knTable[%d][%d] : %d\n",i,j,knTable[i][j]);
					//printf("knTable[%d][%d] : %d\n",i-1,j,knTable[i-1][j]);
					
					// Ambil dari yang atas,  item ga dikeep
					if(knTable[i][j] == knTable[i-1][j])
					{
					//	printf("Masuk\n");
						keepTable[i][j] = 0;	
					}
					
					// Item included
					else
					{
					//	printf("masuk2\n");
						keepTable[i][j] = 1;
					}  
					
					//printf("keepTable[%d][%d] : %d\n",i,j,keepTable[i][j]);
				} 
			//printf("masuk3\n");
			}
		}
		
		// Cek Knapsack Table --- <True>
		//printf("Cek Knapsack Table\n");
		/*
		REP(a,t+1)
		{
			REP(b,oxygen+1)
			{
				printf("%d ",knTable[a][b]);
			}
			
			printf("\n");
		}
		
		// Cek keep Table
		
		printf("Cek Keep Table\n");
		REP(a,t+1)
		{
			REP(b,oxygen+1)
			{
				printf("%d ",keepTable[a][b]);
			}
			
			printf("\n");
		}
		*/
		
		// Ambil Optimal Solusion di kolom terakhir. :D
		if ( test++ ) puts("");
		printf("%d\n",knTable[t][oxygen]);
		
		// Print Path
		int berat = oxygen;
		vi idxGet;
		
		for(int i = t; i >= 1; i--)
		{
			if(keepTable[i][berat] == 1)
			{
				idxGet.pb(i);
				berat = berat -  ( (2 * w * data[i].first) + (w * data[i].first) );			// asc time
			}
		}
		
		printf("%d\n",idxGet.size());
		for(int i = idxGet.size()-1; i>=0; i--) printf("%d %d\n",data[idxGet[i]].first,data[idxGet[i]].second);
	}
	
	return 0;
}
