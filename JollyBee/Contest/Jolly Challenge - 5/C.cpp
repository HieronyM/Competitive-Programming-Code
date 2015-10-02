#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<pii,pii> ppi;
typedef pair<LL,LL> pll;
typedef pair<string,string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<LL> vl;
typedef vector<vl> vvl;
typedef vector<string> vstr;
typedef vector<char> vc;
typedef map <int,int> mii;

double PI = acos(-1);

#define REP(i,n) for(int (i) = 0; (i) < (int)(n); (i)++)
#define READ_int(data) scanf("%d",&data);
#define RESET(c,v) memset(c, v, sizeof(c))
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define pb push_back
#define mp make_pair
#define ALL(vec) vec.begin(),vec.end()
#define sI(val) scanf("%d",&val)
#define sID(val,val2) scanf("%d %d",&val,&val2)
#define INF 2123123123

inline string IntToString(int a)
{
    char x[100];
    sprintf(x,"%d",a);
    string s = x;
    return s;
}

inline int StringToInt(string a)
{
    char x[100];
    int res;
    strcpy(x,a.c_str());
    sscanf(x,"%d",&res);
    return res;
}

inline string GetString(void)
{
    char x[1000005];
    scanf("%s",x);
    string s = x;
    return s;
}

// FPB gan
int gcd(int  a, int b)
{
    if(b == 0)return a;
    else return gcd(b,a%b);
}

//kpk gan
int lcm(int a,int b)
{
    return (a*(b/gcd(a,b)));
}

bitset<10000010> bs;
vi primes;

// Prima pertama terdapat di primes[1] yah :D
void sieve(LL upperbound)
{
    bs.set();
    bs[0]=bs[1]=0;
    primes.pb(0);
    for(LL i=2; i<=upperbound+1; i++)if(bs[i])
        {
            for(LL j=i*i; j<= upperbound+1; j+=i)bs[j] = 0;
            primes.pb((int) i);
        }
}

int main()
{
    int TC;
    sI(TC);

    string data[15];
    data[2] = "#ABC";
    data[3] = "#DEF";
    data[4] = "#GHI";
    data[5] = "#JKL";
    data[6] = "#MNO";
    data[7] = "#PQRS";
    data[8] = "#TUV";
    data[9] = "#WXYZ";

    REP(a,TC){
        string kata = GetString();
        int sizey = kata.size();

        printf("Case #%d: ",a+1);
        REP(b,sizey)
        {
            string temp;
            for(int i = 2; i <= 9; i++)
            {
                int ukuran = data[i].size();
                int status = 0;
                for(int j = 1; j <= ukuran; j++){
                    // Jika ketemu, cetak
                    if(kata[b] == data[i][j])
                    {
                        for(int k = 1; k <= j; k++)
                        {
                            printf("%d",i);
                        }

                        status = 1;
                        break;
                    }

                    if(status == 1) break;
                }

                if(status == 1) break;
            }

            if(b != sizey-1) printf(" ");
            else printf("\n");
        }
    }

    return 0;
}
