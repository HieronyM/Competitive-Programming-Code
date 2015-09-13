//  Program     :  Bukit dan Lembah
//  Programmer  :  Hierony Manurung
//  Begin       :  24 Oktober 2013, 05:52
//  Finish      :  


#include<stdio.h>
int tinggi[600000];
int main()
 {
   int a=0;
   while(scanf("%d",&tinggi[a]) !=EOF)         
   {
      a++;          
   }
   
   int b;
   int X = tinggi[0];
   int Y = tinggi[1];
   int state;                              //   State 0 = menurun,     State  1 = menaik  
   int rentangTinggi;                      //   Rentang tinggi paling besar
   int tempRentangTinggi                   //   Penampung Smenetara rentangTinggi
   
   if(X < Y)                               // Kondisi awal yang menaik
   {
     state = 0;
     rentangTinggi = Y-X;   
   }
   
   else if(X > Y)                          //  Kondisi awal yang menurun
   {
    state = 1;
    rentangTinggi = X - Y;    
   }
   
   
   for(b=2; b<a ; b++)
   {
     if(Y < tinggi[b] && state == 0)                                                      // Keadaan Turun
     {
       state = 0;
       rentangTinggi = rentangTinggi + (tinggi[b] - Y);     
     }
     else if(Y > tinggi[b] && state == 1)
     {
          state = 1;
          rentangTinggi = rentangTinggi;              
     }
     
     else if (Y == tinggi[b])                               // Lanjut saja jika tinggi sama, namun state tetap diingat :D
     {
       state = state;
     }
     Y = tinggi[b];                                   //   Menampung nilai selanjutnya yang akan dicek   
   }

   getch();
   return 0;       
 }
