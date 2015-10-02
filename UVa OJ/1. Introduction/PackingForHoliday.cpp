#include<cstdio>

int TC,a;
int l,h,w;
int main()
 {
 	scanf("%d",&TC);
 	for(a = 1; a <= TC; a++)
 	{
 		scanf("%d %d %d",&l,&w,&h);
 		
 		if(l > 20 || w > 20 | h > 20) printf("Case %d: bad\n",a);
 		else printf("Case %d: good\n",a);
  	}
 	return 0;
 }
