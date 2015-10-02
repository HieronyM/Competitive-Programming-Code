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
    char x[105];
    sprintf(x,"%d",a);
    string s = x;
    return s;
}

inline int StringToInt(string a)
{
    char x[105];
    int res;
    strcpy(x,a.c_str());
    sscanf(x,"%d",&res);
    return res;
}

inline string GetString(void)
{
    char x[105];
    scanf("%s",x);
    string s = x;
    return s;
}

int main()
{
    int TC;
    sI(TC);

    REP(a,TC){
       int N;
       sI(N);

       vii data;
       int elapsedAll = 0;
       REP(b,N){
          int temp1,temp2;
          sID(temp1,temp2);

          data.pb(mp(temp2,temp1));
       }

        sort(ALL(data));

        int elapsedMain = data[N-1].second;
        elapsedAll =  data[N-1].first + data[N-1].second;
        for(int i = N-2; i >= 0; i--){
            elapsedMain += data[i].second;
            elapsedAll = max (elapsedAll, elapsedMain + data[i].first);
        }

        printf("%d\n",elapsedAll);
    }

    return 0;
}
