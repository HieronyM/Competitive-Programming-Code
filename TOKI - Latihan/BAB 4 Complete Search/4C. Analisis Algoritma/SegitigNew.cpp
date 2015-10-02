#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
 
int main()
{
    int n;
    double x[303], y[303], s1, s2, s3, r,luas_min, luas,d1,d2;
    bool sama = false,ada=false;
    luas_min = 1000000000;
    cin>>n;
    for (int i = 1; i<=n ; i++) cin>>x[i]>>y[i];
   
    for (int i = 1; i<= n-2;i++)
    {
        for (int j = i+1; j<= n-1; j++)
        {
            for (int k = j+1; k<=n; k++)
            {
                d1 = (x[i]*y[j])+(x[j]*y[k])+(x[k]*y[i]);
 	   	   	 	d2 = (x[i]*y[k])+(x[j]*y[i])+(x[k]*y[j]);
 	   	   	 	luas = abs(d1-d2)/2;
                if (luas==luas_min) sama = true;
                if (luas<luas_min && luas>0.0)
                {
                                  ada = true;
                                  sama = false;
                                  luas_min = luas;
                }
            }
            
        }
    }
    cout<<fixed<<setprecision(2);
    if (ada==true && sama==false) cout<<luas_min<<endl; else cout<<"-1.00\n";
    return 0;
}
