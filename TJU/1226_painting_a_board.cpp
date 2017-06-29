#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int t, n, depth, C[20];
int M[N][N], h[20];
bool adj[20][20], vis[20];
bool memo[1<<16];
int dp[1<<16];
vector<int> nv[20];
vector<int> G[20];
struct data{
   int x, y, w, z;
   data(int xx = 0, int yy = 0, int ww = 0, int zz = 0) : x(xx), y(yy), w(ww), z(zz) {}
};
vector<data> v;


int backtrack(int mask){
   if(mask+1 == (1<<n)) return 0;
   if(memo[mask]) return dp[mask];  

   int ans = 20;

   for(int c = 1; c <= 20; ++c){
      int tr = mask;

      for(int i = 0; i <= depth; ++i){
         for(int j = 0; j < nv[i].size(); ++j){
            int v = nv[i][j];  

            if(tr&(1<<v)) continue;
            if(C[v] != c) continue;         

            bool ok = true;
            for(int k = 0; k < G[v].size(); ++k)
               if((~tr)&(1<<G[v][k]))
                  ok = false;

            if(ok) tr |= (1<<v);
         }
      }

      if(tr != mask)
         ans = min(ans, backtrack(tr)+1);
   }

   memo[mask] = 1;
   return dp[mask] = ans;
}

int dfs(int x){
   if(vis[x] == 1) return h[x];
   vis[x] = 1;

   h[x] = 0;
   for(int i = 0; i < n; ++i)
      if(adj[x][i])
         h[x] = max(h[x], dfs(i)+1);

   nv[h[x]].push_back(x);
   depth = max(depth, h[x]);

   return h[x];
}


int main(){

   scanf("%d", &t);
   while(t--){   
      scanf("%d", &n);

      v.clear();
      memset(M, -1, sizeof M);      

      for(int x, y, w, z, c,i = 0; i < n; ++i){
         scanf("%d %d %d %d %d", &x, &y, &w, &z, &c);

         C[i] = c;
         for(int j = y; j <= z; ++j)
            M[w][j] = i;            

         v.push_back(data(x, y, w, z));
      }

      memset(adj, 0, sizeof adj);
      for(int i = 0; i < n; ++i)
         G[i].clear();
      for(int i = 0; i < n; ++i)
         for(int j = v[i].y; j <= v[i].z; ++j){
            int u = M[v[i].x][j];
            if(u != -1 and not adj[i][u]){
               G[i].push_back(u);
               adj[i][u] = 1;
            }
         }

      memset(vis, 0, sizeof vis);
      for(int i = 0; i < 20; ++i)
         nv[i].clear();

      depth = 0;
      for(int i = 0; i < n; ++i)
         dfs(i);

      memset(memo, 0, sizeof memo);
      printf("%d\n", backtrack(0));
   }

   return 0;
}
