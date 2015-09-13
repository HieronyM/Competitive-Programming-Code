#include <stdio.h>
#include <string.h>
 
int nilai[1005], jumlah[1005],nilai2[1005],jumlah2[1005];
 
int main(){
    char perintah[10];
    int x, y, N,size = 0,k,i,j,count = 0,uk = 0;
    scanf("%d",&N);
    for(k = 0; k < N; k++){
        scanf("%s",&perintah);
        //x = 0, y = 0;
        if(strcmp(perintah,"add") == 0){
            scanf("%d %d",&x,&y);
            nilai[count] = x;
            jumlah[count] = y;
            size = size + y;
            printf("%d\n",size);
            count++;
        }
         
        else if(strcmp(perintah,"del") == 0){
            scanf("%d",&y);
            size = size - y;
            if(size < 0) {
                size = 0;
            }
            for(i = 0; i < count; i++){
                if(jumlah[i] > 0){
                    printf("%d\n",nilai[i]);
                    break;
                }
            }
             
            i = 0;
            while(y >= 0 && i < count){
                y = y-jumlah[i];
                if(y >= 0){
                    jumlah[i] = 0;
                    nilai[i] = 0;
                }
                else {
                    y = y+jumlah[i];
                    jumlah[i] -= y;
                    y = 0;
                }
                i++;
            }
             
        }
         
        else if(strcmp(perintah,"rev") == 0){
            for(i = 0; i < count; i++){
                nilai2[i] = nilai[i];
                jumlah2[i] = jumlah[i];
            }
            //proses membalik bilangan
            for(i = 0; i < count; i++){
                nilai[i] = nilai2[count-i-1];
                jumlah[i] = jumlah2[count-i-1];
            }
        }
         
        /*for(i = 0; i < count; i++){
            printf("%d ",jumlah[i]);
        }
        printf("\n");
        for(i = 0; i < count; i++){
            printf("%d ",nilai[i]);
        }
        printf("\n");
        */
         
    }
     
    return 0;
}
