#include <iostream>
#include <cstdio>
#define N 1000005

using namespace::std;

int n;
string A;
int dp[N];
bool par;
int cont;

int main( void ){

    cin >> n;
    cin >> A;

    if(n == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    if(A[0] == '1') par = false;
    else par = true;
    
    dp[0] = 1;
    for(int i = 1; i < n; i++)
        if(A[i] - '0' == par)
            dp[i] = dp[i-1] + 1, par = not par;
        else
            dp[i] = dp[i-1];

    for(int i = 1; i < n - 1; i++)
        if(A[i-1] == '0' and A[i] == '0' and A[i+1] == '0')
        {
            cout << dp[n-1] + 2 << endl;
            return 0;
        }

    if(A[0] == '0' and A[1] == '0')
        cout << dp[n-1] + 1 << endl;
    else if(A[n-2] == '0' and A[n-1] == '0')
        cout << dp[n-1] + 1 << endl;
    else
        cout << dp[n-1] << endl;

    return 0;
}
