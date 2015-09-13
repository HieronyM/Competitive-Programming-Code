#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

vector<string> stringVec;
char temp[22];
std::string str;


int main()
 {
 	int TC,a,b,hasil,i;
 	scanf("%d",&TC);
 	
 	for(a = 1 ; a <= TC; a++)
 	{
 		i = 0;
 		//scanf("\n");
 		//gets(temp); 		
 		cin >> str;
 		std::transform(str.begin(), str.end(), str.begin(), ::toupper);
		stringVec.push_back(str);
		sort(stringVec.begin(), stringVec.end());
		
 	    	for(b = 0 ; b < a; b++)
 			{
 				if(str == stringVec[b])
 				  {
 				  	hasil = b+1;
 				  }			  
 	   		}
 	   		printf("%d\n",hasil);
	}	
 	 return 0;
 }
