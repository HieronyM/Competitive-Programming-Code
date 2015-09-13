#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define REP(i,n) for((i) = 0; i < (n); i++)

typedef unsigned long long ull;

vector <int> M;
void initializeType()
 {
 	M.pb(1);
 	M.pb(5);
 	M.pb(10);
 	M.pb(25);
 	M.pb(50);
 }

ull count(int n, int m)
 {
 	int i,j;
	ull x,y;
 	
 	// Initialize table - Bottom Up
 	ull table[n+1][m];
 	
 	for(i = 0; i <= n; i++)
 	{
 		for(j = 0; j < m; j++)
 		{
 			// If we change 0, the choice is just 1.
 			if(i == 0) table[i][j] = 1;
 			
 			if(j == 0) table[i][j] = 1;
 			
 			else
 			{
 				// Number of ways if including m[j]
 				x = (i - M[j] >= 0) ? table[i-M[j]][j] : 0;
 				
 				// Number of ways if Excluding m[j]
 				y = (j >= 1) ?  table[i][j-1] : 0;
 				
 				table[i][j] = x + y;
 			}
 		}
 	}
 	
 	return table[n][m-1];
 }
int main()
 {
 	int n;
  	initializeType();
  
  	while(scanf("%d",&n) != EOF)
  	{
  		ull hasil = count(n,5);
  		
  		if(hasil == 1) printf("There is only 1 way to produce %d cents change.\n",n);
  		else printf("There are %llu ways to produce %d cents change.\n",hasil,n);
  	}
 	return 0;
 }
