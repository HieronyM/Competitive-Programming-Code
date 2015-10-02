#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;
int input;
string data;
int nilai[11],a;

void refresh()
 {
 	for(a =1; a<=10; a++)
 	{
 		nilai[a] = 1;
 	}
 }
 
 void hapusKanan(int batas)
 {
 	for(a = batas; a <= 10; a++)
	 {
	 	nilai[a] = 0;
	 }	
 }
 
  void hapusKiri(int batas)
 {
 	for(a = batas; a >= 1; a--)
	 {
	 	nilai[a] = 0;
	 }	
 }

int main()
 {
 	// Call for the first time
 	refresh();
 	
 	while(1)
 	{
 		scanf("%d",&input);
 		if(!input) break;
 		
 		getline(cin,data);
 		
 		if(data == "too high")
 		{
 			hapusKanan(input);
 		}
 		
 		else if(data == "too low")
 		{
 			hapusKiri(input);
 		}
 		
 		else if(data == "right on")
 		{
 			if(nilai[input] == 0) printf("Stan is dishonest\n");
 			else printf("Stan may be honest\n");
 			refresh();
 		}
 	}
 	
 	return 0;
 }
