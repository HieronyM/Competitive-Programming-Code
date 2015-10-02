#include<cstdio>
#include<cstring>
#include<queue>
 
using namespace std;
 
queue <int> Q;
int jumlah[1002],head = -1,tail = -1,tempRev[1002],tempjumlah[1002],size = 0;
int a,nilai,nBilangan,temp;
void Add(int x, int y)
   {     
    size += y;
    printf("%d\n",size);
    
    if(head == -1) 
	{
	  head++;
	}
    
    tail++;
    Q.push(x);
    jumlah[tail] = y;
   }
    
void Del(int x)
{
    printf("%d\n",Q.front());
    //printf("(Sebelum) Head : %d Tail : %d\n",head,tail);
    size -= x;
	for(a = head; a <= tail ; a++)
    {
    //	printf("Jumlah [a] : %d X : %d\n",jumlah[a],x);
        temp = jumlah[a];
        jumlah[a] -= x;
        if(jumlah[a] <= 0)
        {   
         jumlah[a] == 0;
         Q.pop();
         head++;
         x -= temp;
        }   
        else if(jumlah[a] > 0)
        {
            break;
        }
    }
    
   // printf("(Sesudah) Head : %d Tail : %d\n",head,tail);
}    
 
void Rev()
{
  int count = head,store;
  for(a = tail; a >= head; a--)
  {
    store = Q.front();
    Q.pop();
    tempRev[a] = store;
    tempjumlah[count] = jumlah[a]; 
    count++;
  }
   
  for(a = head; a <= tail; a++)
  {
    Q.push(tempRev[a]);
    jumlah[a] = tempjumlah[a];
  } 
}
 
using namespace std;
     
   int main ()
 {
    int TC;
    scanf("%d",&TC);
    char perintah[12];
     
    while(TC--)
    {
        scanf("%s %d",&perintah,&nilai);    
         
        // Bagian Memasukkan Data       
        if(strcmp (perintah, "add") == 0)
          {
            scanf("%d",&nBilangan);
            Add(nilai,nBilangan);
          }
       else if(strcmp (perintah, "del") == 0) Del(nilai);   
       else if(strcmp (perintah, "rev") == 0) Rev();    
 
    }
   	
	 // Debugging   
    /*for(a = head; a <= tail; a++)
     {
     	printf("bilangan %d jumlah : %d\n",Q.front(),jumlah[a]);
     	Q.pop();
     }
     */
    return 0;
 }
