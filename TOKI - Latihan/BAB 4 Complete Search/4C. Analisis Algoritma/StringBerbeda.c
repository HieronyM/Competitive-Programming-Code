#include<stdio.h>
#include<string.h>

int main()
 {
 	char Kata1[52],Kata2[52];
 	scanf("%s %s",&Kata1,&Kata2);
 	
 	int nKata1 = strlen(Kata1);
	int nKata2 = strlen(Kata2);
	int a,b;
	
	// Jika added string diappend di kanan
	
	// Jika added String diappend di kiri
	int beda = nKata2 - nKata1,count,min = 100;
	for(a = 0; a <= beda; a++)
	  {
	  	count = 0;
	  	for(b = 0; b < nKata1; b++)
	  	{
	  	  if(Kata1[b] != Kata2[b+a])
	  	   {
	  	   	count++;
	  	   }
	  	}
	  //	printf("count (%d) : %d\n",a,count);
	  	if(min > count) min = count;	  	 
	  }  
	  
	printf("%d\n",min); 
	return 0;
 }
