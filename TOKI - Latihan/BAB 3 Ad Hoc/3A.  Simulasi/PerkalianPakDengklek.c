        //  Program     :   Perkalian Pak Dengklek
        //  Programmer  :   Hierony Manurung
        //  Begin       :   23 Okt 2013, 23:04
        //  Finish      :   23 Okt 2913, 23:52
        
#include<stdio.h>
int main()
{
    long A,B;
    scanf("%ld %ld",&A,&B);
    
    int pangkat = 1;                     //   Variabel membaca digit A
    int pangkat2 = 1;                    //    Variabel membaca digit B   
        
    while(A % pangkat != A)             // Mencek panjang nilai A
      {
       pangkat = pangkat * 10;     
      }
      pangkat = pangkat / 10;
    while(B % pangkat2 !=B)             // Menghitung panjang nilai B
      {
       pangkat2 = pangkat2*10;     
      }
      pangkat2 = pangkat2 / 10;
      
      
    int total=0,X,Y;                                  //      Untuk pemrosesan jumlah perkalian
    int tempB = B,tempPangkat2 = pangkat2;            //      Untuk variabel penyimpan data si B (agar tidak berubah)
    while(pangkat >= 1)
        {
            pangkat2 = tempPangkat2;                           //      Menset ulang nilai si B, dan menset ulang pencek digitnya
            B = tempB;
            while(pangkat2 >= 1)
           {
             //printf("**///  Bagian X /////****\n");
             //printf("pangkat = %d\n",pangkat);
             X = A / pangkat;                                  //   Mencek digit di si A
             //printf("X = %d\n",X);
             
             //printf("**///  Bagian Y /////****\n");
             //printf("pangkat2 = %d\n",pangkat2);
             
             Y = B / pangkat2;                                //    Mencek digit di si B
             //printf("Y = %d\n",Y);
             B = B % pangkat2;                               //     Mencek digit selanjutnya di B
             pangkat2 = pangkat2 / 10;                       
             //printf("B = %d\n",B);
             
             //printf("**///  Penghitungan nilai ke total /////****\n"); 
             total = total + (X*Y);                                                          // Menjumlahkan nilai perkalian     
             //printf("%d\n",total);                
           }
           A = A % pangkat;                         // Menset nilai A menjadi / 10 nya
           pangkat = pangkat/10;                    // Menset pangkatnya
             
        } 
      
    printf("%d\n",total);  
    return 0;
}      
