#include <bits/stdc++.h>
using namespace std;

const int N = 805;
const int dj[6] = {0, 1, 0, -1, -1, 1};
const int di[6] = {1, 0, -1, 0, 1, -1};
stack<int> Q;
bool vis[N][N], T[N][N], color;
int q, np, mp, n, m, a, b, c, d, r, qx, qy, nx, ny;

inline bool valid(int a, int b){
	return a >= 0 and a < np and b >= 0 and b < mp; 
}

void dfs(int x, int y){
	
	vis[x][y] = true;
	Q.push(x), Q.push(y);
	color = T[a-1+x][b-1+y];
	while(not Q.empty()){
		qx = Q.top(); Q.pop();
		qy = Q.top(); Q.pop();

		for(int i = 0; i < 6; ++i){
			nx = qx + dj[i];
			ny = qy + di[i];
			if(valid(ny, nx) and not vis[ny][nx] and T[ny+a-1][nx+b-1] == color){
				vis[ny][nx] = true;
				Q.push(ny);
				Q.push(nx);
			}
		}
	}

}

int main(){
	
	scanf("%d %d%*c", &n, &m);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j)
			T[i][j] = (getchar() == 'B');
		getchar();
	}


	scanf("%d", &q);
	while(q--){
		//memset(vis, false, sizeof vis);
		scanf("%d %d %d %d", &a, &b, &c, &d);
		np = c - a + 1;
		mp = d - b + 1;
		for(int i = 0; i < np; ++i)
			memset(vis[i], false, sizeof(bool)*mp);
		r = 0;
		for(int i = 0; i < np; ++i)
			for(int j = 0; j < mp; ++j)
				if(not vis[i][j]){
					r++;
					dfs(i, j);
				}

		printf("%d\n", r);
	}

	return 0;
}
