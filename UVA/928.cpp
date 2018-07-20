#include <bits/stdc++.h>
using namespace std;

const int N = 305;
bool adj[N][N];
int dis[N][N][4];
int t, n, m, x, y, xf, yf;
const int dx[] = {1, 0, -1, 0},
		  dy[] = {0, -1, 0, 1};

bool lim(int x, int y, int xf, int yf){
	if(x == xf){ 
		if(y > yf) swap(y, yf);
		for(int i = y; i <= yf; ++i)
			if(adj[x][i]) return false;

	}
	if(y == yf){
		if(x > xf) swap(x, xf);
		for(int i = x; i <= xf; ++i)
			if(adj[i][y]) return false;
	}
	return true;
}


bool bfs(int x, int y, int xf, int yf){
	queue<int> Q; Q.push(x); Q.push(y); Q.push(2);
	dis[x][y][2] = 0;

	bool ok = false;
	while(not Q.empty()){
		int q1 = Q.front(); Q.pop();
		int q2 = Q.front(); Q.pop();
		int e = Q.front(); Q.pop();
		if(q1 == xf and q2 == yf) ok = true;
		for(int a, b, c, i = 0; i < 4; ++i){
			c = (e+1)%3;
			a = q1 + dy[i]*(c+1);
			b = q2 + dx[i]*(c+1);
			if(a >= 0 and a < n and b >= 0 and b < m and  dis[q1][q2][e]+1 < dis[a][b][c] and lim(q1, q2, a, b)){
				dis[a][b][c] = dis[q1][q2][e] + 1;
				Q.push(a);
				Q.push(b);
				Q.push(c);
			}			
		}
	} 	
	return ok;
}



int main(){

	scanf("%d", &t);
	while(t--){
		scanf("%d %d%*c", &n, &m);
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				int c = getchar();
				if(c == 'S') x=i, y=j;
				if(c == 'E') xf=i, yf=j;
				if(c == '#') adj[i][j] = true;
				for(int k = 0; k < 3; ++k)
					dis[i][j][k] = 1000000000;										
			}
			getchar();
		}
		
		if(bfs(x, y, xf, yf))
			printf("%d\n", min(dis[xf][yf][0], min(dis[xf][yf][1], dis[xf][yf][2])));
		else puts("NO");		
		memset(adj, false, sizeof adj);
	}

	return 0;
}
