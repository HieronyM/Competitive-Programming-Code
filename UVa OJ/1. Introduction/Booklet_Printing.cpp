#include<cstdio>

using namespace std;

int main()
 {
 	int a,n,bagi2,sheet,kel4,nBlank,nPrint;
 	while(1)
 	{
 		// Refresh value
 		nPrint =0;
 		kel4 = 0;
 		sheet = 0;
 		
 		scanf("%d",&n);
 		if(n == 0) break;
 		
 		
 		// Cari angka kelipatan 4 yang bisa handle TC nya (Ex 14 = 16, 3 = 4)
 		while(kel4 < n) kel4 +=4;
 		
 		// Bagi2 merupakan banyaknya perulangan di pencetakan nanti 
 		bagi2 = kel4/2;
 		
 		// nBlank merupakan banyaknya output blank
 		nBlank = bagi2 * 2 - n;
 		
 		// Mulai mencetak
 		printf("Printing order for %d pages:\n",n);
 		// Cari kelipatan
 		 for(a = 1; a <= bagi2 ; a++)
 		{
 			// Jika yang diprint  == banyak halaman, break
 			if(nPrint == n) break;
 			
 			// Pengaturan iterasi untuk sheet (2a = +1 sheet)
 			if((a % 2) + 1 == 2) sheet++;
 			
 			// Pengaturan Front
 			if(a % 2 == 1) 
			 {
			 	if(nBlank)
			 	{
			 		printf("Sheet %d, front: Blank, %d\n",sheet,a);
			 		nBlank--;
			 		nPrint +=1;
			 	}
			 	else
			 	{
			 		printf("Sheet %d, front: %d, %d\n",sheet,((kel4) - a + 1),a);
			 	    nPrint +=1;
				}
			 }
			 
			 // Pengaturan back;
			else
			 {
			 	// Jika masih ada blank
			 	if(nBlank)
			 	{
			 		printf("Sheet %d, back : %d, Blank\n",sheet,a);
			 		nBlank--;
			 		nPrint +=1;
			 	}
			 	// Jika blank tidak ada
			 	else
			 	{
			 		printf("Sheet %d, back : %d, %d\n",sheet,a,((kel4) - a + 1));
			 		nPrint +=2;
				}
			 } 			 
 		}
 	}
 	return 0;
 }
