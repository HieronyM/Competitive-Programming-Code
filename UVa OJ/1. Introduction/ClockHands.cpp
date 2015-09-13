#include<cstdio>
#include<cmath>

using namespace std;
int main()
 {
 	int M,H;
 	float degree;
 	char dummy;
 	float derJam, derMin;
 	
 	while(1)
 	{
 		scanf("%d",&H);
 		scanf("%c",&dummy);
 		scanf("%d",&M);
 		
 		// Kondisi dia berhenti
 		if(!H && !M)   break;
		 	
 		else
		 {
 			derJam =(float) (60 * H + M) / 2;
 			derMin =(float) 6 * M;
 			degree = fabs( derJam - derMin);
 			// Cek yang terkecil
 			if(degree > 180) degree = 360 - degree;
 	
 			printf("%.3f\n",degree);
 		}
 	}
 	return 0;
 }
