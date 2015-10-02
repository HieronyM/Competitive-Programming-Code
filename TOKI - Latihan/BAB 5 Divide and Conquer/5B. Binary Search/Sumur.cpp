#include <cstdio>
  
long long x[1000005] = {};
  
int main(){
        long long n,m,v;
        scanf("%lld %lld %lld",&n,&m,&v);
        for(long i=0; i<n; i++)
        for(long j=0; j<m; j++){
            long long a;
            scanf("%lld",&a);
            x[a]++;
        }
        double h = 1e+6;
        long long i=0,j=0;
        while(h>i){
        v -= j;
        j += x[i];
        if(x[i]>0) h = (double) v/j+i;
        i++;
        }
        printf("%0.3lf\n",h);
        return 0;
}
