#include <cstdio>
#include <iostream>
 

 
typedef long l;
void tukar(l &x, l &y){
     l temp = x;
     x = y;
     y = temp;
     }
 
int main(){
    l arr[100000];
    l N,tkr,a,b,c,d,e;
    scanf("%ld %ld",&N,&tkr);
    for(a = 1; a <= N; a++)arr[a] = a;
    for(a = 1; a <= tkr; a++){scanf("%ld %ld",&b,&c);
                           tukar(arr[b],arr[c]);}
    scanf("%ld",&d);
    l ans[d];
    for(a = 0; a < d; a++) {scanf("%ld",&e);ans[a] = arr[e];}
    for(a = 0; a < d; a++) printf("%ld\n",ans[a]);
    return 0;
    }
