// Program      : Array
// Programmer   : Hierony Manurung
// Begin        : 12 Juni 07:50
// Finish       : 12 Juni 07:58

#include<stdio.h>
int input[25000]; 

int main()
{
  
  int a=0;
  while(scanf("%d",&input[a])!=EOF)
      {
       a++;                            
      }
  a--;   
  while(a >=0)
     {
      printf("%d\n",input[a]);
      a--;    
     }   
 return 0;   
}
