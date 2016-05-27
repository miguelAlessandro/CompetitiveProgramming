#include <iostream>
#include <cstdio>
#define N 1010
#define M 1000000007

using namespace::std;

int dp[N],
    n, p[N];

int main(){  

    scanf("%d", &n);

    int r = 0;
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &p[i]);
        dp[i] = 2;
        for(int j = p[i] - 1; j < i; ++j)
            dp[i] = (dp[i] + dp[j])%M;
        r = (r + dp[i])%M;
    }
        
    printf("%d\n", r);

    return 0;
}
