#include <iostream>
#include <cstdio>
#define N 1010
#define M 1000000007

using namespace::std;

int dp[N], //dp a cero
    n, r, p[N]; //r en cero


int main(){  

    scanf("%d", &n);

    for(int i = 1; i <= n; ++i)
        scanf("%d", &p[i]);
    

    for(int i = 1; i <= n; ++i)
    {
        dp[i] = 2;
        for(int j = p[i]; j < i; j++)
            dp[i] = (dp[i] + dp[j])%M;
        r = (r + dp[i])%M;
    }

    printf("%d\n", r);

    return 0;
}
