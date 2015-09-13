#include<cstdio>
#include<cstring>

using namespace std;
int a,b,n,hasil;
int Data[3000],cek[3000];
int status;

int main()
 {
 	while(scanf("%d",&n) != EOF)
 	{
 		status = 0;
 		memset(cek,0,sizeof(cek));
 		
 		for(a = 0; a < n; a++) 
		 {
		 	scanf("%d",&Data[a]);
		 }
		 
		if(n <= 1) 
		 {
		 	printf("Jolly\n");
		 	continue;
		 }
 		
 		for(a = 0; a < n-1; a++)
 		{
 		 if(Data[a+1] > Data[a])
 		 {
 		 	hasil = Data[a+1] - Data[a];
 		 }
	     
	     else
	     {
	     	hasil = Data[a] - Data[a+1];
	     }
	     
	     cek[hasil] = 1;
 		}
 		
 		// Pengecekan
 		for(a = 1; a < n; a++)
 		{
 			if(cek[a] != 1)
			{
				status = 1;
				printf("Not jolly\n");
				break;
			}
 		}
 		
 		if(!status) printf("Jolly\n");
 	}
 	
 	return 0;
 }
