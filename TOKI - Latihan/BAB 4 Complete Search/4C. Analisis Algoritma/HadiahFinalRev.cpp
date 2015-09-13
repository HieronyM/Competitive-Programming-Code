#include <cstdio>
#include <algorithm>
using namespace std;

long long int hadiahSet[100000],total,Data[100000];

int main()
 {
 	int N,M;
 	scanf("%d %d",&N,&M);
 	
 	int a,count=0;
 	for(a = 0; a < N; a++)
 	 {
 	 	scanf("%lld",&Data[a]);  
 	 }
 	 
 	 total = 0;
 	for(a = 0; a < N; a++)
 	 { 
 	 	total += Data[a];
 	 	if(a == M-1)
 	 	  {
 	 	  	hadiahSet[count] = total;
 	 	  	count++;
 	 	  }
 	 	else if(a > M-1)
		  {
		  	hadiahSet[count] = total - Data[(count -1)];
			total = hadiahSet[count]; 
		  	count++;
		  }
 	 }
	  
	  sort(hadiahSet,hadiahSet+count); 	 
 	 // Debug
	  /*for(a = 0; a < count; a++)
 	 { 
 	   printf("hadiah[%d] : %lld\n",a,hadiahSet[a]);
 	  }
 	  */
 	    
 	  // print max
	 printf("%lld\n",hadiahSet[count-1]);
	  
	  return 0; 
 }
