#include <cstdio>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;
 
double eps=1e-3;
int N,i,j;
double sum,average,arr[500005],angka=1.0,m=0.0;
 
double jum(double y){
    sum=0.0;
    for(i = 0; i < N; i++){
        sum = sum +pow(abs(arr[i]-y),1.5);
    }
    return sum;
}
 
double cari(double kiri, double kanan){
    double x,y,z,mid;
    mid=(kiri+kanan)/ 2;
            x=jum(mid-eps);
            y=jum(mid);
            z=jum(mid+eps);
            if ((x>y) and (y<z)) return mid;
            else if (y>z) return cari(mid+eps,kanan);
            else if (y>x) return cari(kiri,mid-eps);
}
 
int main(){
    scanf("%d",&N);
    for(i = 0; i < N; i++){
        cin >> arr[i];
        sum = sum+arr[i];
        //printf("angka = %f %f\n",m,arr[i]);
        m=m+angka;
    }
     
    printf("%.2lf\n",cari(-10001,10001));
}
