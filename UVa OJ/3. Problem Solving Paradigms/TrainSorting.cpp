#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

#define PB push_back
#define REP(i,n) for((i) = 0; i < (n); i++)

using namespace std;

vector <int> Data;

void Refresh()
 {
 	Data.erase(Data.begin(), Data.end());
	//Lup.erase(Lup.begin(), Lup.end());
	//Ldown.erase(Ldown.begin(), Ldown.end());
 }

int main()
 {
 	int a,b;
 	int TC,n,temp,sum;
	scanf("%d",&TC);
 	
 	while(TC--)
 	{
 		int max = 0;
 		int Lup[2005], Ldown[2005];
 		scanf("%d",&n);
 		REP(a,n)
 		{
 			scanf("%d",&temp);
 			Data.PB(temp);
 			//Lup.PB(1);
 			//Ldown.PB(1);
 			Lup[a] = Ldown[a] = 1;
 		}
 	
 		for(a = n-1; a >= 0; a--)
 		{
 			for(b = a+1; b < n; b++)
 			{
 				// Kondisi untuk Lup
 				if(Data[b] > Data[a] && Lup[b] + 1 > Lup[a])
 				{
 					Lup[a] = Lup[b] + 1;
 				}
 				
 				// Kondisi untuk Ldown
 				else if(Data[b] < Data[a] && Ldown[b] + 1 > Ldown[a])
 				{
 					Ldown[a] = Ldown[b] + 1;
 				}
 			}
 			
 			sum = (Lup[a] + Ldown[a]) - 1;
 			//printf("SUM[%d] : %d\n",a,sum);
 			if(sum > max) max = sum;
 		}
 		
 		printf("%d\n",max);
 		
 		Refresh();
 	}

 	return 0;
 }
