 // Program     : ParkirTruk
 // Programmer  : Hierony Manurung
 // Begin Date  : 2 November 2013, 19:31
 // Finish      : -
 
 #include<stdio.h>
 int main()
  {
    int A,B,C;
    scanf("%d %d %d",&A,&B,&C);         //  Biaya Sewa Truk
    
    int rentangWaktu[3][3],a,max=0,min=100000;
    for(a=0; a<3; a++)
       {
        scanf("%d %d",&rentangWaktu[a][0],&rentangWaktu[a][1]);    // Rentang Waktu tiap truk 
        rentangWaktu[a][0] += 1; // Ditambah 1
        if(min > rentangWaktu[a][0])
          {
            min = rentangWaktu[a][0];   
          }
        if(max < rentangWaktu[a][1])
          {
            max = rentangWaktu[a][1];   
          }  
       }
       //printf("Min : %d \t Max : %d \n",min,max);
       
    int totalBiaya = 0,count=0,b;   
    for(a= min; a<=max; a++)
       {
           for(b=0; b<3; b++)                // Ngecek Selang waktu yang sama 
           {
             if(a == rentangWaktu[b][0])
              {
               count++;   
              }
           }
          // printf("Count : %d\n",count);
           if(count == 1)                       // Cek biaya
             {
              totalBiaya = totalBiaya + A;      
             }
           else if(count == 2)
             {
             totalBiaya = totalBiaya + (2*B);
             }
           else if(count == 3)
             {
               totalBiaya = totalBiaya + (3*C);
             }
           
           for(b=0; b<3; b++)
              {
                if(rentangWaktu[b][0] != rentangWaktu[b][1] && a == rentangWaktu[b][0])
                  {
                  rentangWaktu[b][0]++;
                  }    
              }
              
             count = 0;  
       }
   
    printf("%d\n",totalBiaya);
    
    return 0;        
  }
