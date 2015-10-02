#include <stdio.h>

int prim[77779];
int cekprim[999999];
  
int main(){
    int i,j,k=1;
    for(i = 1; i < 1000000; i++)cekprim[i] = 1;
    for(i = 2; i < 1000000; i++)
          if(cekprim[i]== 1){
                     prim[k] = i;
                     for(j = i; j < 1000000; j=j+i) {cekprim[j] = 0;}
                     k++;
                     }
    int N;
    scanf("%d",&N);
 
    for(i = 0; i < N; i++) {
          scanf("%d",&k); printf("%d\n",prim[k]);}
 
    return 0;
    }
