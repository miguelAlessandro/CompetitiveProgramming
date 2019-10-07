/**
 *	@name POI 2009 Walk
 *	@author Miguel Mini
 *	@tag	bfs, product graph
 *	@idea:
 *		- convert path problem to find median node
 *		we can map (x, v) -> ... -> (i, i) in a new
 *		graph with O(n*n) nodes and O(m*m) edges.		
 *	   with ejecution time  O(d * ((nx|A|)^2 + m^2))
 *
 *		- with bfs multi-source we can reduce to  
 *		O(dxn^2 + (nx|A|)^2 + m^2) 'cuz the  
 *		walk can be O(n^2) length.
 *
 *		- with reduction POI 2007 Agency we can reducek 
 * 	to O(dxn^2 + (nx|A|)^2 + nm).
 *
 *		- finally we can separate election in move first 
 *		x and then y in move (x, y, .) --c--> (v, y, c)	
 *		and move (x, y, c) --c--> (x, y, .) with complexity
 *		O(n^2x(d + |A|) + nm).
 *
 *		- https://oi.edu.pl/static/attachment/20110731/oi7/age.html
 *		- https://oi.edu.pl/static/attachment/20110704/oi16.pdf
 */

#include <bits/stdc++.h>
using namespace std;
const int maxn = 410;
const int maxc = 27;
vector<int> gt[maxn];
int d[maxn][maxn][maxc];
vector<int> nxt[maxn][maxc];
pair<int, pair<int, char>> p[maxn][maxn][maxc];
int adj[maxn][maxn];
int c[maxn];
int n, m, t;

void bfs() {
	auto add = [](queue<int>& Q, int x, int y, int ch) {
		Q.push(x); Q.push(y); Q.push(ch);
	};
	queue<int> Q;
	memset(d, 1, sizeof d);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j or adj[i][j] != -1) {
				d[i][j][26] = i != j;
				add(Q, i, j, 26);
			}
		} 
	}
	while (not Q.empty()) {
		int x = Q.front(); Q.pop();
		int y = Q.front(); Q.pop();
		int ch = Q.front(); Q.pop();
		if (ch == 26) {
			for (int v : gt[x]) {
					int nch = adj[v][x];
					if (d[v][y][nch] > d[x][y][ch] + 1) {
						d[v][y][nch] = d[x][y][ch] + 1;
						p[v][y][nch] = {x, {y, (char)ch}};
						add(Q, v, y, nch);
					}}			
		} else {
			for (int v : nxt[y][ch]) {
				if (d[x][v][26] > d[x][y][ch] + 1) {
					d[x][v][26] = d[x][y][ch] + 1;
					p[x][v][26] = {x, {y, ch}};
					add(Q, x, v, 26);
				}
			}
		}	
	}	
}

void genPath(deque<char>& P, int s, int t) {
	if (d[s][t][26] <= 1) {
		if (s != t) P.push_back('a' + adj[s][t]);
		return;
	}
	auto Parent = p[s][t][26];
	int px = Parent.first;
	int py = Parent.second.first;
	int pch = Parent.second.second;
	genPath(P, p[px][py][pch].first, py);
	pch += 'a';
	P.push_back(pch);
	P.push_front(pch);
} 

int main() {
	memset(adj, -1, sizeof adj);
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		char ch;
		cin >> u >> v >> ch;
		ch -= 'a';
		adj[u][v] = ch;
		nxt[u][ch].push_back(v);
		gt[v].emplace_back(u);
	}
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		cin >> c[i];
	}
	bfs();
	for (int i = 1; i < t; ++i) {
		int u = c[i], v = c[i+1];
		int dist = d[u][v][26];
		if (dist > n*n) cout << -1 << endl;
		else {
			deque<char> P;
			genPath(P, u, v);
			cout << P.size() << " ";
			for (char e : P) cout << e; cout << endl;
		}
	}
	return 0;
}
