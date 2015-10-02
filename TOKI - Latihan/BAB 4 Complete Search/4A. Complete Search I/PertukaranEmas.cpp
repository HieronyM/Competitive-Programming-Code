#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;								

int HasilPenukaranEmas(int nilai)
{  	
	int total = 0;
   if(nilai == 0 )
     {
       return total;
 	}
 	
   else
   {
    total = total + max(nilai, (HasilPenukaranEmas(nilai/2) + HasilPenukaranEmas(nilai/3) + HasilPenukaranEmas(nilai/4)));
    return total;
   }
}


int main()
{
   int N;
   int total;
   scanf("%d",&N);
   
   total = HasilPenukaranEmas(N);
   printf("%d\n",total);   
  return 0;
}
