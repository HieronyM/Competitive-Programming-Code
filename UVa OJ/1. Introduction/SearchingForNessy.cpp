#include<cstdio>

int x,y,TC;

int main()
  {
  	scanf("%d",&TC);
  	while(TC--)
  	{
  		scanf("%d %d",&x,&y);
  		
  		// untuk x
  		if((x-2) % 3 == 0) x = ((x-2) /3);
  		else x =  ((x-2) /3) +1;
  		
  		// Untuk y
  		if((y-2) % 3 == 0) y = ((y-2) /3);
  		else y =  ((y-2) /3) +1;
  		
  		printf("%d\n",x*y);
   	}
   	return 0;
  }
