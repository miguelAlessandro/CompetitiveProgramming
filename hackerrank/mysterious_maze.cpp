#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1005;
bool adj[N][N];
int n;
const int dx[] = {1, 0, -1, 0},
		  dy[] = {0, 1, 0, -1};

class dsu{
	private:
		int rank[N][N];	
		pair<int, int> id[N][N];
	public:
		void init(int n){
			for(int i = 0; i <= n+1; ++i)
				for(int j = 0; j <= n+1; ++j){
					id[i][j] = make_pair(i, j);
					rank[i][j] = 0;
				}
		}

		pair<int, int> find(int x, int y){
			if(id[x][y] != make_pair(x, y)) id[x][y] = find(id[x][y].first, id[x][y].second);
			return id[x][y];
		}

		void Union(int x, int y, int w, int z){
			pair<int, int> u = find(x, y), v = find(w, z);
			if(u == v) return;
			if(rank[u.first][u.second] > rank[v.first][v.second])
				id[v.first][v.second] = u;
			else{
				id[u.first][u.second] = v;
				rank[u.first][u.second] += (rank[u.first][u.second] == rank[v.first][v.second]);
			}
		}
		bool same(int x, int y, int w, int z){
			return find(x, y) == find(w, z);
		}
} graph;

int X, Y;

int main(){
	
	scanf("%d", &n); graph.init(n);

	for(int i = 0; i <= n+1; ++i){
		adj[0][i] = adj[n+1][i] = true;
		graph.Union(0, 0, 0, i);
		graph.Union(n+1, 0, n+1, i);
	}

	int t = 1;
	while(scanf("%d %d", &X, &Y) == 2){
		
		for(int i = 0; i < 4; ++i){
			int a = X + dx[i], b = Y + dy[i];
			if(a >= 0 and a <= n+1 and b >= 0 and b <= n+1 and adj[a][b])
				graph.Union(X, Y, a, b);
		}
		adj[X][Y] = true;
		if(graph.same(0, 0, n+1, 0)){
			printf("%d\n", t);
			return 0;
		}
		t++;			
	}	

	puts("-1");

	return 0;
}
