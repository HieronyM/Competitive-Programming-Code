#inlude<stdio.h>

char bangunan[502][502];
int count,row,column;

 // The recursion lies here
void FloodBebek(int x,int y)
 {
 	bangunan[x][y] = 'b';
 	if (x > 0 || x < row+1 || y>0 || y < column+1)
	 {	
	  if(bangunan[x][y-1] == '.' || bangunan[x][y-1] == 'k')
 	 	{
 			FloodBebek(x,y-1);
 	 	}
 	 	
	  if(bangunan[x][y+1] == '.' || bangunan[x][y+1] == 'k')
 	 	{
 	   		FloodBebek(x,y+1);
	 	}
	 	
	  if(bangunan[x-1][y] == '.' || bangunan[x-1][y] == 'k')
 		{
 			FloodBebek(x-1,y);
 	 	}
	 
	  if(bangunan[x+1][y] == '.' || bangunan[x+1][y] == 'k')
 	 	{
 			FloodBebek(x+1,y);
 	 	}
	}
 }
 
 void FloodKucing(int x,int y)
 {
 	bangunan[x][y] = 'k';
 	if (x > 0 || x < row+1 || y>0 || y < column+1)
	 {	
	  if(bangunan[x][y-1] == '.')
 	 	{
 			FloodKucing(x,y-1);
 	 	}
 	 	
	  if(bangunan[x][y+1] == '.')
 	 	{
 	   		FloodKucing(x,y+1);
	 	}
	 	
	  if(bangunan[x-1][y] == '.')
 		{
 			FloodKucing(x-1,y);
 	 	}
	 
	  if(bangunan[x+1][y] == '.')
 	 	{
 			FloodKucing(x+1,y);
 	 	}
	}
 }

int main()
  {
	short int b,c;

	 	scanf("%hd%*c %hd%*c",&column,&row);
	 	for(b = 0; b < row; b++)
	 	  {
	 	   scanf("%[^\n]%*c",bangunan[b]);
		  }
		
		int luasKucing = 0,luasBebek = 0;
		
		int rowBebek,colBebek;
		// Mencari Posisi bebek agar bisa diketahui
		for(b = 0; b < row; b++)
		 {
		 	for(c = 0; c < column; c++)
		 	  {
		 	  	if(bangunan[b][c] == 'B')
		 	  	  {
		 	  	  	rowBebek = b;
		 	  	  	colBebek = c;
		 	  	  	break;
		 	  	  }
		 	   }
		 }
		
		 // Mencari starting point dari rekursi Kucing 
		 for(b = 0; b < row; b++)
		 {
		 	for(c = 0; c < column; c++)
		 	  {
		 	  	if(bangunan[b][c] == 'K')
		 	  	  {
		 	  	  	FloodKucing(b,c);
		 	  	  }
		 	   }
		 }
		 
		 	// Hitung wilayah Kucing
			 for(b = 0; b < row; b++)
		 	{
		 		for(c = 0; c < column; c++)
		 	  	{
				  	if(bangunan[b][c] == 'k')
				  	{
				  		luasKucing++;
				  	}
			  	}
			}
		 		 
		// rekursi Bebek 
	
		 	FloodBebek(rowBebek,colBebek);
			 	  	 
		// Hitung wilayah bebek
			 for(b = 0; b < row; b++)
		 	{
		 		for(c = 0; c < column; c++)
		 	  	{
				  	if(bangunan[b][c] == 'b')
				  	{
				  		luasBebek++;
				  	}
			  	}
			}
		
					
		/*			 
		   // Debugging
		   printf("Luas bebek : %d\n",luasBebek);
		   printf("Luas kucing : %d\n",luasKucing);
	       
	       	//  Debugging
	  	 printf("\n");
	  	 
	 	// Hasil Rekursi
	 	for(b = 0; b < row; b++)
	 	  {
	 	  	printf("%s\n",bangunan[b]);
	 	  }
	 	  */
	 	
	 	
	       // Penentuan Hasil
	       if(luasBebek == luasKucing)
	         {
	         	printf("SERI\n");
	         }
	       else if(luasBebek > luasKucing)
	         {
	         	printf("B %d\n",luasBebek-luasKucing);
	         }
		   else	if(luasBebek < luasKucing)
	         {
	         	printf("K %d\n",luasKucing-luasBebek);
	         }   
	         
	return 0; 	  
  }
