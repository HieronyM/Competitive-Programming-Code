#include<cstdio>
#include<cstring>

using namespace std;

int no,a,b;
char word[1000],guest[1000];
int nCharW,nCharG,counter;
int status,nWrong,found;
int main()
 {
 	
 	while(1)
 	{
 	 counter = 0;
 	 nWrong = 0;
 	 found = 0;
 	 scanf("%d",&no);
	 if(no == -1) break;
	 else
	 {
	 	scanf("%s",&word);
	 	scanf("%s",&guest);
	 	
		nCharW = strlen(word);				// Banyak Karakter kata yang mau ditebak
	 	nCharG = strlen(guest);				// Banyak karakter Kata yang ditebak
	 	for(a = 0; a < nCharG; a++)
	 	 {
	 	 	status = 0;
	 	 	for(b = 0; b < nCharW; b++)
	 	 	{
	 	 		// Jika karakter yang ditebak ada di kata asli, ubah kata aslinya
	 	 		if(guest[a] == word[b])
	 	 		{
	 	 			counter++;
	 	 			word[b] = '*';
	 	 			status = 1;
	 	 		}
	 	 	}
	 	 	
	 	 //	printf("nWrong : %d\n",nWrong);
	 	 	if(!status) nWrong++;
	 	 	
			// Jika dia udah kalah
			if(nWrong > 6)
			{
				printf("Round %d\nYou lose.\n",no);
				found = 1;
				//found = 1;
				break;
			}
	 	 	
			// ketika sudah jelas Menang  
			if(counter >= nCharW && !found) 
			  {
			  	printf("Round %d\n",no);
			  	printf("You win.\n");
			  	break;
			  }
	 	 } 
	 	 
	 	  // Jika Keputusan belum bisa ditentukan
	 	 if(nWrong < 7 && counter < nCharW  && !found) 
		  {
		  	printf("Round %d\n",no);
		  	printf("You chickened out.\n");
		  }
	 }	
 	}
 	return 0;
 }
