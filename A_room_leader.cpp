#include <iostream>
#include <cstdio>
#include <climits>
#define N 60

using namespace::std;

string A[N];
int v[N], t, r = INT_MIN, ir,
    p, m, a, b, c, d, e;



int main(){

    ios_base::sync_with_stdio(0);
    
    cin >> t;

    for(int i = 0; i < t; ++i){

        cin >> A[i] >> p >> m >> a >> b >> c >> d >> e;
        
        int test = 100*p - 50*m + a + b + c + d + e;
        if(r < test)
            r = test, ir = i;
    }
    cout << A[ir] << endl;

    return 0;
}
