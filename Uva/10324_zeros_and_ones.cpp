#include <iostream>
#define N 1000005

using namespace::std;

int C[N], 
    n, t;

int main( void ){

    string A;

    t = 0;
    while(cin >> A && A.length() > 0){
    
        C[0] = 0;
        for(int i = 1; i <= A.length(); i++)
            C[i] = C[i-1] + (A[i-1] - '0');

        t++;
        cout << "Case " << t << ":" << endl;
        cin >> n;
        while(n--){
            int a, ib;
            cin >> a >> b;
            if(C[b+1] - C[a] == 0 || C[b+1] - C[a] == b - a + 1) 
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }

    return 0;
}
