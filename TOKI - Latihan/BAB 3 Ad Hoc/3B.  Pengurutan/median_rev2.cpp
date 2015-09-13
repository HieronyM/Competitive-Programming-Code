#include <cstdio>
#include <iostream>
#include <algorithm>
 
using namespace std;
 
void tukar (int &y,int &x){
     int temp = x;
     x = y;
     y = temp;
     }
      
int main(){
    int N,i,j;
    float median;
    scanf("%d",&N);
    int arr[N];
    for(i = 0; i < N; i++) scanf("%d",&arr[i]);
    sort(arr,arr+N);
    median = (N % 2) ? arr[N/2] : (float)(arr[N/2-1]+arr[N/2])/2;
    printf("%.2f\n",median);
    return 0;
    }
