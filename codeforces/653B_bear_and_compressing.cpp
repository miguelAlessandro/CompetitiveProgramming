#include <iostream>
#include <cstdio>

int n, m,
    dp[7][7], trans[7][7];
char a[3], b[2];

int main(){

    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i){
        scanf("%s %s", a, b);
        ++trans[b[0] - 'a'][a[0] - 'a'];
    }

    dp[0][0] = 1;
    for(int i = 1; i < n; ++i)
        for(int j = 0; j < 6; ++j)
            for(int k = 0; k < 6; ++k)
                dp[i][k] += dp[i-1][j]*trans[j][k];

    int r = 0;
    for(int i = 0; i < 6; ++i)
        r += dp[n-1][i];

    printf("%d\n", r);

    return 0;
}
