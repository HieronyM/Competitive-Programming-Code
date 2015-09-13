#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int counter;
int main()
 {
 	counter = 1;
 	string input;
 	while(1)
 	{
 		//scanf("%s",&input);
 		getline(cin,input);
		if(input == "#") break;
 		
 		else
 		{
 			if(input == "HELLO") printf("Case %d: ENGLISH\n",counter);
 			else if(input == "HOLA") printf("Case %d: SPANISH\n",counter);
 			else if(input == "HALLO") printf("Case %d: GERMAN\n",counter);
 			else if(input == "BONJOUR") printf("Case %d: FRENCH\n",counter);
 			else if(input == "CIAO") printf("Case %d: ITALIAN\n",counter);
 			else if(input == "ZDRAVSTVUJTE") printf("Case %d: RUSSIAN\n",counter);
			else  printf("Case %d: UNKNOWN\n",counter);
		}
 		
 		counter++;
 	}
 	
 	return 0;
 }
