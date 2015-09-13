#include <bits/stdc++.h>
using namespace std;

inline string GetString(void){
        char x[1000005];
        scanf("%s",x); string s = x;
        return s;
}

int main()
{
    int TC;
    scanf("%d",&TC);
    vector<int> data (TC+5,0);

    int pos = -1;
    for(int a = 1; a <= TC; a++)
    {
        int value;
        string temp = GetString();

        if(temp == "push")
        {
            scanf("%d",&value);
            if(a != TC) printf("%d\n",value);

            else printf("%d",value);

            pos++;
            data[pos] = value;

        }

        else if(temp == "pop")
        {
            pos--;

            if(a != TC)
            {
                if(pos < 0) printf("EMPTY\n");
                else printf("%d\n",data[pos]);
            }
            else
            {
                if(pos < 0) printf("EMPTY\n");
                else printf("%d\n",data[pos]);
            }
        }

        else if(temp == "inc")
        {
            int val1,val2;
            scanf("%d %d",&val1,&val2);

           // printf("###Posisi Saat ini : %d\n",pos);
            for(int a = 0; a < val1; a++)
            {
                data[a] = data[a] + val2;
            }

            if(a != TC)
            {
                printf("%d\n",data[pos]);
            }
            else
            {
                printf("%d\n",data[pos]);
            }
        }
    }

    return 0;
}
