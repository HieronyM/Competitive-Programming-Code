	

    #include <stdio.h>
     
    long long int arr[20];
    long long int ans[20];
     
    int main(){
            long long int i, angka, k = 0;
            arr[0] = 1;
           
            for(i = 1; i < 20; i++){
                    arr[i] = arr[i-1] * 3;
            }
           
            scanf("%lld",&angka);
           
            for(i = 19; i >= 0; i--){
                    if(angka >= arr[i]){
                            ans[k] = arr[i];
                            angka = angka-arr[i];
                            k++;
                    }
            }
           
            for(i = k-1; i >= 0; i--){
                    printf("%lld",ans[i]);
                    if(i > 0)printf(" ");
            }
            printf("\n");
            return 0;
    }


