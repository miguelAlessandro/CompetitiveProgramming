/**
 *	@name Baltic 2012 Peaks
 *	@author Miguel Mini
 *	@tag dfs, dsu, amortized, sweepline
 *	@idea
 *			- we can do this incrementally 
 *			by adding the largest heights first.
 *
 *			- each height we add is a set that 
 *			tells us if it is part of a peak or not.
 *
 *			- As we do this incrementally, by 
 *			joining these sets, with higher heights 
 *			first, then you can always go from all 
 *			heights, except the greatest, to the 
 *			greatest by means of heights as great as 
 *			possible.
 *
 *			- the latter means that each set only has 
 *			one type of elements that they have not 
 *			yet joined, the highests.
 *
 *			- we can merge this in O(n \log n) with 
 *			a small variant of dsu.
 *
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 10;
const int maxm = 1e5 + 10;
int p[maxm];
int sz[maxm];
bool isSet[maxm];
int mx[maxm];
int height[maxm];
vector<int> s[maxm];
vector<int> ind[maxn], mat[maxn];
vector<bool> vis[maxn];
bool peak[maxm];
int ans[maxm];
int n, m;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 1, 0, -1, 1, -1, 1, 0};

bool valid(int x, int y) {
	return 0 <= min(x, y) and x < n and y < m;
}

void init(int x, int y) {
	int t = ind[x][y];
	p[t] = t;
	sz[t] = 1;
	isSet[t] = 1;
	mx[t] = peak[t] ? height[t] : -1;
	if (peak[t]) {
		s[t].push_back(t);
	}
}

int get(int x) {
	return x == p[x] ? x : p[x] = get(p[x]); 
}

void merge(int x, int y, int w) {
	x = get(x); y = get(y);
	if (x == y) return;
	if (sz[x] < sz[y]) swap(x, y);
	sz[x] += sz[y];
	p[y] = x;	
	if (mx[y] == -1) return;
	if (mx[x] == -1) {
		swap(s[x], s[y]);
		mx[x] = mx[y];
		return;
	}
	if (mx[x] > mx[y]) {
		for (int v : s[y]) ans[v] = w;
  } else if (mx[y] > mx[x]) {
		for (int v : s[x]) ans[v] = w;
		swap(s[x], s[y]);
 	}	else {
		for (int v : s[y]) s[x].emplace_back(v);
	}
	mx[x] = max(mx[x], mx[y]);
}

void dfs(int x, int y, int t, bool& peak) {
	ind[x][y] = t;
	height[t] = mat[x][y];
	vis[x][y] = 1;
	for (int i = 0; i < 8; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!valid(nx, ny)) continue;
		if (mat[nx][ny] <= mat[x][y]) {
			if (vis[nx][ny]) continue;
			if (mat[nx][ny] == mat[x][y]) {
				dfs(nx, ny, t, peak);
			}
		} else {
			peak = 0;
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		mat[i].resize(m);
		vis[i].resize(m);
		ind[i].resize(m);
		for (int j = 0; j < m; ++j) {
			scanf("%d", &mat[i][j]);
		}
	}
	int t = 0;	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (not vis[i][j]) {
				peak[t] = 1;
				dfs(i, j, t, peak[t]);
				t += 1;
			}
		}
	}
	vector<pair<int, pair<int, int>>> values;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			values.push_back({mat[i][j], {i, j}});
		}
	}	
	sort(values.rbegin(), values.rend());
	for (int i = 0; i < values.size(); ++i) {	
		int x = values[i].second.first;
		int y = values[i].second.second;
		if (not isSet[ind[x][y]]) {
			for (int j = i; j < values.size(); ++j) {
				if (values[i].first != values[j].first) break;
				int tx = values[j].second.first;
				int ty = values[j].second.second;
				init(tx, ty);
			}
		}
		for (int k = 0; k < 8; ++k) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (!valid(nx, ny)) continue;
			if (isSet[ind[nx][ny]]) {
				merge(ind[nx][ny], ind[x][y], mat[x][y]);
			}
		}
	}
	vector<pair<int, int>> sol; 
	for (int i = 0; i < n*m; ++i) {
		if (peak[i]) {
			sol.emplace_back(height[i], ans[i]);
		}
	}
	sort(sol.rbegin(), sol.rend());
	printf("%d\n", (int)sol.size());
	for (auto e : sol) {
		printf("%d %d\n", e.first, e.second);
	}
	return 0;
}
