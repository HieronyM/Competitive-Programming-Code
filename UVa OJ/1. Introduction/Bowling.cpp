#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;
//char command[50];
int total,i,status,status2;
int nPukul;
string command;

int getNum(char number)
 {
 	return number - '0';
 }

int main()
 {
 	while(1)
 	{
 		nPukul = 0;
 		total = 0;
 		i = 0;
 		//scanf("\n");
 		//scanf("%[^\n]",&command);
 		getline(cin,command);
 		
 		if(command == "Game Over") break;
 		
 		/* Debugging */
 		//printf("Command : %s\n",command);
 		
 		// Mulai Proses perhitungan
		while(command[i] != '\0')
 		{
 			// Break
 			if(nPukul == 10) break;
 			
 		   // Abaikan spasi
 		  if(command[i] == ' ')
		   {
		   	i++;
		   	continue;
		   }	
		   
		   // Jika tidak spasi
		  else
		   {
		   //	printf("i : [%d], status : %d, nPukul : %d, Total saat ini : %d\n",i,status,nPukul,total);
		   	
			// Jika ketemu Strike
		  	if(command[i] == 'X')
		  	  {
		  	  	// Jika pukulan kedua yang strike
		  	  	if(status) total -= getNum(command[i-2]);
		  	  	
		  		// Perhitungan
		  	  	if(command[i+2] == 'X' || command[i+2] == '/')  total += 10;
		  	  	
				else 
				{
				  total += getNum(command[i+2]);
				  status2= 1;	
				}
				
				if(command[i+4] == 'X' || command[i+4] == '/')  
				{
					total += 10;
					if(status2) total -= getNum(command[i+2]);
					
					status2 = 0;
				}
		  	  	else total += getNum(command[i+4]);
		  	  	
		  	  	total += 10;
		  	    status = 0;
		  	    nPukul++;
			  }
		  	  
		  	// Jika ketemu Spare
		  	else if(command[i] == '/')
		  	  {
		  	  	// Jika pukulan kedua yang spare
		  	  	if(status) total -= getNum(command[i-2]);
		  	  	
		  	  	// Perhitungan
		  	  	if(command[i+2] == 'X' || command[i+2] == '/') 
				  {
				  	total += 10;
				  }
		  	  	else 
				  {
					total += getNum(command[i+2]);	
				  }
		  	  	total += 10;
		  	  	status = 0;
		  	  	nPukul++;
		  	  }  
		  	  
		  	// Jika tidak Spare atau Strike
			  else  
			  {
			  	if(status == 1) 
				  {
				  	status = 0;
				  	nPukul++;
				  }
			  	
			  	else  
				{
					status = 1;
				}
			  	total += getNum(command[i]);
			  }
		   } 
		   i++;
 		}
 		
 		printf("%d\n",total);
 	}
 	return 0;
 }
