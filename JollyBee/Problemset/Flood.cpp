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

vstr data;
int dr[8] = {1,-1,0,0};
int dc[8] = {0,0,1,-1};
 int M,N;

void floodfill(int y,int x)
{
    data[y][x] = '#';

    REP(a,4){
        int row = y + dr[a];
        int column = x + dc[a];

        if(row >= 0 && row <= M-1 && column >= 0 && column <= N-1){
            if(data[row][column] == '.') floodfill(row,column);
        }
    }
}
int main()
{
    int TC;
    sI(TC);

    REP(a,TC){
        sID(M,N);

        REP(b,M){
            string temp= GetString();
            data.pb(temp);
        }

        REP(b,M){
            REP(c,N){
                if(data[b][c] == '.'  && (b == 0 || b == M-1  || c == 0 || c == N-1)) floodfill(b,c);
            }
        }


        int status = 0;
        /*printf("Hasil Setelah Floodfill\n");
        REP(b,M) printf("%s\n",data[b].c_str());
        */

        REP(b,M){
            REP(c,N){
                if(data[b][c] == '.'){
                  status = 1;
                  break;
                }
            }
            if(status) break;
        }

        if(status) printf("Case #%d: YA\n",a+1);
        else printf("Case #%d: TIDAK\n",a+1);

        data.clear();

    }

    return 0;
}
