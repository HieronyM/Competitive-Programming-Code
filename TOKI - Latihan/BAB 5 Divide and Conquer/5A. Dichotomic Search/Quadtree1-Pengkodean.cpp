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

int R,C;
int j,k;
int Data[132][132];
vstr hasil;
string temp = "0";

int cekSame(int Rawal, int Rakhir, int Cawal, int Cakhir)
  {
  	int val = Data[Rawal][Cawal];
  	int f,g;
  	for(f = Rawal; f < Rakhir; f++)
  	{
  		for(g = Cawal; g < Cakhir; g++)
  		{
  			//printf("val : %d Data[%d][%d] : %d\n",val,f,g,Data[f][g]);
  			if(val != Data[f][g])
  			{
  			//	printf("Masuk di return 0 cekSame\n");
  				return 0;
  			}
  		}
  	}
  	return 1;
  }

void searchYok(int Rawal, int Rakhir, int Cawal, int Cakhir, char kar)
 {
 	int nKotak = (Rakhir - Rawal) * (Cakhir - Cawal);
 	//string temp = "0";
 	temp += kar;
 			
 	//printf("nKotak : %d\n",nKotak);
 	if(cekSame(Rawal,Rakhir,Cawal,Cakhir))
 	{
 	//	printf("Masuk di CekSame\n");
 		if(Data[Rawal][Cawal] == 1) 
 		{
 			temp[0] = '1';   // Penanda
 			hasil.push_back(temp);
	 	} 
 	}
 	
 	else if(!cekSame(Rawal,Rakhir,Cawal,Cakhir) && nKotak == 4)
 	{
 	//	printf("Masuk di else if\n");
 		int y,z,count = 0;
 		for(y = Rawal; y < Rakhir; y++)
 		{
 			for(z = Cawal; z < Cakhir; z++)
 			{			
 				// Jika bernilai 1
				if(Data[y][z] == 1)
 				{
 					if(count == 0) temp += '0';
					else if(count == 1) temp += '1';
					else if(count == 2) temp += '2';
					else if(count == 3) temp += '3';
					
					temp[0] = '1';
					hasil.push_back(temp);
					temp.erase(temp.end()-1, temp.end());
 				}
				count++;
 			}
 		}
 	}
 	
 	// Jika tidak sama
 	else
 	{
 	 // printf("Masuk di else\n");
 	  
 	  int tempA = ( Rakhir - ( (Rakhir-Rawal) / 2) );
 	  int tempB = ( Cakhir - ( (Cakhir-Cawal) / 2) );
 	  int tempC = ( Cawal + ( (Cakhir-Cawal) / 2) );
 	  int tempD = ( Rawal + ( (Rakhir-Rawal) / 2) );
 	  
 	  searchYok(Rawal, tempA, Cawal,tempB ,'0');	  // 0
 	  temp.erase(temp.end()-1, temp.end());
	  
	  searchYok(Rawal, tempA,tempC ,Cakhir,'1');	  // 1
 	  temp.erase(temp.end()-1, temp.end());
	  
	  searchYok(tempD , Rakhir, Cawal, tempB,'2');	  // 2
 	  temp.erase(temp.end()-1, temp.end());
	  
	  searchYok(tempD, Rakhir, tempC,Cakhir,'3');	  // 3
	  temp.erase(temp.end()-1, temp.end());
	}
 }

int main()
 {
 	int a = 4;
 	scanf("%d %d",&R,&C);
 	
 	// Memset
 	RESET(Data,0);
 	
 	// Tampung awal awal
 	REP(j,R)
 	{
 		REP(k,C)
 		{
 			scanf("%d",&Data[j][k]);
 		}
 	}
 	
 	// Ambil R dan C terkecil yang 2^X;
	while(R != C || R != a || C != a)
 	{
 		if(R < a ) R = a;
 		if(C < a) C = a;
 		
		if(a < C || a < R) a *= 2;
 	}
 	
 	//printf("R : %d C: %d\n",R,C);
 	
 	/* Debugging - Well Tested
 	//printf("R : %d C: %d\n",R,C);
	REP(j,R)
 	{
 		REP(k,C)
 		{
 			printf("Data[%d][%d] : %d ",j,k,Data[j][k]);
 		}
 		printf("\n");
 	}
 	*/
 	
 	// Cek apakah elemennya sama semua
 	//Jika semua Sama
 	if(cekSame(0,R,0,C))
 	{
 		if(Data[0][0] == 1) printf("1\nEND\n",Data[0][0]);
		else printf("END\n"); 
 	}
 	
 	// Jika ada berbeda
 	else
 	{
 		//printf("Masuk2!\n");
 		
 		// The Divide and Conquer lies here
 		searchYok(0,R/2,0,C/2,'0');  // 0
		temp = "0";
		searchYok(0,R/2,C/2,C,'1');  // 1
 		temp = "0";
		searchYok(R/2,R,0,C/2,'2');  // 2
 		temp = "0";
		searchYok(R/2,R,C/2,C,'3');  // 3
 		
 		sort(hasil.begin(), hasil.end());
 	
 		// Cetak Hasil
	 	for(a = 0; a < hasil.size(); a++)
	 	{
	 		printf("%s\n",hasil[a].c_str());
	 	}
	 	printf("END\n");
 	} 
 	
 	return 0;
 }
 	
