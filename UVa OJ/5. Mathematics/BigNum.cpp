#include <iostream>
#include "gmpxx.h"
typedef mpz_class big; 

using namespace std;

//=========================================================
// program:
//
int N;
big t[1000];

big gcd(big A , big B) {
    while (B != 0) {
        big C = B;
        B = A%B;
        A = C;
    }
    return A;
}

big solve() {
    big T = t[0] - t[1];
    for (int i=0; i<N; i++) {
        for (int j=i+1; j<N; j++) {
            T = gcd(T, t[i] - t[j] );
        }
    }
    T = abs(T);
    return (T - t[0] % T) % T;
}


inline void init(){}
//=========================================================
// I/O:
//
int main()
{
    init();
    int C; cin>>C;
    for (int i=1;i<=C;i++)
    {
        cerr<<"["<<i<<" / "<<C<<"]"<<endl;
        cin >> N;
        for (int j=0; j<N; j++){
            cin >> t[j];
        }
        cout<<"Case #"<<i<<": " << solve() << endl; 
    }
    return 0;
}
