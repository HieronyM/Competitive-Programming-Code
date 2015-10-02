#include<stdio.h>

/*int banyakPecahan(int uang, int hargaPecahan)
  {
                      
  }

*/
int main()
  {
   int K;
   scanf("%d",&K);
   
   int hasil=0;
   while(K != 0)
    {
     //hasil = 0;
     if(K >= 1000)
       {
        hasil =K/ 1000;
        K %= 1000;
        printf("1000 %d\n",hasil);    
       }
     else if(K >= 500)
       {
        hasil =K/ 500;
        K %= 500;
        printf("500 %d\n",hasil);    
       }
     else if(K >= 200)
       {
        hasil =K/ 200;
        K %= 200;
        printf("200 %d\n",hasil);    
       }
     else if(K >= 100)
       {
        hasil =K/ 100;
        K %= 100;
        printf("100 %d\n",hasil);    
       }
     else if(K >= 50)
       {
        hasil =K/ 50;
        K %= 50;
        printf("50 %d\n",hasil);    
       }
     else if(K >= 20)
       {
        hasil =K/ 20;
        K %= 20;
        printf("20 %d\n",hasil);    
       }
     else if(K >= 10)
       {
        hasil =K/ 10;
        K %= 10;
        printf("10 %d\n",hasil);    
        }
      else if(K >= 5)
       {
        hasil =K/ 5;
        K %= 5;
        printf("5 %d\n",hasil);    
       }
       else if(K >= 2)
       {
        hasil =K/ 2;
        K %= 2;
        printf("2 %d\n",hasil);    
       }
       else if(K >= 1)
       {
        hasil =K/ 1;
        K %= 1;
        printf("1 %d\n",hasil);    
       }          
    }
    return 0;     
  }
