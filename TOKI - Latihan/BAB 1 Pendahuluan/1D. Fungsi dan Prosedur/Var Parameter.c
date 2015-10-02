// Program      : Var Parameter
// Programmer   : Hierony Manurung
// Begin        : 11 Juni 2013, 11:58
// Finish       : -

#include<stdio.h>
int main()
{
 int a,b;
 int temp;
 scanf("%d %d",&a,&b);
 temp = b;
 b = a;
 a = temp;
 
 printf("%d %d\n",a,b);
 return 0;   
}
