#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#define pb push_back
using namespace std;
typedef vector<string> vs;
int arr[130][130],sum,s,i,j;
vs kode;
 
char test(int a){
    char h[5]="0123";
    return h[a];
}
  
 
void periksa(int x1,int y1, int x2, int y2,int k, string code){
    int sum=0; 
    for(i = x1; i <= x2; i++)
        for(j = y1; j <= y2; j++)
            sum+=arr[i][j];
     
    if(sum == (x2-x1+1)*(y2-y1+1)){
        code+=test(k);
        kode.pb(code);
    }
    else if(sum != 0){
            code +=test(k);
            periksa(x1            ,y1       ,(x2+x1)/2  ,(y2+y1)/2 ,  0,code);
            periksa(x1            ,((y2+y1)/2)+1 ,(x2+x1)/2  ,y2          ,1,code);
            periksa(((x2+x1)/2)+1 ,y1       ,x2         ,(y2+y1)/2   ,2,code);
            periksa(((x2+x1)/2)+1      ,((y2+y1)/2)+1 ,x2         ,y2          ,3,code);
        }
}
#define REP(a,b) for(a = (int) 1; a <= (int) b; a++)
int main(){
    int r,c,a,b;
    int v = 1;
    memset(arr,0,sizeof(arr));
    scanf("%d %d",&r,&c);
    sum = 0;
    REP(a,r){
        REP(b,c){
            scanf("%d",&arr[a][b]);
        }
    }
    while(r>v || c>v) v <<= 1;
    periksa(1,1,v,v,1,"");
    for(int i=0; i < kode.size();i++)printf("%s\n",kode[i].c_str());
    printf("END\n");
    return 0; 
}
