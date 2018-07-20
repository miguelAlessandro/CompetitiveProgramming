#include <bits/stdc++.h>
using namespace std;

const int N = 10;
typedef pair<int, int> ii;
char x[5], y[5];
int dis[N][N];
bool vis[N][N];
const int dx[] = {2, 1, -1, -2, -2, -1, 1, 2},
		  dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};


int bfs(int x, int y, int xf, int yf){
	memset(vis, false, sizeof vis);
	queue<ii> Q; Q.push(ii(x, y));
	dis[x][y] = 0; vis[x][y] = true;
	while(not Q.empty()){
		ii q = Q.front(); Q.pop();
		if(q.first == xf and q.second == yf) return dis[xf][yf];
		for(int i = 0; i < 8; ++i){
			int a = q.first+dx[i], b = q.second+dy[i];
			if(a >= 1 and a <= 8 and b >= 1 and b <= 8 and not vis[a][b]){
				vis[a][b] = true;
				dis[a][b] = dis[q.first][q.second] + 1;
				Q.push(ii(a, b));
			}
		}
	}
}

int main(){

	while(scanf("%s %s", x, y) != EOF)
		printf("To get from %s to %s takes %d knight moves.\n", x, y, bfs(x[0]-'a'+1, x[1]-'0', y[0]-'a'+1, y[1]-'0'));

	return 0;
}
