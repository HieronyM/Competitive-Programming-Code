#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

#define REP(a,n) for((a) = 0; (a) < n; a++)
#define pb push_back
#define vi vector <int>

inline string GetString(void){
	char x[1000005];
	scanf("%s",x); string s = x;
	return s;
}

queue <int> l,r;
int TC;
 		
int main()
 {
 	int a,b;
 	int n,t,m;
 	int tempT;
 	string pos;
 	scanf("%d",&TC);
 	
 	int counter;
 	int timeNow,loadNow;
 	string ferryPos;
	REP(a,TC)
 	{
 		counter = 0;
 		ferryPos = "left";	// Initially is 0 (left)
 		timeNow = 0;	// Waktu Sekarang
 		loadNow = 0;	// Yang diload Ferry Sekarang
		scanf("%d %d %d",&n,&t,&m);
 		
 		// Input
		REP(b,m)
		{
			scanf("%d",&tempT);
			pos = GetString();
			
			if(pos == "left") l.push(tempT);
			else	r.push(tempT);
		} 		
		
		if(a!= 0) printf("\n");
		
		while(!l.empty() && !r.empty)
		{
			// Jika tidak Sesuai
			if(ferryPos != Data.front().second)
			{
				// Langsung Pindah aja
				if(timeNow >= Data.front().first) timeNow += t;
				
				else timeNow = Data.front().first + t;
				
				ferryPos = Data.front().second;	
			} 
			// Pengecekan yang dikiri
			while(!Data.empty() && timeNow >= Data.front().first && ferryPos == Data.front().second && loadNow < n ) 
			{
				loadNow++;
				Data.pop();
			}
			
			timeNow = timeNow + t;
			REP(b,loadNow)
			{
				printf("%d\n",timeNow);
			}
			
			loadNow = 0;
			
			// Ganti Posisi
			if(ferryPos == "left") ferryPos = "right";
			else ferryPos = "left";
		}
 	}
	return 0;
 }
