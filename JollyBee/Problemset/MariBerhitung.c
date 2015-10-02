#include<stdio.h>

int main()
  {
   int TC;
   scanf("%d",&TC);
   
   int p;
   unsigned long long int A,B,N,M;                         // input variabel
   int banyakPembagi,rentangBawah,kelipatanNM,kelipatanNM2;                        
   
   unsigned long long int Total,Total2,Total3,Total4;        // Penampung totalNilai
   for(p=1; p<=TC; p++)
     {
      Total = 0;
      Total2 = 0;
      Total3 = 0;
      Total4 = 0;
      scanf("%lld %lld %lld %lld",&A,&B,&N,&M);
      
      /************* Kelipatan N *************/
      banyakPembagi = B/N;
      if(banyakPembagi %2 ==  0)
        {
         banyakPembagi = ((banyakPembagi/2) * (1 + banyakPembagi));
         Total += (N * banyakPembagi);        
        }
      
      else
        {
         banyakPembagi = (banyakPembagi * ((1 + banyakPembagi)/2));
         Total += (N * banyakPembagi);        
        }
        
        // Kurangi dengan yang rentang bawah    
       rentangBawah = (A-1)/N;
       if(rentangBawah %2 ==  0)
        {
         rentangBawah = ((rentangBawah/2) * (1 + rentangBawah));
         Total2 += (N * rentangBawah);        
        }
      
      else
        {
         rentangBawah = (rentangBawah * ((1 + rentangBawah)/2));
         Total2 += (N * rentangBawah);        
        }
        
        /************* Kelipatan N * M *************/
        // Kurangi dengan kelipatan N * M
       kelipatanNM = B / (N*M);
       if(kelipatanNM %2 ==  0)
        {
         kelipatanNM = ((kelipatanNM/2) * (1 + kelipatanNM));
         Total3 += ((N*M) * kelipatanNM);        
        }
      else
        {
         banyakPembagi = (kelipatanNM * ((1 + kelipatanNM)/2));
         Total3 += ((N*M) * kelipatanNM);        
        }
        
         // Bagian bawah kelipatan N*M
        kelipatanNM2 = (A-1) / (N*M);
       if(kelipatanNM2 %2 ==  0)
        {
         kelipatanNM2 = ((kelipatanNM2/2) * (1 + kelipatanNM2));
         Total4 += ((N*M) * kelipatanNM2);        
        }
      
      else
        {
         banyakPembagi = (kelipatanNM2 * ((1 + kelipatanNM2)/2));
         Total4 += ((N*M) * kelipatanNM2);        
        }
        // Debug
        printf("Total1 : %lld\n",Total);
        printf("Total2 : %lld\n",Total2);
        printf("Total3 : %lld\n",Total3);
        printf("Total4 : %lld\n",Total4);
        
        
        Total = Total - (Total2 + (Total3 - Total4));
        printf("%lld\n",Total);         
     }
        return 0;
  }
