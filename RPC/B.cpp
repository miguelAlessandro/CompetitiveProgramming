#include <bits/stdc++.h>
using namespace std;

const int N = 30;
int n, im, e, len;
char T[N][N];

int dx[4] = {1, -1, -1, 1};
int dy[4] = {-1, -1, 1, 1};
bool vis[N][N];

bool isvalid(int a, int b){
	return  a >= 0 and a < n and b >= 0 and b < n;
}

int dfs(int x, int y){

	vis[x][y] = true;
	int g = 0;
	for(int i = 0; i < 4; ++i){

		int nx = x + dx[i];
		int ny = y + dy[i];
		int nnx = x + 2*dx[i];
		int nny = y + 2*dy[i];

		if(not isvalid(nx, ny) or not isvalid(nnx, nny)) continue;
		
		if(T[nx][ny] == 'W' and T[nnx][nny] == '_'){
			if(not vis[nnx][nny]) dfs(nnx, nny);	
			g++;
		}
	}

	if(g&1) im++;
	e += g;
	return g;
}


int main(){

	scanf("%d%*c", &n);
	len = 0;
	for(int i = 0; i < n; ++i){
		scanf("%s", T[i]);
		//puts(T[i]);			
		for(int j = 0; j < n; ++j)
			if(T[i][j] == 'W') len++;
			else if(T[i][j] != 'B') T[i][j] = '_';
		getchar();
	}	

	int r = 0;
	int a, b;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			if(T[i][j] == 'B'){
				e = 0;	
				im = 0;
				memset(vis, false, sizeof vis);
				T[i][j] = '_';	
				int f = dfs(i, j);
				T[i][j] = 'B';
				if(e == 2*len and (im == 0 or (im == 2 and (f&1)))) r++, a = i, b = j;
				if(r == 2) break;
			}
	
	if(r == 0) puts("None");
	else if(r > 1) puts("Multiple");
	else printf("%c%d\n", 'a' + b, n - a); 

	return 0;
}
