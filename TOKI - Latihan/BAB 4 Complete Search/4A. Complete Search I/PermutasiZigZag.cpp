 //  Menggambar Pegunungan
 
 #include<cstdio>
 #include<algorithm>
 #include<iostream>
 
 using namespace std;
 
 int main()
   {
    int N;
    scanf("%d",&N);
    
    int data[N],a,b;
    
    // Generate the value first
    for(a = 0; a < N; a++)
       {
		data[a] = a+1;
	   }
	
	int count  =1,status;
	do
      {
      	status = 0;
      	//printf("%d %d %d\n",data[0],data[1],data[2]);
	   for(a=1; a < N-1; a++)
	     {
	     	// Kondisi lebih besar
		   if(data[a] > data[a-1])
		     {
			   if(data[a] < data[a+1])
			     {
			     	status = 1;
					break;
			     }
			 }
			 
			 // Kondisi lebih kecil
			else if(data[a] < data[a-1])
		     {
			   if(data[a] > data[a+1])
			     {
			     	status = 1;
					break;
			     }
			 } 
		 }
		 
		 //printf("--------Status : %d--------\n",status);
		 if(status == 0)
		   {
		    for(b = 0 ; b < N; b++)
		      {
			   printf("%d",data[b]);
			  }
			  printf("\n");
		   }
		
		// The Permutations is true
	//	printf("%d\n",count);
		count++;
	  }
    while(next_permutation(data,data+N));
   
    return 0;
   }
