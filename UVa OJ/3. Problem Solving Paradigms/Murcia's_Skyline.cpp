#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define pb push_back
#define REP(a,n) for((a) = 0; a < (n); (a)++)

typedef vector<int> vi;

vi HeightData,WidthData,M1,M2;

int LIS(int val)
 {
 	int aw,ak,pivot;
 	
 	aw = 0;
 	ak = M1.size();
 	
 	while(aw < ak)
 	{
 		pivot = (aw + ak) / 2;
 		
 		if(HeightData[M1[pivot]] < val) aw = pivot + 1;
 		else ak = pivot;
 	}
 	
 	return aw;
 }

int LDS (int val)
  {
  	int aw,ak,pivot;
 	
 	aw = 0;
 	ak = M2.size();
 	
 	while(aw < ak)
 	{
 		pivot = (aw + ak) / 2;
 		
 		if(HeightData[M2[pivot]] > val) aw = pivot + 1;
 		else ak = pivot;
 	}
 	
 	return aw; 	
  }

void Refresh()
 {
 	HeightData.erase(HeightData.begin(), HeightData.end());
 	WidthData.erase(WidthData.begin(), WidthData.end());
 	M1.erase(M1.begin(), M1.end());
 	M2.erase(M2.begin(), M2.end());
 	
 }

int main()
 {
 	int TC,n,a;
 	int temp,MaxLis,MaxLds;
 	int index,counter = 1;
 	scanf("%d",&TC);
 	while(TC--)
 	{
 		MaxLis = MaxLds = 0;
 		scanf("%d",&n);
 		int Sum1[n+5],Sum2[n+5];
 		
 		// Input Height
		REP(a,n)
		{
			scanf("%d",&temp);
			HeightData.pb(temp);
			
			// Set 0
			Sum1[a] = Sum2[a] = 0;
		}
		
		// Input width
		REP(a,n)
		{
			scanf("%d",&temp);
			WidthData.pb(temp);
		}
		
		// Processing
		REP(a,n)
		{
			// for LIS
			if(WidthData[a] < 0) continue;              // if width negative, ignore
			
			index = LIS(HeightData[a]);
			if(index == M1.size()) M1.pb(a);
			else M1[index] = a;
	
			if(index == 0)
			{
				// Jika lebih besar ganti
				if(WidthData[a] >= Sum1[0]) Sum1[0] = WidthData[a];
			}	 		
			else 
			{
				if(Sum1[index] < Sum1[index-1] + WidthData[a]) Sum1[index] = Sum1[index-1] + WidthData[a];	
			}
			
			MaxLis = max(MaxLis,Sum1[index]);
			MaxLis = max(MaxLis,WidthData[a]);
			
			// for LDS
			index = LDS(HeightData[a]);
			if(index == M2.size()) M2.pb(a);
			else M2[index] = a;
			
			if(index == 0)	
			{
				if(WidthData[a] >= Sum2[0]) Sum2[0] = WidthData[a];
			}
			else
			{
				if(Sum2[index] < Sum2[index-1] + WidthData[a]) Sum2[index] = Sum2[index-1] + WidthData[a];
			}  
			
			MaxLds = max(MaxLds,Sum2[index]);  
			MaxLds = max(MaxLds,WidthData[a]);
			
		}
		
		// Debugging
		printf("\n-----Sum yang ada di M1---\n");
		REP(a,M1.size())
		{
			printf("Sum1[%d] : %d\n",a,Sum1[a]);
		}
		
		printf("\n-----Sum yang ada di M2---\n");
		
		REP(a,M2.size())
		{
			printf("Sum2[%d] : %d\n",a,Sum2[a]);
		}
		
	
		
		// Print and Refresh
		if(MaxLis >= MaxLds) printf("Case %d. Increasing (%d). Decreasing (%d).\n",counter,MaxLis,MaxLds);
		else printf("Case %d. Decreasing (%d). Increasing (%d).\n",counter,MaxLds,MaxLis);
		
		Refresh();	
		counter++;
 	}
	 	
 	return 0;
 }
