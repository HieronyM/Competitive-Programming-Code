#include<cstdio>
using namespace std;

int H,D,counter;
float tinggi,U,tempU,F;

int main()
 {
 	while(1)
 	{
 		// Refresher
 		counter = 0;
 		tinggi = 0;
 		
 		scanf("%d %f %d %f",&H,&U,&D,&F);
 		if(!H) break;
 		tempU = U;
 		
 		while(1)
 		{
 			tinggi += U;
 			
 			// Kondisi Sampai
 			if(tinggi > H)
			 {
			 	printf("success on day %d\n",counter+1);
			 	break;
			 }
			 
			 // Kondisi Gagal
			tinggi -= D;
			if(tinggi < 0)
			 {
			 	printf("failure on day %d\n",counter+1);
			 	break;
			 }
			
 			counter++;
 			// Pengurangan
 			U = U - ((F/100) * tempU);
 			if(U < 0) U = 0;
 			
 			// Debugging
 			//printf("tinggi = %f U = %f\n",tinggi,U);
 		}
 	}
 	return 0;
 }
