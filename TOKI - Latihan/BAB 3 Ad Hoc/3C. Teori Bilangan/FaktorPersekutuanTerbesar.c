        /*
          Program     :  Faktorisasi Persekutuan Besar (Latihan 3C TOKI)
          Programmer  :  Hierony Manurung
          Start Date  :  3 November 2013, 06:25
          Finish Date :  3 November 2013, 06:40 (Using Euclid Algorithm punya pake )
        */
#include<stdio.h>
int main()
  {
   int T;
   scanf("%d",&T);
   
   long data[T][2],temp,R;
   short int a;
   for(a=0; a<T; a++)
      {
       scanf("%ld %ld",&data[a][0], &data[a][1]);    
       if(data[a][1] > data[a][0] )                        //  Tukar nilai B ke A jika nilai B lebih besar dari A
       {
        temp = data[a][1];                      
        data[a][1] = data[a][0];
        data[a][0] = temp;  
       }

      // printf("\n");
       while(data[a][1] != 0)
        {
         //printf("%ld = %ld x %ld + %ld \t\t gcd(%ld,%ld)\n",A,A/B,B,A%B,B,A%B);
         R = data[a][0] % data[a][1];
         data[a][0] = data[a][1];
         data[a][1] = R;     
         }        
       printf("%ld\n",data[a][0]);
      }
   return 0;       
  }
