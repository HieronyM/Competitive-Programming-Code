#include<stdio.h>

char bangunan[82][82];

 // The recursion lies here
void Flood(char pattern[82][82], int x,int y)
 {
 	pattern[x][y] = '*';
 	
 		
	  if(pattern[x][y-1] == '.')
 	 	{
 			Flood(pattern,x,y-1);
 	 	}
 	 	
	  if(pattern[x][y+1] == '.')
 	 	{
 	   		Flood(pattern,x,y+1);
	 	}
	 	
	  if(pattern[x-1][y] == '.')
 		{
 			Flood(pattern,x-1,y);
 	 	}
	 
	  if(pattern[x+1][y] == '.')
 	 	{
 			Flood(pattern,x+1,y);
 	 	}  
 }

int main()
  {
  	short int N;
    scanf("%hd%*c",&N);

	short int a,b,c,row,column;
	int status;
	for(a = 0; a < N; a++)
	 {
	 	scanf("%hd%*c %hd%*c",&row,&column);
	 	for(b = 0; b < row; b++)
	 	  {
	 	  	//gets(bangunan[b]);
	 	   scanf("%[^\n]%*c",bangunan[b]);
		  }
		
		 // Mencari starting point dari rekursinya	 
		 status= 0;
		 for(b = 0; b <= row; b++)
		 {
		 	for(c = 0; c < column; c++)
		 	  {
		 	   if(b == 0 || b == row-1 || c == 0 || c == column-1)
			   {	
		 	  	if(bangunan[b][c] == '.')
		 	  	  {
		 	  	  	bangunan[b][c] = '*';
		 	  	  	Flood(bangunan,b,c);
		 	  	  }
		 	   }
		 	  }
		 }
		 
		 /*
		 // Debugging
	  	 printf("\n");
	 	// Hasil Rekursi
	 	for(b = 0; b < row; b++)
	 	  {
	 	  	printf("%s\n",bangunan[b]);
	 	  }
	 	  */
	 	
	 	  
	 	  
	 	  
	 	  // Mengecek apakah ada daerah tidak terkena banjir
	 	 for(b = 0; b < row; b++)
		 {
		 	for(c = 0; c < column; c++)
		 	  { 
		 	   if(bangunan[b][c] == '.')
		 	     {
		 	     	status = 1;
		 	     	break;
		 	     }
		 	  }
		}
		
		// Mencetak Output
		if(status == 0)
		  {
		  	printf("TIDAK\n");
		  }
		else
		  {
		    printf("YA\n");	
		  }  	  
	 } 
	return 0; 	  
  }
