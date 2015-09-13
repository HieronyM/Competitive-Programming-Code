#include<stdio.h>

char gambar[500][500];
int main()
 {
  int N,M;                //  Banyak Testcase
  scanf("%d %d",&N,&M);
  //char gambar[N+2][M+2];
  int a;
  for(a = 0; a < N; a++)
     {
      scanf("%s",&gambar[a]);
	 }

  // Melakukan Proses Pencarian Posisi kucing dan Bebek
  int KolBebek,RowBebek;		// Posisi Bebek (Kol = idx Kolom, Row = idx Row)
  int KolKucing,RowKucing;		// Posisi Kucing (Kol = idx Kolom, Row = idx Row)
  int b;						// Variabel looping
  int status=0;					// Jika status sudah 2 (Bebek dan Kucing ketemu) kita Break proses pencarian
  for(a = 0; a < N; a++)
     {
      for(b=0; b < M ; b++)
        {
        
        // Ketemu Posisi Bebek
		 if(gambar[a][b] == 'B')
		 {
		 	KolBebek = b;
		 	RowBebek = a;
		 	status++;
		 }
		 
		 if(gambar[a][b] == 'K')
		  {
		  	KolKucing = b;
		  	RowKucing = a;
		    status++;
		  }
 		}
 		
 		// Hentikan Proses Pencarian
 		if(status == 2)
 		  {
 		  	break;
 		  }
	 }
  
  // Melakukan Proses perhitungan Luas Di kanan dan Kiri 
  
  /******** Bebek ******/
  int Kiri,Kanan, Atas,Bawah; 
  Kiri = Kanan = Atas = Bawah = 0; 
  // Kiri
  for(b= KolBebek ; b >= 0; b--)
    {
    	// Tambahkan Luas sisinya
	 if(gambar[RowBebek][b] == '.' )
	   {
	   	Kiri++;
	   }
	   
	   // jangan cari lagi karena ketemu batu
	 if(gambar[RowBebek][b] == '#')
	   {
	   	break;
	   }  
	}
	
	// Kanan
	for(b= KolBebek ; b < M ; b++)
    {
    	// Tambahkan Luas sisinya
	 if(gambar[RowBebek][b] == '.' )
	   {
	   	Kanan++;
	   }
	   
	   // jangan cari lagi karena ketemu batu
	 if(gambar[RowBebek][b] == '#')
	   {
	   	break;
	   }  
	}

  /* Seperti Atas dan Bawah tidak diperlukan
   // Atas
	for(b= RowBebek ; b >= 0; b--)
    {
    	// Tambahkan Luas sisinya
	 if(gambar[b][KolBebek] == '.' )
	   {
	   	Atas++;
	   }
	   
	   // jangan cari lagi karena ketemu batu
	 if(gambar[b][KolBebek] == '#')
	   {
	   	break;
	   }  
	}
	
	// Arah Bawah
	for(b= RowBebek ; b < N; b++)
    {
    	// Tambahkan Luas sisinya
	 if(gambar[b][KolBebek] == '.' )
	   {
	   	Bawah++;
	   }
	   
	   // jangan cari lagi karena ketemu batu
	 if(gambar[b][KolBebek] == '#')
	   {
	   	break;
	   }  
	}
	*/
	
	int luasDaerahBebek=0,i;
	   for(a= KolBebek - Kiri; a <= KolBebek + Kanan; a++)
	     {
	     	  i = RowBebek;
	     	  // Ngecek ke atas
	     	  while(gambar[i][a] != '#')
	     	  {
			   // Ketemu batu, sudahi perhitungan di Satu Baris
	     	 	luasDaerahBebek++;
	     	 	if(i == 0)
	     	 	  {
	     	 	  	break;
	     	 	  }
				i--;
	 	   	  }
	 	   	  
	 	   	  // Refresh Value
	 	   	  i = RowBebek;
	 	   	  // Ngecek ke bawah
	 	   	  while(gambar[i+1][a] !='#')
	     	  {
			   // Ketemu batu, sudahi perhitungan di Satu Baris
	     	 	luasDaerahBebek++;
	     	 	if(i == N)
	     	 	  {
	     	 	  	break;
	     	 	  }
				i++;	
	 	   	  }
	   	  printf("-- Bebek Di Kolom ke %d, Banyak luas : %d\n",a,luasDaerahBebek);
		 }
	
	// jUST dEBUGGING;
	
	
	printf("Posisi Bebek berada di titik : %d,%d\n",RowBebek,KolBebek);
	printf("Atas : %d\n Bawah : %d\n Kiri : %d\n Kanan : %d\n",Atas,Bawah,Kiri,Kanan);
	printf("%d\n",luasDaerahBebek);
	
	
	// Melakukan Proses perhitungan Luas Daerah 
   // Melakukan Proses perhitungan Luas Daerah 
  
  /******** Kucing ******/
  Kiri = Kanan = Atas = Bawah = 0; 
  // Kiri
  for(b= KolKucing ; b >= 0; b--)
    {
    	// Tambahkan Luas sisinya
	 if(gambar[RowKucing][b] == '.' )
	   {
	   	Kiri++;
	   }
	   
	   // jangan cari lagi karena ketemu batu
	 if(gambar[RowKucing][b] == '#')
	   {
	   	break;
	   }  
	}
	
	// Kanan
	for(b= KolKucing ; b < M ; b++)
    {
    	// Tambahkan Luas sisinya
	 if(gambar[RowKucing][b] == '.' )
	   {
	   	Kanan++;
	   }
	   
	   // jangan cari lagi karena ketemu batu
	 if(gambar[RowBebek][b] == '#')
	   {
	   	break;
	   }  
	}
	
	int luasDaerahKucing=0;
	   for(a= KolKucing - Kiri; a <= KolKucing + Kanan; a++)
	     {
	     	  i = RowKucing;
	     	  // Ngecek ke atas
	     	  while(gambar[i][a] != '#')
	     	  {
			   // Ketemu batu, sudahi perhitungan di Satu Baris
	     	 	luasDaerahKucing++;
	     	 	if(i == 0)
	     	 	{
	     	 		break;
	     	 	}
				i--;
	 	   	  }
	 	   	  
	 	   	  // Refresh Value
	 	   	  i = RowKucing;
	 	   	  // Ngecek ke bawah
	 	   	  while(gambar[i+1][a] !='#')
	     	  {
			   // Ketemu batu, sudahi perhitungan di Satu Baris
	     	 	luasDaerahKucing++;
	     	 	if(i == N)
	     	 	{
	     	 		break;
	     	 	}
				  i++;
	 	   	  }
	 	   	  printf("--Kucing Di Kolom ke %d, Banyak luas : %d\n",a,luasDaerahKucing);
		 }
	
	
	// jUST dEBUGGING;
	
	printf("\nPosisi Kucing berada di titik : %d,%d\n",RowKucing,KolKucing);
	printf("Atas : %d\n Bawah : %d\n Kiri : %d\n Kanan : %d\n",Atas,Bawah,Kiri,Kanan);
	printf("%d\n",luasDaerahKucing);
	
	
	// Penentuan Hasil
	if(luasDaerahBebek > luasDaerahKucing)
	  {
	  	printf("B %d\n",luasDaerahBebek-luasDaerahKucing);
	  }
	 else if(luasDaerahBebek < luasDaerahKucing)
	  {
	  	printf("K %d\n",luasDaerahKucing-luasDaerahBebek);
	  }
	 else
	  {
	  	printf("SERI\n");
	  }  
	
  return 0;        
 }
