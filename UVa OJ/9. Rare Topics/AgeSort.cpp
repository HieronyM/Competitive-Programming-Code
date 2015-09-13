#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int n,a,temp;
vector <int> Data;

int main()
 {
 	while(1)
 	{
 		scanf("%d",&n);
		 if(!n) break;
		 for(a = 0; a < n; a++)
		 {
		 	scanf("%d",&temp);
		 	Data.push_back(temp);
		 }	
		 sort(Data.begin(), Data.end());
		 
		 for(a = 0; a < n; a++)
		 {
		 	if(a != n-1) printf("%d ",Data[a]);
		 	else printf("%d\n",Data[a]);
		 }
		 Data.erase(Data.begin(),Data.begin() + n);
 	} 
 	return 0;
 }
