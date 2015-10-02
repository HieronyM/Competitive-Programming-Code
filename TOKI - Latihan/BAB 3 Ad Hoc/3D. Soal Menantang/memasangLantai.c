
    #include <stdio.h>     
    unsigned long long int data[1010];
     
    int main()
    {
        /* Setting data yang ditahu (Dari Pola)*/
        int N,a;
        data[1] = 1;
        data[2] = 1;
        data[3] = 2;
        data[4] = 3;
        data[5] = 4;
        data[6] = 6;
        data[7] = 9;
        
        /* N = Merepresentasikan panjang */
        scanf("%d",&N);
        for(a = 8; a <= N; a++)
          {
           data[a] = (data[a-1] + data[a-3]) %1000000;
           }
           
        /*if(data[N] <= 999999)
        { 
          printf("%lld\n",data[N]);
        }
        else 
        { 
         */
          printf("%lld\n",data[N]%1000000);
        //}
        return 0;
}

