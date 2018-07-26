/**
 *  4787 - Tracking Bio-bots
 *  @overview find not connect components in grid NxN 
 *  with obstacles.
 *  1. grid compression  
 *  2. dfs
 */

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;

const int MAX_N = 2.5e3 + 5;
int x_1[MAX_N], y_1[MAX_N];
int x_2[MAX_N], y_2[MAX_N];
int dx[] = {0, -1};
int dy[] = {-1, 0};
int n, m, w;
bool vis[MAX_N][MAX_N];
int tx[MAX_N * MAX_N];
int ty[MAX_N * MAX_N];
long long vtx[MAX_N];
long long vty[MAX_N];
vector<int> x, y;
bool valid (int i, int j) {
    return i >= 1 and i < y.size() and j >= 1 and j < x.size(); 
}

long long dfs (int i, int j) {
    vis[i][j] = 1;
    for (int k = 0; k < 2; ++k) {
        int nx = i + dy[k];   
        int ny = j + dx[k];
        if (valid(nx, ny) and not vis[nx][ny]) {
            dfs(nx, ny);
        }
    }
}

int main () {
    int nc = 1;
    while (scanf ("%d %d %d", &m, &n, &w), n+m+w) {
        x.clear(); y.clear();
        for (int i = 0; i < w; ++i) {
            scanf ("%d %d %d %d", x_1+i, y_1+i, x_2+i, y_2+i);
            x.emplace_back(x_1[i]); x.emplace_back(x_2[i]+1);
            y.emplace_back(y_1[i]); y.emplace_back(y_2[i]+1);
        }
        x.push_back(0); x.emplace_back(n);
        y.push_back(0); y.emplace_back(m);
        sort(all(x)); x.resize(unique(all(x)) - x.begin());
        sort(all(y)); y.resize(unique(all(y)) - y.begin());
        for (int i = 0; i < x.size(); ++i) tx[x[i]] = i, vtx[i] = i ? x[i] - x[i-1] : 0;
        for (int i = 0; i < y.size(); ++i) ty[y[i]] = i, vty[i] = i ? y[i] - y[i-1] : 0;
        
        memset(vis, 0, sizeof vis);
        long long res = 0;
        for (int i = 0; i < w; ++i) {
            for (int j = tx[x_1[i]] + 1; j <= tx[x_2[i]+1]; ++j)
                vis[ty[y_2[i]+1]][j] = 1;
        }
        if (not vis[ty[m]][tx[n]])
            dfs(ty[m], tx[n]);
        long long ans = 0;
        for (int i = 1; i < y.size(); ++i)
            for (int j = 1; j < x.size(); ++j)
                if (not vis[i][j]) ans += vty[i] * vtx[j];

        printf("Case %d: %lld\n", nc++, ans);
    }
    
    return 0;
}
