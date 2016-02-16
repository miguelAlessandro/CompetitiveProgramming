#include <iostream>
#include <vector>
#include <cstdio>

using namespace::std;

int n, m;
int v; 
vector<bool> dp(1010), _dp(1010);

int main(){

    scanf("%d %d", &n, &m);

    if(n > m){puts("YES"); return 0;}

    for(int i = 0; i < n; ++i){

        scanf("%d", &v);
        v %= m;
        for(int j = 0; j < m; ++j)
            if(_dp[j])
                dp[(j + v)%m] = true;
        
        dp[v] = true;

        _dp = dp;

        if(dp[0]) {puts("YES"); return 0;}
    }   
    puts("NO");

    return 0;
}
