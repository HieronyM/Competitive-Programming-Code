#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

#define pb push_back
#define REP(i,n) for(int(i) = 0; i < (n); i++)
#define sI(n) scanf("%d",&n);
#define ALL(vec) vec.begin(),vec.end()

typedef pair < int, int> pii;
typedef vector <int> vi;

int main()
 {
 	int n;
 	while(1)
 	{
		priority_queue <int> pq;
 		int cost = 0;
 		scanf("%d",&n);
 		if(!n) break;
 		
 		int temp;
 		REP(a,n)
 		{
 			scanf("%d",&temp);
 			pq.push(temp * -1);
 		}
 		
 		// Processing
 		int sum;
 		while(pq.size() > 1)
 		{
 			sum = (pq.top() * -1);
 			pq.pop();
 			sum += (pq.top() * -1);
 			pq.pop();
			
			//printf("Sum : %d\n",sum);
			pq.push((sum * -1));
			
			cost += sum;
 		}
 		
 		//printf("%d\n",pq.top());
 		printf("%d\n",cost);
 		
 	}
 	
	return 0;
 }
