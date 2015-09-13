#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n,k;
	vector<int> Data;
	scanf("%d %d",&n,&k);
	
	int a;
	for(a = 0; a < n; a++)
	{
		int temp;
		scanf("%d",&temp);
		Data.push_back(temp);
	}
	
	sort(Data.begin(), Data.end());
	
	//int nAdvance = 0;
	int nRank = 0;
	int valK = 0;
	
	for(int b = n-1; b >= 0; b--)
	{
		if(Data[b] > 0)
		{
			if(valK != 0 && valK != Data[b])	
			{
				printf("%d\n",nRank);
				return 0;
			}
			
			nRank++;
		} 
		if(nRank == k)
		{
			valK = Data[b];
		}
	}
	
	printf("%d\n",nRank);
				
	return 0;
}
