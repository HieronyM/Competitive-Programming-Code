#include<stdio.h>
#include<string.h>
int Data[10002],head = - 1,tail = -1,nilai,value,a;
char operasi [12];
 
void push_front(int nilai)
 {
    if(head > 0)
    {
        head--;
        Data[head] = nilai;
    }
     
    else
    {
        if(head == -1) 
        {
            head++;
        }
         
        tail++;
        for(a = tail; a >= 0; a--)
        {
            if(a != 0) Data[a] = Data[a - 1];
            else    Data[a] = nilai;
        }
    }  
 }
 
void push_back(int nilai)
    {
     if(head == -1) 
     {
        head++;
     }
     tail++;
     Data[tail] = nilai;    
    }
 
void pop_front()
    {
     head++; 
    }
 
void pop_back()     
    {
     if(tail == 0)
     {
        head--;
        tail--;
     } 
     else   tail--;
         
    }
 
int main()
 {
    int TC;
    scanf("%d",&TC);
    char perintah[12];
     
    int a;
    while (TC--)
    {       
        scanf("%s",&perintah);  
         
        // Bagian Memasukkan Data       
        if(strcmp (perintah, "push_back") == 0)
          {
            scanf("%d",&value);
            push_back(value);
          }
        else if(strcmp (perintah, "push_front") == 0)
          {
            scanf("%d",&value);
            push_front(value);
          }
               
        // Bagian mengeluarkan Data
        else if(strcmp (perintah, "pop_front") == 0)
          {
            pop_front();
          }
        else if(strcmp (perintah, "pop_back") == 0)
          {
            pop_back();
          }
     }
     for(a = head; a <= tail; a++) printf("%d\n",Data[a]);
    return 0;
 }
