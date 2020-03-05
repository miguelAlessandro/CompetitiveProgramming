/**
 *	@name Codeforces 1218 div1 I
 *	@author Miguel Mini
 *	@tag dfs, greedy, coloring
 *	@idea
 *		- every position have a coloring
 *		edge restriction, if initial value
 *		is distinct of target value, we need 
 *		a one between l[i] or l[j]. if is 0
 *		we need both have the same color.
 *	
 *		- color -> 1:taked, 0:not taked.
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010;
char s[maxn][maxn], t[maxn][maxn];
char l[maxn];
int n;
int f[2 * maxn];
int color[2 * maxn];
bool vis[2 * maxn];
vector<pair<int, int>> g[2 * maxn];

bool force(int x, int v) {
	if (f[x] == -1) f[x] = v;
	return f[x] == v;
}

bool dfs(int x, int c) {
	if (f[x] != -1 and f[x] != c) return 0;
	vis[x] = 1;
	color[x] = c;
	bool ans = 1;
	for (auto node : g[x]) {
		if (not vis[node.first]) {
			ans &= dfs(node.first, c ^ node.second);
		} else {
			ans &= color[node.first] == (c ^ node.second);
		}
	}	
	return ans;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%s", s[i]);
	for (int i = 0; i < n; ++i) scanf("%s", t[i]);
	scanf("%s", l);
	bool fun = 1;
	memset(f, -1, sizeof f);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (l[i] == '0' and l[j] == '0') {
				if (s[i][j] != t[i][j]) fun = 0;
			} else {
				if (s[i][j] == t[i][j]) {
					if (l[i] == l[j]) {
						g[2 * i].push_back({2 * j + 1, 0});
						g[2 * j + 1].push_back({2 * i, 0});
					} else if (l[i] == '1') {
						fun &= force(2 * j + 1, 0);
					} else {
						fun &= force(2 * i, 0);
					}
				} else {
					if (l[i] == l[j]) {
						if (l[i] == '0') fun = 0;						
						else {
							g[2 * i].push_back({2 * j + 1, 1});
							g[2 * j + 1].push_back({2 * i, 1});
						}
					} else if (l[i] == '1') {
						fun &= force(2 * j + 1, 1);
					} else {
						fun &= force(2 * i, 1);
					}	
				}
			}
		}
	}
	if (not fun) return cout << -1 << endl, 0;
	for (int i = 0; i < 2 * n; ++i) {
		if (f[i] != -1 and not vis[i]) {
			fun &= dfs(i, f[i]);
		}
	}
	for (int i = 0; i < 2 * n; ++i) {
		if (not vis[i]) {
			fun &= dfs(i, 0);
		}
	}
	if (not fun) return cout << -1 << endl, 0;
	vector<int> t;
	for (int i = 0; i < n; ++i) {
		if (color[2 * i] == 1) t.push_back(2 * i);
		if (color[2 * i + 1] == 1) t.push_back(2 * i + 1);
	}
	cout << t.size() << endl;
	for (auto e : t) {
		if (e&1) cout << "col " << e / 2  << endl;
		else cout << "row " << e / 2 << endl;
	}
	return 0;
}
