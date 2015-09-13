#include <stdio.h>
 

 

int main(){
    int N,i,j,k,sama = 0, ada = 0, x1,y1,x2,y2,x3,y3;
    int x[305],y[305];
    long long d1,d2,luas,min = 1000000000;
    scanf("%d",&N);
    
    for(i = 1; i <= N; i++)
        scanf("%d %d",&x[i],&y[i]);
    //combinasi gan
    for(i = 1; i <= N-2; i++){
        for( j = i+1; j <= N-1; j++){
            for(k = j+1; k <= N; k++){
                x1 = x[i];
                y1 = y[i];
                x2 = x[j];
                y2 = y[j];
                x3 = x[k];
                y3 = y[k];
                d1 = (x1*y2)+(y1*x3)+(x2*y3);
                //printf("%llf",d1);
                d2 = (x3*y2)+(y3*x1)+(x2*y1);
                luas = abs(d1-d2);
                //printf("%llf\n",luas);
            	if(luas == min)	sama = 1;
                if(luas < min){
                	min = luas;
                	ada = 1;
                	sama = 0;
                }
                
            }
    	}	
			
    }
    if(ada == 1 && sama == 0) printf("%.2lf\n",(double)min/2);
    else printf("-1.00\n");
    
     
    return 0;
}
