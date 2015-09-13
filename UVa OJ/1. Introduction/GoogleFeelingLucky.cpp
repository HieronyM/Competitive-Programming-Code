#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int TC,a,b;
int main()
 {
 	int max;
 	scanf("%d",&TC);
 	b = 1;
 	while(TC--)
 	{
 	 max = 0;
 	 string data[12];
	 int angka[10];
	 
	 for(a = 0; a < 10; a++)
	 {
	 	char temp[50];
	 	scanf("%s %d",&temp, &angka[a]);
	 	data[a] = temp;
	 	// Cek max
	 	if(max < angka[a]) max = angka[a];
	 }	
	 
	 // Cetak
	 printf("Case #%d:\n",b);
	 for(a = 0; a < 10; a++)
	 {
		// Cek max
	 	if(angka[a] == max) printf("%s\n",data[a].c_str());
	 }
	 
	 b++;
 	}
 	
 	return 0;
 }
