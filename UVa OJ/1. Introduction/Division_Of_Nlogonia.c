#include<cstdio>

using namespace std;
int main()
  {
  	int n,X,Y,X1,Y1;
  	int a,b;
  	//int r = 10000000;
  	
  	for(b = 1; b <= 10000000; b++)
  	{
  		scanf("%d",&n);
  		if(!n) break;
  		
  		scanf("%d %d",&X,&Y);
  		for(a = 1; a <=n; a++)
  		{
  			scanf("%d %d",&X1,&Y1);
  			
  			//printf("X : %d Y : %d || X1 : %d Y1 : %d \n",X,Y,X1,Y1);
  			// Divisa Condition
			if(X == X1 || Y == Y1) printf("divisa\n");
			
			else if(X < X1 && Y < Y1) printf("NE\n");
			else if(X < X1 && Y > Y1) printf("SE\n");
			else if(X > X1 && Y < Y1) printf("NO\n");
			else if(X > X1 && Y > Y1) printf("SO\n");
  		}
  	}
  	
  	return 0;
  }
