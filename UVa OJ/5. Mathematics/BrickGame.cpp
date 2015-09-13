#include<cstdio>

using namespace std;

#define REP(i,n) for((i) = 0; (i) < (int)(n); (i)++)

typedef int i;
i TC,a,b;
int nTeam,ageMember[11];

int main()
{
	scanf("%d",&TC);
	
	REP(a,TC)
	{
		scanf("%d",&nTeam);
		REP(b,nTeam)   scanf("%d",&ageMember[b]);
		
		//sort(ageMember, ageMember + nTeam);
		printf("Case %d: %d\n",a+1,ageMember[b/2]);
	}
	
	return 0;
}
