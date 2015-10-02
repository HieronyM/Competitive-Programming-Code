#include<stdio.h>
#include<string.h>
  
int countdelta(char x, char y);
int correction(char* s, char* t);
  
int main() {
    /* Input */
    int K;                  //inisiasi jumlah kata dalam kamus
    scanf("%d",&K);         //input jumlah kata
      
    char kamus[5000][414],query[5000];         //inisiasi kata dalam kamus sejumlah K, dan query
    int i,l;
      
    for (i=0; i<K; i++) {
        scanf("%s",kamus[i]);             //memasukkan kata dalam kamus
    }
    scanf("%s",query);                    //memasukkan query
      
    /* Algo */
    char temp[5000];         //variabel untuk menampung query per huruf
    int j,min,cek,indeks;
      
    l=strlen(query);        //hitung panjang query
    for (i = 0; i < l; i++) {   //pengetikan huruf dilakukan sebanyak panjang query
           for (j = i; j >= 0; j--) {
                  temp[j]=query[j];            //menampung huruf yang telah diketik
        }
        temp[i+1]='\0';
          
        for (j = 0; j < K; j++) {            //looping untuk membandingkan query dengan kamus
            if (strlen(temp) > strlen(kamus[j])) {
               continue;
            }
            else {
               cek = correction(temp,kamus[j]);
               if (j==0) {
                  min=cek;
                  indeks=j;
               }
               else if (cek < min) {
                  min=cek;
                  indeks=j;
               }
            }
        }
        for (j=0; j<=i; j++) {
            printf("%c",kamus[indeks][j]);
        }
        printf("\n");
    }
    return 0;
}
  
/* Fungsi */
int countdelta(char x, char y) {
    int indx,indy,i,temp;
    char abjad[26]="abcdefghijklmnopqrstuvwxyz";
      
    for (i=0; i<26; i++) {
        if (x==abjad[i]) {
           indx=i;
        }
        if (y==abjad[i]) {
           indy=i;
        }
    }
    if (indx < indy) {
       i=indy;
       indy=indx;
       indx=i;
    }
    i=indx-indy;
    temp=26-indx+indy;
    if (i<temp) {
       return i;
    }
    else {
       return temp;
    }
}
  
int correction(char* s, char* t) {
    int i,delta,sum;
    i=sum=0;
    while (s[i] != '\0') {
        delta=(countdelta(s[i],t[i]));
        sum=sum+delta;
        i++;
    }
    return sum;
}
