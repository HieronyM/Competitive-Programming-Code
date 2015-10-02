#include <stdio.h>
  
unsigned long long int gcd(unsigned long long int a, unsigned long long int b)
{
    unsigned long long int t;
    while (b)
    {
        t = a%b;
        a = b;
        b = t;
    }
    return a;
}
  
main()
{
    unsigned long long int a,b,c,d,fpb,e;
    scanf("%lld %lld",&a,&b);
    scanf("%lld %lld",&c,&d);
    fpb = gcd(b,d);
    a = a * (d / fpb);
    c = c * (b / fpb);
    b = b * (d / fpb);
    e = a + c;
    fpb = gcd(e,b);
    e = e / fpb;
    b = b / fpb;
    printf("%lld %lld\n",e,b);
    return 0;
}
