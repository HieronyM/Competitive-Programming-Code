#include<stdio.h>

int jaw[27][27];
int row,column,bola;

 // The recursion lies here
void FloodBola(int x,int y)
 {
 	jaw[x][y] = 7;
 	if (x > 0 || x < row+1 || y > 0 || y < column+1)
	 {	
	  if(jaw[x][y-1] == bola)
 	 	{
 			FloodBola(x,y-1);
 	 	}
 	 	
	  if(jaw[x][y+1] == bola)
 	 	{
 	   		FloodBola(x,y+1);
	 	}
	 	
	  if(jaw[x-1][y] == bola )
 		{
 			FloodBola(x-1,y);
 	 	}
	 
	  if(jaw[x+1][y] == bola)
 	 	{
 			FloodBola(x+1,y);
 	 	}
	}
 }

int main()
  {
	short int b,c;

	 	scanf("%hd%*c %hd%*c",&row,&column);
	 	for(b = 0; b < row; b++)
	 	  {
	 	  	for(c = 0; c < column; c++)
	 	  	{
				scanf("%d",&jaw[b][c]);
	 	  	} 
		  }
		
		int rowPosisi,colPosisi;
		scanf("%d %d",&rowPosisi,&colPosisi);
		
		bola = jaw[rowPosisi][colPosisi];
		//printf("Cari bola yang : %d\n",bola);
		int nBola = 0;
		
		// lakukan Rekursi
		FloodBola(rowPosisi,colPosisi);
		 
		 	// Hitung wilayah Kucing
			 for(b = 0; b < row; b++)
		 	{
		 		for(c = 0; c < column; c++)
		 	  	{
				  	if(jaw[b][c] == 7)
				  	{
				  		nBola++;
				  	}
			  	}
			}
		 
	//	 printf("Jumlah bola yang terpilih : %d\n",nBola);
		 
		 int nilai = nBola * (nBola - 1);		 
					
			
		/*			 
	       	//  Debugging
	  	 printf("\n");
	  	 
	 	// Hasil Rekursi
	 	for(b = 0; b < row; b++)
	 	  {
	 	  	  for(c = 0; c < column; c++)
	 	  	{
				printf("%d ",jaw[b][c]);
	 	  	} 
	 	  	printf("\n");
	 	  }
	 	  */
	 	  
	 	  
	 	  printf("%d\n",nilai);
	 	  
	return 0; 	  
  }
