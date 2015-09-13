#include<stdio.h>

int main()
  {
  	int TC;
  	scanf("%d",&TC);
  	
  	int sum,difference;
  	
  	int looseScore,winScore;
	int a;
	for(a = 0; a < TC; a++)
	   {
	   	scanf("%d %d",&sum,&difference);
	    looseScore = 0;
	    winScore = difference;
	    
	    if(difference > sum)
	      {
	      	printf("usil\n");
	      	continue;
	      }
	    
		else if(difference == sum)
	      {
	      	printf("%d %d\n",winScore,looseScore);
	      	continue;
	      }
	    
	    else if(sum - difference == sum)
	      {
	      	printf("%d %d\n",sum,looseScore);
	      	continue;
	      }
	    
		else
	      {
		    while(winScore + looseScore != sum && winScore + looseScore < sum)
		      {
		      	winScore++;
		      	looseScore++;
			  }
			  
			  if(winScore + looseScore != sum)
			   {
			   	printf("usil\n");
			    continue;
			   }
			  else
			  { 
			   printf("%d %d\n",winScore,looseScore);
		  	  }
		  }
	   }
  	return 0;
  }
