#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
bool adj[N][N], vis[N][N];
int dis[N][N]; 
int n, m, t, r, c, x;
const int dx[] = {1, 0, -1, 0},
		  dy[] = {0, -1, 0, 1};

int bfs(int x, int y, int xf, int yf){
	queue<int> Q;
	Q.push(x); Q.push(y); 
	dis[x][y] = 0; vis[x][y] = true;
	while(not Q.empty()){
		int q1 = Q.front(); Q.pop();
		int q2 = Q.front(); Q.pop();
		if(q1 == xf and q2 == yf) return dis[xf][yf];
		for(int a, b, i = 0; i < 4; ++i){
			a = q1+dy[i]; b = q2+dx[i];
			if(a >= 0 and a < n and b >= 0 and b < m and not vis[a][b] and not adj[a][b]){
				vis[a][b] = true;
				dis[a][b] = dis[q1][q2] + 1;
				Q.push(a);
				Q.push(b);
			}
		}
	}
}

int main(){
	
	while(scanf("%d %d", &n, &m), n+m){
		scanf("%d", &t);
		while(t--){
			scanf("%d %d", &r, &c);		
			for(int i = 0; i < c; ++i){
				scanf("%d", &x);
				adj[r][x] = true;		
			}
		}
		int x, y, xf, yf;		
		scanf("%d %d %d %d", &x, &y, &xf, &yf);
		printf("%d\n", bfs(x, y, xf, yf));
		memset(adj, false, sizeof adj);
		memset(vis, false, sizeof vis);
	}

	return 0;
}
