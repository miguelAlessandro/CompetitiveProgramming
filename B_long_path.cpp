#include <iostream>
#include <cstdio>
#define f(x, y, z) for(int x = y; x < z; ++x)
#define N 1005

using namespace::std;

int n;
int p[N];
int dp[N][2];
bool E[N] = {false, true};

int DP(int, bool);

int main(){
    
    dp[n][0] = 1;

    scanf("%d", &n);
    f(i, 1, n + 1)
        scanf("%d", &p[i]);

    printf("%d\n", DP(1, E[1]));

    return 0;
}

int DP(int m, bool k){
 
    if(dp[m][k] != 0) return dp[m][k];

    if(k){
        for(int i = p[m]; i <= m; i++){
            E[i] = !E[i];           
            dp[m][k] += DP(i, E[i]);
        }
        return dp[m][k];
    }
    else{
        E[m+1] = !E[m+1];
        return dp[m][k] = DP(m + 1, E[m+1]) + 1;
    }
}









