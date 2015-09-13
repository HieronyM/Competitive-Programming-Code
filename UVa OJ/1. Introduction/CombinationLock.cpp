#include<cstdio>

int initial,first,second,third;
int total;

int Clockwise(int Hinitial, int Htujuan)
 {
 	int temp;
 	if(Hinitial < Htujuan) temp = (Htujuan-Hinitial) * 9;
	else temp = 360 -  ((Hinitial-Htujuan) * 9);
	
	//printf("Return Dari Clockwise : %d\n",temp);
	return temp;
 }
 
 int CClockwise(int Hinitial, int Htujuan)
 {
 	int temp;
 	if(Hinitial > Htujuan) temp = (Hinitial-Htujuan) * 9;
	else temp = 360 -  ((Htujuan-Hinitial) * 9);
	
	//printf("Return Dari CClockwise : %d\n",temp);
	return temp;
 }

int main()
 {
 	while(1)
 	{
 		scanf("%d %d %d %d",&initial,&first,&second,&third);
 		if(!initial && !first && !second && !third) break;
 		
		 else
 		{  
 			total = 1080;
 			total +=  CClockwise(initial,first); // Pertama
 			//printf("Total Setelah pertama : %d\n",total);
 			total += Clockwise(first,second);	// Kedua
 			//printf("Total Setelah kedua : %d\n",total);
			total += CClockwise(second,third);	// Ketiga
 			
 		}
 		printf("%d\n",total);
 	}
 	return 0;
 }
