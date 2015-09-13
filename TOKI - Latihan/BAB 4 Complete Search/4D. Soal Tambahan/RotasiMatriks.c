#include<stdio.h>
int Data1[77][77],Data2[77][77],status=-1,found;
int a,b,N,M,k,l;

// Membuat Fungsi
int satu()
 {
 	//printf("Status saat ini : %d\n",status);
 	for(a = 0; a < N; a++)
 	   {
 	   	for(b = 0; b < M; b++)
 	   	 {
 	   	 	if(Data1[a][b] != Data2[a][b])
 	   	 	  {
 	   	 	  	return status;
 	   	 	  }
 	   	 }
 	   }
 	   found = 0;
 	   status = 0;
 	   return found;
 }

int dua()
 {
 	for(a = 0; a < N; a++)
 	   {
 	   	for(b = 0; b < M; b++)
 	   	 {
 	   	 	if(Data1[N-b-1][a] != Data2[a][b])
 	   	 	  {
 	   	 	  	return status;
 	   	 	  }
 	   	 }
 	   }
 	   found = 1;
 	   status = 0;
 	   return found;
 }
 
int tiga()
 {
 //	printf("Masuk\n");
 for(a = 0; a < N; a++)
 	   {
 	   	for(b = 0; b < M; b++)
 	   	 {
 	   	 	if(Data1[N-a-1][N-b-1] != Data2[a][b])
 	   	 	  {
 	   	 	  	return status;
 	   	 	  }
 	   	 }
 	   }
 	   found = 2;
 	   status = 0;
 	   return found;
 } 
 
int empat()
 {
 for(a = 0; a < N; a++)
 	   {
 	   	for(b = 0; b < M; b++)
 	   	 {
 	   	 	if(Data1[b][N-a-1] != Data2[a][b])
 	   	 	  {
 	   	 	  	return status;
 	   	 	  }
 	   	 }
 	   }
 	   found = 3;
 	   status = 0;
 	   return found;
 } 

int main()
 {
 	scanf("%d %d",&N,&M);
 	
 	for(a = 0; a < N; a++)
 	 {
 	 	for(b = 0; b < M; b++)
 	 	   {
 	 	   	scanf("%d",&Data1[a][b]);
 	 	   }
 	 }
 	 
 	scanf("%d %d",&N,&M); 
 	for(a = 0; a < N; a++)
 	 {
 	 	for(b = 0; b < M; b++)
 	 	   {
 	 	   	scanf("%d",&Data2[a][b]);
 	 	   }
 	 }
   // Manggil fungsi	  
   satu();
   if(status == -1) 
    {
      dua();
      if(status == -1) 
	    {
	    	tiga();
	    	if(status == -1)
	    	{
	    		empat();
	    	}
	    }
    }
   
   //printf("status Akhir : %d\n",status);
   
   if(status == -1) printf("tidak sama\n");
   else printf("%d\n",found * 90);
     
   return 0;	
 }
