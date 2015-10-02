#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

#define REP(a,n) for((a) = 0; (a) < n; a++) 
#define pb push_back
//char pattern[105][105];
vector <string> pattern;
int TC;
int n;

inline string GetString(void){
	char x[1000005];
	scanf("%s",x); string s = x;
	return s;
}

void floodFill(int row,int column)
 {
 	int j;
 	int tempX,tempY;
 	
	 int x[4] = {-1,0,1,0};   // Column
 	int y[4] = {0,-1,0,1};   // Row	
 	pattern[row][column] = '-';  // "-" Set as visited

		// Cek Atas,Bawah,Kiri,Kanan 
		REP(j,4)
		{
			tempY = row + y[j];
			tempX = column + x[j];
		
			if(tempX < 0 || tempY < 0 || tempX >= n || tempY >= n) continue;
		
			else if(pattern[tempY] [tempX] == 'x' || pattern[tempY] [tempX] == '@')  floodFill( tempY , tempX );
		}
 }

int main()
 {
 	int a,b,c,nAlive;
 	scanf("%d",&TC);
 	
 	REP(a,TC)
 	{
 		nAlive = 0;
 		//scanf("%d",&n);
 		
		scanf("%d",&n);
 		
 		// Input
		REP(b,n)
 		{
 			pattern.pb(GetString());
 		}
 		
 		/* Debugging  -- Correct
 		printf("\n");
 		REP(b,n)
 		{
 			printf("%s\n",pattern[b].c_str());
 		}
 		printf("\n");
 		*/
 		
 		// Processing
 		REP(b,n)
 		{
 			REP(c,n)
 			{
 				if(pattern[b][c] == 'x') 
				 {
				 	nAlive++;
 					//printf("FloodFill di Pattern[%d][%d]\n",b,c);
					floodFill(b,c);
				 }
 			}
 		}
 		
 		// Cetak & clear
 		printf("Case %d: %d\n",a+1,nAlive);	  
		pattern.clear();
 	}
 	
 	return 0;
 }

