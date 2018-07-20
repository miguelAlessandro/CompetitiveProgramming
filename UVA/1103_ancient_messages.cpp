#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace::std;

char L[10] = {'W', 'A', 'K', 'J', 'S', 'D'};
int n, m, x, K;
int M[210][51*4];
bool vis[210][51*4];
const int   di[8] = {0, -1, 0, 1},
            dj[8] = {1, 0, -1, 0};
vector<int> solve;

void dfs(int x, int y, int D, int T){
    vis[x][y] = true;
    M[x][y] = T;
    for(int i = 0; i < 8; ++i){
        int a = x + di[i], b = y + dj[i];
        if(a >= 0 and a <= n+1 and b >= 0 and b <= 4*m+1 and M[a][b] == D and not vis[a][b])
            dfs(a, b, D, T);
    }
}

void _dfs(int x, int y, int D1, int D2){
    vis[x][y] = true;
    for(int i = 0; i < 8; ++i){
        int a = x + di[i], b = y + dj[i];
        if(a > 0 and a <= n and b > 0 and b <= 4*m and not vis[a][b])
            if(M[a][b] == D1) _dfs(a, b, D1, D2);
            else if(M[a][b] == D2) dfs(a, b, 0, ++K);
    }
}

int main(){
    
    int nc = 1;
    while(scanf("%d %d%*c", &n, &m), n + m){
        printf("Case %d: ", nc++);
        memset(M, 0, sizeof M);     
        memset(vis, false, sizeof vis);
        solve.clear();
        for(int i = 1; i <= n; ++i){
            for(int j = 0; j < m; ++j){
                x = getchar();
                islower(x) ? x = x - 'a' + 10 : x -= '0';
                for(int k = 0; k < 4; ++k)
                    if(x & (1 << k))
                        M[i][4*j + 4 - k] = 1;
                    else
                        M[i][4*j + 4 - k] = 0;
            }               
            getchar();
        }
        
        dfs(0, 0, 0, -1);
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= 4*m; ++j){
                if(M[i][j] == 1 and not vis[i][j]){
                    K = 0;
                    _dfs(i, j, 1, 0);
                    solve.push_back(L[K]);
                }
            }
        sort(solve.begin(), solve.end());
        for(int i = 0; i < int(solve.size()); ++i)
            putchar(solve[i]);
        putchar('\n');
    }

    return 0;
}
