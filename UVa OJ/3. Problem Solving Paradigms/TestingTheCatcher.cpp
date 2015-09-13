#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//typedef vector<int> vi;

#define pb push_back

vector<int> Data, LIS;

int bs(int val)
 {
	int aw,ak,pivot;
	
	aw = 0;
	ak = LIS.size();
	
	while(aw < ak)
	{
		pivot = (aw + ak) / 2;
		
		if(Data[LIS[pivot]] >= val) aw = pivot + 1;
		else ak = pivot;	
	}
	
	return ak;
 }

int main()
 {
 	int nomor = 0,nilai,index,TC = 1;
 	int a,b;
 	
 	while(1)
 	{
 		scanf("%d",&nilai);
 		
 		if(nilai == -1 && !nomor)
 		{
 			break;
 		}
 		
 		// Mulai cari LIS nya disini
 		else if(nilai == -1 && nomor)
 		{
 		
 			for(a = 0; a < Data.size(); a++)
 			{
 				index = bs(Data[a]);
 				if(index == LIS.size()) LIS.pb(a);
 				else LIS[index] = a;
 			}
 			
 			/* Debug
 			
 			printf("\n");
 			for(a = 0; a < LIS.size(); a++)
 			{
 				printf("%d ",LIS[a]);
 			}
 			*/
 			
 			// Jika Testcase pertama
 			if(TC == 1)
 			{
 				printf("Test #%d:\n",TC);
 				printf("  maximum possible interceptions: %d\n",LIS.size());	
 			}
 			else
 			{
 				printf("\nTest #%d:\n",TC);
 				printf("  maximum possible interceptions: %d\n",LIS.size());	
 			}
 			
 			TC++;
 			
 			// Refresh value
 			Data.erase(Data.begin(), Data.end());
 			LIS.erase(LIS.begin(), LIS.end());
 			nomor = 0;
 		}
 		
 		else
 		{
 		 Data.pb(nilai);
 		 nomor++;
 		}
 		
 	}
 	
 	return 0;
 }
