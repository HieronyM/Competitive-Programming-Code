#include<cstdio>
//#include<sstream>
#include<cstring>
#include<string.h>
#include<stdlib.h>
#include<cstring>

using namespace std;

//stringstream convert;   // stream used for the conversion
int counter[10],n;
//string temp,str;
char buffer[33];
int nHuruf,a,b;

void cek(char digit)
 {
 	if(digit == '0') counter[0]++;
 	else if(digit == '1') counter[1]++;
 	else if(digit == '2') counter[2]++;
 	else if(digit == '3') counter[3]++;
 	else if(digit == '4') counter[4]++;
 	else if(digit == '5') counter[5]++;
 	else if(digit == '6') counter[6]++;
 	else if(digit == '7') counter[7]++;
 	else if(digit == '8') counter[8]++;
 	else if(digit == '9') counter[9]++;
 }

int main()
 {
 	int nData;
 	// Set jadi 0
 	for(a = 0; a < 10; a++) counter[a] = 0;
 	
 	scanf("%d",&nData);
 	while(nData)
 	{
 		buffer[nHuruf-1] = '\0';
 		scanf("%d",&n);
 		a = 0;
 		for(a = 1; a <= n; a++)
 		{
 			sprintf(buffer,"%d",a);
			nHuruf = strlen(buffer);
			for(b = 0; b < nHuruf; b++)
			{
				cek(buffer[b]);
			}
			//convert << '\0';
 		}
 		for(a = 0; a < 10; a++)
		{ 
      		if(a != 9) printf("%d ",counter[a]);
      		else printf("%d\n",counter[a]);
		}
		memset(counter,0,sizeof(counter));
		
		nData--; 
	}
	
 	return 0;
 }
