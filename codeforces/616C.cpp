#include <bits/stdc++.h>
using namespace std;

struct point{
	int x, y;
	point(){}
	point(int xx, int yy): x(xx), y(yy) {}
	bool operator==(const point& p){
		return x == p.x and y == p.y;
	}
	bool operator!=(const point& p){
		return x != p.x or y != p.y;
	}
};
const int N = 1005;
const int dx[4] = {1, 0, -1, 0},
		  dy[4] = {0, -1, 0, 1};
int sz[N][N];
point p[N][N];
char adj[N][N];
int gx[4], gy[4], len;
int n, m;

void init(int n, int m){
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j){
			sz[i][j] = 1;
			p[i][j] = point(i, j);
		}
}

point find(int x, int y){
	if(point(x, y) != p[x][y]) p[x][y] = find(p[x][y].x, p[x][y].y);
	return p[x][y];
}


void Union(int x, int y, int w, int z){
	point u = find(x, y), v = find(w, z);
	if(u == v) return;

	if(sz[u.x][u.y] > sz[v.x][v.y]){
		p[v.x][v.y] = u;
		sz[u.x][u.y] += sz[v.x][v.y]; 
	}
	else{
		p[u.x][u.y] = v;
		sz[v.x][v.y] += sz[u.x][u.y];
	}
}

bool same(int x, int y, int w, int z){
	return find(x, y) == find(w, z);
}


int main(){

	scanf("%d %d%*c", &n, &m);
	for(int i = 0; i < n; ++i)
		scanf("%s%*c", adj[i]);

	init(n, m);

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if(adj[i][j] != '*')
				for(int a, b, k = 0; k < 4; ++k){
					a = i + dx[k];
                    b = j + dy[k];
                    if(a >= 0 and b >= 0 and a < n and b < m and adj[a][b] != '*')
						Union(i, j, a, b);
				}
				

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j)
			if(adj[i][j] == '*'){
				len = 0;
				for(int a, b, k = 0; k < 4; ++k){
					a = i + dx[k];
					b = j + dy[k];
					if(a >= 0 and b >= 0 and a < n and b < m and adj[a][b] != '*'){
						bool ok = true;
						for(int h = 0; h < len and ok; ++h)
							if(same(gx[h], gy[h], a, b))
								ok = false;

						if(ok){
							gx[len] = a;
							gy[len] = b;
							len++;
						}
					}
				}
				int r = 1;
				for(int k = 0; k < len; ++k){
					point u = find(gx[k], gy[k]);
					r += sz[u.x][u.y];
				}
				printf("%d", r%10);
			}	
			else
				putchar('.');
		putchar('\n');
	}


	return 0;
}
