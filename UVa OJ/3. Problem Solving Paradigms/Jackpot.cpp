#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

int cek()

vector <int> Data;
int n,a,temp;
int main()
 {
 	while(1)
 	{
 		scanf("%d",&n);
 		for(a = 0; a < n; a++)
 		{
 			scanf("%d",&temp);
 			Data.push_back(temp);
 		}
 		
 		
 		Data.erase(Data.begin(), Data.end());
 	}
 	
 	return 0;
 }
