#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, m, k;
bool vis[N][N];
float dp[N][N];
float s2 = sqrt(2.0);

int main(){

   scanf("%d %d", &n, &m);
   scanf("%d", &k);
   
   for(int x,y,i = 0; i < k; ++i){
      scanf("%d %d", &x, &y);
      vis[x][y] = 1;
   }

   for(int i = 0; i <= n; ++i)
      dp[i][0] = i;
   for(int i = 0; i <= m; ++i)
      dp[0][i] = i;

   for(int i = 1; i <= n; ++i)
      for(int j = 1; j <= m; ++j){
         dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
         if(vis[i][j])
            dp[i][j] = min(dp[i][j], dp[i-1][j-1] + s2);
      }

   printf("%.0f\n", 100.0*dp[n][m]);


   return 0;
}
