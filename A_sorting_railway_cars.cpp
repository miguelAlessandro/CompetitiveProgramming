#include <iostream>
#include <cstdio>
#define N 1000005

using namespace::std;

int n, a, cont = 0;
int dp[N];

int main( void ){
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        dp[a] += dp[a-1]+1;
        cont = max(cont, dp[a]);
    }
    
    printf("%d\n", n - cont);

    return 0;
}
