#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

#define pb push_back
#define REP(i,n) for(int(i) = 0; i < (n); i++)
#define sI(n) scanf("%d",&n);
#define ALL(vec) vec.begin(),vec.end()

typedef pair < int, int> pii;
typedef vector <int> vi;
	
int difference;
int bil1,bil2;
	
int main()
 {
 	int n;
 	int temp,money;
	while(scanf("%d",&n) != EOF)
 	{
 		difference = INT_MAX;   // Initializing every TC
 		vi data;
 		
 		REP(a,n)
 		{	
 			sI(temp);
 			data.pb(temp);
 		}
 		
 		// Sort the vector
 		sort(ALL(data));
 		
 		scanf("%d",&money);
		
		vector<int>::iterator low;
		REP(a,n-1)
		{
			int val = money - data[a];
			if(binary_search( (data.begin() + a + 1), data.end(),val) )
			{
				low=lower_bound ( (data.begin() + a + 1), data.end(), val);
				if(difference > data[low-data.begin()] - data[a])
				{
					difference = data[low-data.begin()] - data[a];
					bil1 = data[a];
					bil2 = data[low-data.begin()];
				}
			}
		}
		printf("Peter should buy books whose prices are %d and %d.\n\n",bil1,bil2);
	}
 	
	return 0;
 }
