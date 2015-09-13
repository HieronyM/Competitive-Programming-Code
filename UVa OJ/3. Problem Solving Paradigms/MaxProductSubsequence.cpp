#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

typedef long long int LL;
using namespace std;

LL prod[105][105];		// Banyak State DP
vector <LL> Data;

int main()
 {
 	int a,b;
 	LL temp,maxi;
 	while(scanf("%lld",&temp) == 1)
 	{
 		if(temp != -999999)  Data.push_back(temp);
 		
		 if(temp == -999999)
 		{
 		// Set di awal	
		 maxi = Data[0] * Data[1];
		 
		 // Debug
			//printf("Size : %d\n",Data.size());
		 
		 // Kondisi hanya ada 1
		 if(Data.size() == 1) 
		 {
		 	printf("%lld\n",Data[0]);
		 	Data.erase(Data.begin(), Data.end());
		 }
		 
		 else
		 {
		 // Loop
		  for(a = 0; a < (Data.size()-1); a++ )
		  {
		  	for(b = a+1; b < Data.size(); b++)
		  	{
		  		// First 
		  		if(b == a + 1)
		  		{
		  			prod[a][b] = Data[a] * Data[b];
		  			maxi = max(maxi, prod[a][b]);
		  		}
		  		
		  		// !First
		  		else
		  		{
		  			prod[a][b] = prod[a][b-1] * Data[b];
		  			maxi = max(maxi,prod[a][b]);
		  		}
		  	}
		  }
		  
		  printf("%lld\n",maxi);
		  
		  // Refresh
		  Data.erase(Data.begin(), Data.end());
 		}
 	  }
 	}
 	return 0;
 }
