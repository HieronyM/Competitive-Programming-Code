/* Filename : MotherBear.cpp */

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

string data,temp;
int i,a,b,status;
int main()
 {
 	while(1)
 	{
 		i = -1;
 		a = 0;
 		status = 0;
 		getline(cin,data);
 		
 		// Keadaan dia sudah berakhir
 		if(data == "DONE") break;
 		
 		// Menampung ulang, sehingga yang sisa tinggal huruf
 		while(data[a] != '\0')
 		{
 			// Jika Ketemu karakter Tampung di Temp
 			if ( (data[a]>=65 && data[a]<=90) || (data[a]>=97 && data[a]<=122) )
			{
				i++;
				temp.append(1,data[a]);
			}
			a++;  
 		}
 		
 		// Pindahkan Ke bentuk Upper Case
 		transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
 		
 		// Debugging
 		//printf("%s\n",temp.c_str());
 		
 		//printf("i : %d\n",i);
 		// Mencari apakah Palindrom atau tidak
		for(b = 0; b < ((i+1)/2); b++)
		{
			//printf("IDX ke : %d \t karakter yang dicek : %c & %c\n",b,temp[b], temp[i-b]);
			if(temp[b] != temp[i-b]) 
			{
				//printf("---IDX ke : %d \t karakter yang dicek : %c & %c\n",b,temp[b], temp[i-b]);
				status = 1;
				break;
			}
		}
		
		if(!status) printf("You won't be eaten!\n");
		else printf("Uh oh..\n");
		
		// Refresh
 		temp = "";
 		data = "";
 	}
 	return 0;
 }
