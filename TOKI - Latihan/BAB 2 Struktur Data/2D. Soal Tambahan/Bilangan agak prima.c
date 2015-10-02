#include <stdio.h>
//#include <iostream>
//#include <cmath>
int cek(int k){
    int l = k/2,i,count =0;
    for(i = 2; i < l; i++){
          if(k % i==0) count++;
          if(count > 2) break;
          }
    count=count+2;
    i = (count > 1 && count < 5) ? 1:0;
    return i;
    }
 
int main(){
    int N,i,j,k;
    scanf("%d",&N);
    int Ans[N];
    for(i = 0; i < N; i++) {scanf("%d",&k); Ans[i] = cek(k);}\
    for(i = 0; i < N; i++) {if(Ans[i]) printf("YA\n");else printf("TIDAK\n");}
    return 0;
    }
