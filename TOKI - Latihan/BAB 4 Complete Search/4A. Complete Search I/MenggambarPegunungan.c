            //  Programmer  :   Hierony Manurung
            //  Program     :   Menggambar Pegunungan
            //  Begin Date  :   16 November 2013, 03:00
            //  Finished    :   -


#include<stdio.h>
void gambar(int n)
  { 
     if(n == 1)
	  {
	   printf("*\n");
	  }
	  else
	  {
	  	int i;
	  	gambar(n-1);
	    for(i = 0; i < n; i++)
	    {
		  printf("*");
		}
		printf("\n");
	    gambar(n-1);
	  }	
	
  }


int main()
 {
  int n;
  scanf("%d",&n);
  
  gambar(n);
  
  return 0;        
 }
