#include<cstdio>
#include<cmath>

using namespace std;

int TC;
int nilai;
int main()
 {
 	scanf("%d",&TC);
 	while(TC--)
 	{
 	 scanf("%d",&nilai);
 	 nilai = (((nilai * 63) + 7492) * 5) - 498;
 	 nilai = abs((nilai % 100) / 10);
 	 printf("%d\n",nilai);
 	}
 	
 	return 0;
 }
