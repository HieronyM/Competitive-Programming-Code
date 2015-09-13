#include<stdio.h>

long long int data[100];

int main()
 {
 	long long int nilai,hasil=1;
 	scanf("%lld",&nilai);
 	
 	int count=0;
 	while(nilai != 0)
 	  {
 	  	if(hasil * 3 <= nilai)
 	  	  {
 	  	  	hasil *=3;
 	  	  	
 	  	  }
 	  	else
		   {
		   	data[count] = hasil;
 	  	  	nilai -= hasil;
 	  	  	count++;
 	  	  	hasil = 1;
		   }  
 	  }
 	
 	printf("%d\n",count);
 	
 	int a;
 	for(a = count-1; a >= 0; a--)
 	  {
 	  	// kondisi no space
 	  	if(a == 0)
 	  	{
 	  	  printf("%lld\n",data[a]);
 	  	}
 	  	else
 	  	{
 	  		printf("%lld ",data[a]);
 	  	}
 	  }
 	return 0;
 }
