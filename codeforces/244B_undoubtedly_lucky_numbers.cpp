#include <iostream>
#include <cmath>

using namespace::std;

int n, N;

int backtracking(int T, int bitmask, long long numero, long long decena, int Ndigits){
    if(__builtin_popcount(bitmask) > 2 or numero > n) return 0;
    if(T == Ndigits + 1) return 1;
    int r = 0;
    for(int i = (T == Ndigits); i <= 9; ++i)
        r += backtracking(T+1, bitmask | (1 << i), numero + decena*i, 10*decena, Ndigits);
    return r;
}

int main(){
    
    cin >> n;
    N = log10(n) + 1;
    int r = 0;
    for(int i = 1; i <= N; ++i)
         r += backtracking(1, 0LL, 0LL, 1, i);
    cout << r << endl;

    return 0;
}
