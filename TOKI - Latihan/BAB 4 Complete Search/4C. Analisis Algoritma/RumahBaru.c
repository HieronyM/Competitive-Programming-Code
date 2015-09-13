#include<stdio.h>
int x[60],y[60];

int main()
 {
 	int n;
 	scanf("%d",&n);
 	
 	int a;
 	for(a = 0; a < n; a++)scanf("%d",&x[a]);
 	
 	for(a = 0; a < n; a++)scanf("%d",&y[a]);
 	
 	// Proses membangun rumah Baru
 	int i,j,k,nBangun = 0,find1,find2,find3,find4,findAll; // kiri, kanan, atas,bawah
 	for(i=-100; i <= 100; i++)
	 {
        for(j=-100;j<=100;j++)
		{
			find1 = find2 = find3 = find4 = findAll= 0;
		    for(k=0; k < n; k++)
			{
				// Untuk kiri
				if(y[k] == i && x[k] < j )find1 = 1;
				  // Untuk kanan
				if(y[k] == i && x[k] > j)find2 = 1;
				  // Untuk Atas
				if(y[k] > i && x[k] == j)find3 = 1;
				 // Untuk bawah
				if(y[k] < i && x[k] == j)find4 = 1;
			}
			findAll = find1 + find2 + find3 + find4;					
			if(findAll == 4)nBangun++;
		}
 	}
 	// Cetak
 	printf("%d\n",nBangun);
 	
 	return 0;
 }
