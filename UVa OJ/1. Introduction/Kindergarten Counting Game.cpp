#include<cstdio>
#include<iostream>
#include<cstring>
#include<string.h>

using namespace std;
string data;
int counter,next,i;

bool cek(char karakter)
 {
 	if ( ((karakter>=65 && karakter<=90) || (karakter>=97 && karakter<=122)) && next == 0 ) return true;
 	
	else return false;		
 }

int main()
 {
 	
 	while(getline(cin,data))
 	{
 		next = 0;
 		counter = 0;
 		i = 0;
 		
 		while(data[i] != '\0')
 		{
 			
		  if (cek(data[i]))
 			{
 				counter++;
 				next = 1;
 			}
 		
		  else if(! ( (data[i]>=65 && data[i]<=90) || (data[i]>=97 && data[i]<=122)) )
		   {
		   	next = 0;
		   }	
		 
		   i++;
 		}
 		
 		printf("%d\n",counter);
 	}
 }
