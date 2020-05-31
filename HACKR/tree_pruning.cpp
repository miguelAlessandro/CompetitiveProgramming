/**
 * @author Miguel Mini
 * @tag dp on trees, connect componen approach, lca optimization
 * @idea
 *      - lca optimization aplication.
 *
**/

#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
long long dp[maxN][210];
int  w[maxN], sz[maxN];
vector<int> g[maxN];
int n, k;

int dfs(int x, int p) {
    sz[x] = 1;
    for (int v : g[x]) {
        if (v == p) continue;
        sz[x] += dfs(v, x);
    }
    for (int i = 1; i <= k; ++i) dp[x][i] = -2e18;
    dp[x][0] = w[x];
    for (int v : g[x]) {
        if (v == p) continue;
        for (int i = min(k, sz[x]); i >= 0; --i) {
            dp[x][i] += dp[v][0];        
            for (int j = 1; j <= min(i, sz[v]); ++j) {    
                dp[x][i] = max(dp[x][i], dp[x][i-j] + dp[v][j]);
            }
        }
    }
    dp[x][1] = max(dp[x][1], 0ll);
    return sz[x];
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) scanf("%d", w+i);
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);    
    long long ans = -2e18;    
    for (int i = 0; i <= k; ++i) ans = max(ans, dp[1][i]);
    printf("%lld\n", ans);
    return 0;
}
