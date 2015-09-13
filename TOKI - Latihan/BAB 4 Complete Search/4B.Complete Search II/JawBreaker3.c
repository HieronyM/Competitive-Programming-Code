#include<stdio.h>

int jaw[1000][1000];
int jawCopy[1000][1000];
int row,column,bola,nBola=0,temp,d,e,bolaFix;

 // For the first array (get the max)
void FloodBola(int x,int y)
 {
 	nBola++;
 	jaw[x][y] = 0;
 	if (x >= 0 || x < row+1 || y >= 0 || y < column+1)
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
 
 // Melakukan manipulasi di array Copian (0 menandakan nilai max)
 void FloodBolaCopy(int x,int y)
 {
 	nBola++;
 	jawCopy[x][y] = 0;	
	  if(jawCopy[x][y-1] == bolaFix)
 	 	{
 			FloodBolaCopy(x,y-1);
 	 	}
 	 	
	  if(jawCopy[x][y+1] == bolaFix)
 	 	{
 	   		FloodBolaCopy(x,y+1);
	 	}
	 	
	  if(jawCopy[x-1][y] == bolaFix )
 		{
 			FloodBolaCopy(x-1,y);
 	 	}
	 
	  if(jawCopy[x+1][y] == bolaFix)
 	 	{
 			FloodBolaCopy(x+1,y);
 	 	} 	
 }

// Untuk Meruntuhkan
void Runtuhkan(int x,int y)
 {
 	while(jawCopy[x+1][y] == 0 && x < row-1)
 	{
 	 temp = jawCopy[x][y];
	 jawCopy[x][y] = 0;
	 jawCopy[x+1][y] = temp;
	 x++;
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
				jawCopy[b][c] = jaw[b][c];
	 	  	} 
		  }
		
		// Rekursi untuk ngecek max value
		int max = 0,rowMax,colMax;
		for(b = 0; b < row; b++)
	 	  {
	 	  	for(c = 0; c < column; c++)
	 	  	{
				if(jaw[b][c] != 0)
				 {
				 	bola = jaw[b][c];
				 	nBola = 0;
				 	FloodBola(b,c);
				 	
				 	if(max < nBola)
				 	  {
				 	  	rowMax = b;
				 	  	colMax = c;
				 	  	max = nBola;
						bolaFix = bola;	 	  	
				 	  }
				 }
	 	  	 } 
		  }
			 	 //printf("rowMax : %d \n colMax : %d\n",rowMax,colMax);
			 	 //printf("Max : %d\n",max);
		// Lakukan Rekursi untuk max value	 	 
		FloodBolaCopy(rowMax,colMax);  
		
		 /* Debugging
         printf("\nKeadaan sebelum diruntuhkan \n");
          
        // Hasil Rekursi
        for(b = 0; b < row; b++)
          {
              for(c = 0; c < column; c++)
            {
                printf("%d ",jawCopy[b][c]);
            }
            printf("\n");
          }
          */    
		// Meruntuhkan		  	 
		for(b = 0; b < column; b++)
	 	  {
	 	  	for(c = row-1; c > 0; c--)
	 	  	{
				if(jawCopy[c][b] == 0 && jawCopy[c-1][b])
				 {
				 	//bola = jaw[b][c];
				 	//nBola = 0;
				 	Runtuhkan(c-1,b);
				 }          		
	 	  	 } 
		  }
										  	 
	 	// Cetak hasilnya
	 	for(b = 0; b < row; b++)
	 	  {
	 	  	  for(c = 0; c < column; c++)
	 	  	{
	 	  		// Kondisi No Space (Kolom terakhir)
	 	  	  if(c == column - 1)
				{
				  if(jawCopy[b][c] == 0)
	 	  			{
	 	  		  		printf(".");	
	 	  			}
	 	  		  else
	 	  			{
	 	  		  		printf("%d",jawCopy[b][c]);	
	 	  			}	
				} 	
				
				// Pake Space (Bukan kolom terakhir)
			   else
			    {
			   		if(jawCopy[b][c] == 0)
	 	  			{
	 	  		  		printf(". ");	
	 	  			}
	 	  			else
	 	  			{
	 	  		  		printf("%d ",jawCopy[b][c]);	
	 	  			}
			    }	
	 	  	} 
	 	  	printf("\n");
	 	  }	 	  
	return 0; 	  
  }
