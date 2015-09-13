#include<iostream>
#include<cstdio>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
#include<queue>
#include<deque>
#include<iterator>
#include<assert.h>
#include<bitset>
#include<climits>
#include<ctime>
#include<complex>

using namespace std;

#define SET(a) memset(a,-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define CLR(a) memset(a,0,sizeof(a))
#define PB push_back
#define PI acos(-1.0)
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define READ freopen("input.txt", "r", stdin)
#define WRITE freopen("output.txt", "w", stdout)
#define LL long long

#define S(a) scanf("%d",&a)
#define S2(a,b) scanf("%d%d",&a,&b)
#define KS printf("Case %d: ",kk++)

#define MOD 1000000007
#define MX 100010

struct Z{
        int a,b;
        bool operator < (const Z &p) const{
        return b>p.b;
        }
};

int main()
{
    int a,b,c,w,x,y,n,m,u,cnt,mx,mn,p,q,r,sum,kk=1;
    string s,s2;
    vector<Z>v;
    Z z;
    while(cin>>n && n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>x>>y;
            z.a=x;
            z.b=y;
            v.push_back(z);
        }
        sort(v.begin(),v.end());
        //for(int i=0;i<v.size();i++) cout<<v[i].b<<endl;
        int rem=0;
        sum=0;
        int vl=v.size();
        
        for(int i=0;i<vl;i++)
        {
        	printf("v[%d].first :  %d\n",i,v[i].a);
        	printf("v[%d].second :  %d\n",i,v[i].b);
    	}
        
        printf("-----------------------\n");
        for(int i=0;i<vl;i++)
        {
            sum+=v[i].a;
            printf("[%d]Sum : %d\n",i,sum);
            rem-=v[i].a;
            printf("[%d]RemSebelum : %d\n",i,rem);
			
			rem=max(rem,v[i].b);
            printf("[%d]RemSesudah : %d\n",i,rem);
        }
        sum+=rem;
        cout<<"Case "<<kk++<<": "<<sum<<endl;
        v.clear();
    }
    return 0;
}
