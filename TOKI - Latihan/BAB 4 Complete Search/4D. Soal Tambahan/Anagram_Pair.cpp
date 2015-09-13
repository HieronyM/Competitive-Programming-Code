#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
 
using namespace std;
 
string str,tempStr;
int status;


int main()
 { 
    int TC,a,b;
	scanf("%d",&TC);
	pair<string,string> Data[TC];	
     
    for(a = 0; a < TC; a++)
    {
    	cin >> str;
    	tempStr = str;
        sort(str.begin(), str.end()); 
        
        Data[a].first = str;
        Data[a].second = tempStr;
    }
    
    sort(Data, Data + TC);
 	
 	// Proses Mencetak (Debugging)
 	printf("\nCek bilangannya \n");
 	
	for(a = 0; a < TC; a++)
    {	
    	printf("Array Sort[%d]: %s, Array Asli[%d] : %s\n",a,Data[a].first.c_str(),a,Data[a].second.c_str());
	}
	
	
	int count = 1,countMax = 1,index;
	string min,tempSort;
	for(a = 0; a < TC-1; a++)
	{
		// Kondisi Last
		if(Data[a].first == Data[a+1].first)
		{
			count++;
		}
		else
		{
			if(countMax < count)
			{
				countMax = count;
				tempSort = Data[a + 1-count].second;
				index = a+1-count;
				//printf("%s\n",tempSort.c_str());
			}
			else if(countMax == count)
			{
				if(tempSort > Data[a + 1 - count].second)				// Mencek Leksikografis
				{
					//printf("Masuk di a ke [%d]\n",a);
					tempSort = Data[a + 1 - count].second;
					index = a + 1 - count;
				}
			} 
			
			count = 1;
		}
		//printf("[After]kondisi Counter[%d] : %d, CountMax : %d\n",a,count,countMax);
	}
	
	// Memproses Bagian Akhir
	if(countMax < count) 
	{
	  countMax = count;
	  tempSort = Data[a + 1-count].second;
	  index = a+1-count;				
	}
	
	// Kondisi Khusus (untuk mastiin kelompok terakhir)
	if(countMax == count)
		{
			
			printf("%s\n",Data[a + 1 - count].second.c_str());
			//printf("Masuk di a ke [%d]\n",a);
			if(tempSort > Data[a + 1 - count].second)
			{
				//printf("Masuk di a ke [%d]\n",a);
				tempSort = Data[a + 1 - count].second;
				index = a + 1 - count;
			}
		} 
	
	if(countMax == 1) printf("TIDAK ADA\n");
	
	else
	{
		printf("%d\n",countMax);
		for(a = index; a < index+countMax; a++)
		 {
		 	printf("%s\n",Data[a].second.c_str());
		 }
	}
	
	//printf("\nCountMax : %d String Terkecil: %s\n",countMax,tempSort.c_str());
 }
