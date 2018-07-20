#include <bits/stdc++.h>
using namespace std;

const int N = 35;
bool adj[N][N][N], vis[N][N][N];
int dis[N][N][N];
char s[N];
int a, b, c, x, y, z, xf, yf, zf;
const int dx[] = {1, 0, 0, 0, 0, -1},
		  dy[] = {0, -1, 0, 0, 1, 0},
		  dz[] = {0, 0, -1, 1, 0, 0};


bool bfs(int x, int y, int z, int xf, int yf, int zf, int& r){
	queue<int> Q; Q.push(x); Q.push(y); Q.push(z);
	dis[x][y][z] = 0; vis[x][y][z] = true;
	while(not Q.empty()){
		int q1 = Q.front(); Q.pop();
		int q2 = Q.front(); Q.pop();
		int q3 = Q.front(); Q.pop();
		if(q1 == xf and q2 == yf and q3 == zf){
			r = dis[xf][yf][zf];
			return true;
		}
		for(int i = 0; i < 6; ++i){
			int s1 = q1+dx[i], s2 = q2+dy[i], s3 = q3+dz[i];
			if(s1 >= 0 and s2 >= 0 and s3 >= 0 and s1 < a and s2 < b and s3 < c and not vis[s1][s2][s3] and not adj[s1][s2][s3]){
				vis[s1][s2][s3] = true;
				dis[s1][s2][s3] = dis[q1][q2][q3] + 1;
				Q.push(s1);
				Q.push(s2);
				Q.push(s3);
			}
		}
	}
	return false;
}


int main(){

	while(scanf("%d %d %d%*c", &a, &b, &c), a+b+c){
		for(int i = 0; i < a; ++i){
			for(int j = 0; j < b; ++j){
				cin.getline(s, N);
				for(int k = 0; k < c; ++k){
					if(s[k] == 'S') x = i, y = j, z = k;
					if(s[k] == 'E') xf = i, yf = j, zf = k;
					adj[i][j][k] = s[k]=='#';
				}			
			}
			cin.getline(s, N);
		}
		int r;
		memset(vis, false, sizeof vis);
		if(bfs(x, y, z, xf, yf, zf, r))	
			printf("Escaped in %d minute(s).\n", r);
		else
			puts("Trapped!");
	}

	return 0;
}
