#include <stdio.h>

int main()
{
    long x1,x2,y1,y2;
    scanf("%ld %ld %ld %ld",&x1,&y1,&x2,&y2);
    
    long total,panjang,lebar;
    panjang = x2 - x1;
    lebar = y2 - y1;
    total = panjang + lebar;
    
    printf("%ld\n",total);      
    
    return 0;
}
