#include<stdio.h>
#include<math.h>

int x[303],y[303],i,j,k,count =0;
long double min = 1000000000;

int main()
 {
 	int n;
 	scanf("%d",&n);
 	
 	int a;
 	long long d1,d2,luass;
	for(a = 1 ; a <= n; a++)
 	 {
 	 	scanf("%d %d",&x[a],&y[a]);
 	 }
 	
 	if(n < 3)printf("-1.00\n");
 	
 	else
 	{
 	for(i = 1; i <= n-2; i++)
 	   {
 	   	for(j = i + 1; j <= n-1; j++)
 	   	   {
 	   	   	for(k = j+1; k <= n; k++)
 	   	   	 {
 	   	   	 	//printf("%d %d %d\n",i,j,k);
 	   	   	 	//luass = hitungLuas(x[i], y[i], x[j], y[j], x[k], y[k]);
 	   	   	 	//abs((a * d + c * f + e * b - a * f - c * b - e* d));
 	   	   	 	d1 = (x[i]*y[j])+(x[j]*y[k])+(x[k]*y[i]);
 	   	   	 	d2 = (x[i]*y[k])+(x[j]*y[i])+(x[k]*y[j]);
 	   	   	 	luass = abs(d1-d2);
 	   	   	 	//printf("%lld\n",luass);
 	   	   	 	if(min == luass)
				  {
				  	count++;
				  }
 	   	   	 	
				if(min > luass)
 	   	   	 	  {
 	   	   	 	  	min = luass;
 	   	   	 	  	count = 0;
 	   	   	 	  }
				 //printf("Count di[%d][%d][%d] : %d\n",i,j,k,count);
				 //printf("Luas yang dapat : %.2f\n",luass);
				 //printf("Min saat ini : %.2f\n",min); 
				 	  
 	   	   	 }
 	   	   }
 	   }
 	
 	//printf("Count : %d\n",count);
 	
	if(count > 0)
 	  {
 	  	printf("-1.00\n");
 	  }
 	
	else
	  {
	   	printf("%.2lf\n",(double) min/2);
	   }
	}
 	return 0;
 }
