// Program      : SDS
// Programmer   : Hierony Manurung
// Begin        : 11 Juni 2013, 20:50
// Finish       : 12 Juni 2013, 08:29

#include<stdio.h>

int main()
{
 int N;
 scanf("%d",&N);   
 
 double nilai[N], min, max, ratarata, Sbaku, Sigmanilai=0,sum=0,nkaliXbar;
 int a;
 for(a=0; a<N; a++)
    {
       scanf("%lf",&nilai[a]);
       sum = sum + nilai[a];   
    }
  ratarata = sum/N;
  min = nilai[0];
  max = nilai[0];
  
  for(a=0; a<N; a++)
    {
     if(min > nilai[a])
       {
        min = nilai[a];    
       }
     if(max < nilai[a])
       {
        max = nilai[a];    
       }     
     Sigmanilai = Sigmanilai + (nilai[a]*nilai[a]);           
     
    }
  nkaliXbar = N * (ratarata*ratarata);  
  Sbaku = sqrt(((Sigmanilai - nkaliXbar)/(N - 1)));
  
  printf("%.2lf %.2lf %.2lf %.2lf\n",min,max,ratarata,Sbaku);   
  return 0;  
}
