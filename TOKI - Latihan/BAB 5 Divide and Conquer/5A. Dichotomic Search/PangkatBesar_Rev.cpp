#include<cstdio>
#include<sstream>
#include<cstring>

using namespace std;

typedef long long ll;
ll hasil;
//int modulus = 1000000;

ll PangkatBesar(int base, int pangkat)
 {
 	if(pangkat == 1) return base % 1000000;
 	
	else
	{
		if(pangkat % 2 == 0)
		{
		  hasil = PangkatBesar(base,pangkat/2);
		  return (hasil % 1000000) * (hasil % 1000000) % 1000000;	
		}
		else if(pangkat % 2)
		{
			 hasil = PangkatBesar(base,pangkat/2);
		  	return (hasil % 1000000) * (hasil % 1000000) * (base % 1000000) % 1000000; 
		}
	}	  
 }

int main()
 {
 	ll A,B,temp;
 	scanf("%lld %lld",&A,&B);	
 	//printf("%lld\n",PangkatBesar(A,B));
 	
	// Added
	 
    temp = PangkatBesar(A,B);
         
    string store;
    stringstream strstream;
     
    strstream << temp;
    strstream >> store;
     
    int b;
    
    ll cek = 1;
    int status = 0;
    while(B--)
    {
    	cek *= A;
    	//printf("%lld\n",cek);
    	if(cek > 999999)
    	{
    	//	printf("Masuk\n");
    		status = 1;
    		break;
    	}
    }
    //long n;
    //printf("Cek : %lld\n",cek);
    //printf("temp : %lld\n",temp);
	long n =  store.length(); 
   
   	if(temp == 0) printf("000000\n");
    
   else if(temp <= 999999 && status == 0)
	{
		//printf("Masuk\n");
		printf("%lld\n",temp);
	}
	
   else if(n <= 6)
	{
		for(b = n; b < 6; b++)
		{
			printf("0");
		}
		printf("%lld\n",temp);
	}

	return 0;
 }
