	

    #include <cstdio>
    #include <iostream>
     
    using namespace std;
     
    long long  arr[1005];
     
    int main(){
        int k,i;
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 1;
        arr[3] = 2;
        arr[4] = 3;
        for(i = 5; i < 1005; i++)
          {
           arr[i] = arr[i-1] + arr[i-3];
           }
        scanf("%d",&k);
        if(arr[k] > 999999)
        { 
          printf("%lld\n",arr[k]%1000000);
        }
        else 
        { 
          printf("%lld\n",arr[k]);
        }
        return 0;
}

