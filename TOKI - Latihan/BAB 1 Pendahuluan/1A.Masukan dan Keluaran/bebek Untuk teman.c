#include<stdio.h>

int main()
{
 int  A, B, c, d, e;
 char perintah[7];
 
 scanf("%d",&A);
 scanf("%d",&B);
 c=A/B;
 d=A-(c*B);
 
    printf("masing-masing %d\nbersisa %d\n",c,d);
 return 0;   
}
