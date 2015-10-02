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

vstr data;
int R,C;
pii trophyPos,HarryPos;

// (0,0) is dummy
int dr[8] = {0,0,0,1,-1};
int dc[8] = {0,-1,1,0,0};

int BFS(pii Harry){
    queue < pii > movement;
    int layer = 0;
    movement.push(Harry);

    while(!movement.empty()){
        layer++;
        int sizey = movement.size();

        for(int i = 1; i <= sizey; i++){
            pii temp = movement.front();
            movement.pop();

            for(int j = 1; j <= 4; j++){
                int tempR = temp.first + dr[j];
                int tempC = temp.second + dc[j];

                if( (tempR > 0 && tempR <= R ) && (tempC > 0 && tempC <= C ) ){

                    if(data[tempR][tempC] == 'P'){
                        movement = queue < pii > ();
                        return layer;
                    }

                    if(data[tempR][tempC] == '.'){
                        movement.push(mp(tempR,tempC));
                        data[tempR][tempC] = '#';
                    }
                }
            }
        }
    }
}

int main()
{
    int TC;
    sI(TC);

    REP(a,TC){
        sID(R,C);
        data.pb("0");

        trophyPos = mp(0,0);
        HarryPos = mp(0,0);

        for(int b = 1; b <= R; b++){
            string temp = GetString();
            temp = "#" + temp;

            data.pb(temp);

            // Mencari Posisi Trophy dan Harry
            if(trophyPos.first == 0 || HarryPos.first == 0 ){
                for(int c = 1; c <= C; c++){
                if(data[b][c] == 'P'){
                      trophyPos = mp(b,c);
                    }

                else if(data[b][c] == 'H'){
                      HarryPos = mp(b,c);
                    }
                }
            }
        }

        int hasil = BFS(HarryPos);
        printf("%d %d %d\n",hasil,trophyPos.first,trophyPos.second);

        data.clear();
    }

    return 0;
}
