#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

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

int R,C;
int Grid[1005][1005];

int BFS(int startX,int startY,int DesX,int DesY)
 {
 	int layer = 0,status = 0,size;
 	int tempX,tempY;
 	int j;
 	pair <int,int> temp;					// Temporary
 	queue < pair <int,int> > Q;
 	Q.push( make_pair(startX,startY) );
 	
 	// Set As Visited
 	Grid[startX][startY] = 2;
 	if(startX != DesX || startY != DesY)
 	{
 		while(!Q.empty())
		{
			layer++;						// Tambahkan layer
			size = Q.size();						
			for(j = 0; j < size; j++)
			{
				temp = Q.front();
				Q.pop();
					
				// Kiri
				tempX = temp.first;
				tempY = temp.second - 1;
			
				if(tempY >= 0)
				{
					// Cek jika sudah di Destination
					if(tempX == DesX && tempY == DesY)
					{
						status = 1;
						break;
					}
					
					// Masukkan ke Queue, jika !mine dan !visited yet
					if(Grid[tempX][tempY] == 0)
					{
						Q.push( make_pair(tempX,tempY));	
					} 
					
					Grid[tempX][tempY] = 2;
				}
			
				// Kanan
				tempX = temp.first;
				tempY = temp.second + 1;
			
				if(tempY < C)
				{
					// Cek jika sudah di Destination
					if(tempX == DesX && tempY == DesY)
					{
						status = 1;
						break;
					}
					
					// Masukkan ke Queue, jika ! mine dan !visited yet
					if(Grid[tempX][tempY] == 0)
					{
						Q.push( make_pair(tempX,tempY));	
					} 
					
					Grid[tempX][tempY] = 2;
				}
			
				// Atas
				tempX = temp.first - 1;
				tempY = temp.second;
			
				if(tempX >= 0)
				{
					// Cek jika sudah di Destination
					if(tempX == DesX && tempY == DesY)
					{
						status = 1;
						break;
					}
					
					// Masukkan ke Queue, jika !mine dan !visited yet
					if(Grid[tempX][tempY] == 0)
					{
						Q.push( make_pair(tempX,tempY));	
					} 
					Grid[tempX][tempY] = 2;
				}
			
				// Bawah
				tempX = temp.first + 1;
				tempY = temp.second;
			
				if(tempX < R)
				{
					// Cek jika sudah di Destination
					if(tempX == DesX && tempY == DesY)
					{
						status = 1;
						break;
					}
					
					// Masukkan ke Queue, jika !mine dan !visited yet
					if(Grid[tempX][tempY] == 0)
					{
						Q.push( make_pair(tempX,tempY));	
					} 
					Grid[tempX][tempY] = 2;
				}
			}
			
			if(status) break;
		}	
 	}	
 	return layer;
 }

int main()
 {
 	int nGridBomb;
 	int a,b,c;
 	while(1)
 	{
 		scanf("%d %d",&R,&C);
 		if(!R && !C) break;
 		scanf("%d",&nGridBomb);
 	
 		// Set jadi 0 (Manual Memset)
		REP(b,R+5)
		{
			REP(c,C+5) Grid[b][c] = 0;	// Set as no Mine
		}
 		
 		int RowNumber,nBomb,bombPos;
 		int startX,startY,DesX,DesY;
 		REP(b,nGridBomb)
 		{
 			scanf("%d %d",&RowNumber,&nBomb);
 		
 			// Scan the bomb pos
 			REP(c,nBomb)
 			{
 				scanf("%d",&bombPos);
 				
 				// Set the pos as has mine
 				Grid[RowNumber][bombPos] = 1;
 			}
 		}
 		
 		// Starting Point
 		scanf("%d %d",&startX,&startY);
 		
 		// Destination Point
 		scanf("%d %d",&DesX,&DesY);
 		
 		printf("%d\n",BFS(startX,startY,DesX,DesY));
 		
 		/* Debugging
 		REP(b,R)
		{
			REP(c,C) printf("%d ",Grid[b][c]);
			printf("\n");
		}
		*/
 	}
 	
 	return 0;
 }

