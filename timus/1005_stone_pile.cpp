#include <iostream>
#include <algorithm>
#include <climits>
#define N 22
using namespace::std;

int n, w[N], suma, solve = INT_MAX;

void backtracking(int T, int bitmask, int acum){
    if(T == n) return;
    solve = min(solve, abs(suma - 2*acum));
    backtracking(T+1, bitmask | (1 << T), acum + w[T]);
    backtracking(T+1, bitmask, acum);
}

int main(){
    
    cin >> n;
    for(int i = 0; i < n; ++i)
        {cin >> w[i]; suma += w[i];}
    backtracking(0, 0, 0);
    cout << solve << endl;

    return 0;
}
