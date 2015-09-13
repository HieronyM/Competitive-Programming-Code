#include <cstdio>
#include <iostream>
 
void tukar (int &y,int &x){
     int temp = x;
     x = y;
     y = temp;
     }
int main(){
    int N,i,j,jumlah=0;
    scanf("%d",&N);
    int arr[N];
    for(i = 0; i < N; i++) scanf("%d",&arr[i]);
    for(i = 0; i < N; i++){
          j=i;
          while(j > 0 && arr[j-1] > arr[j]){
                  tukar(arr[j-1],arr[j]);
                  jumlah++;
                  j--;
                  }
    }
    printf("%d\n",jumlah);
    return 0;
    }
