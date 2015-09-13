#include <cstdio>
long int b=0;
long int data[1005];
void swap(long int *x,long int *y)
{
   long int temp;
   temp = *x;
   *x = *y;
   *y = temp;
}
 
void srt(long int list[], long int m, long int n)
{
    long int i, k, kecil,t=0;
    for (i=0;i<=n;i++)
    {
        kecil = 70000;
        for (k=i;k<=n;k++)
        {
            if (list[k] < kecil)
            {
                kecil = list[k];
                t = k;
            }
        }
        swap(&list[i],&list[t]);
        if (i != t)
            b++;
    }
}
 
main()
{
    long int banyak,i;
    scanf("%ld",&banyak);
    for (i=0;i<=(banyak-1);i++)
        scanf("%ld",&data[i]);
    srt(data,0,banyak-1);
    printf("%d\n",b);
    return 0;
}
