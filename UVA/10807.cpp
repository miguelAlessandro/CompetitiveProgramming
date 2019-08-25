#include <bits/stdc++.h>
using namespace std; 
const int maxN = 12;
const int maxM = 30;

struct Edge {
	int a, b, w;
};
int n, m;
int p[maxN], rnk[maxN];
int components;

int get(int x) {return x == p[x] ? x : p[x] = get(p[x]);}
bool merge(int x, int y) {
	x = get(x);
	y = get(y);
	if (x == y) return 0;
	if (rnk[x] < rnk[y]) swap(x, y);
	rnk[x] += rnk[x] == rnk[y];
	p[y] = x;
	components -= 1;
	return 1;
}

int main() {
	while (cin >> n, n) {
		cin >> m;	
		vector<Edge> edges; 
		for (int i = 0; i < m; ++i) {
			int a, b, w;
			cin >> a >> b >> w;
			edges.push_back({a, b, w});
		}
		if (m < 2*(n-1)) {
			cout << "No way!" << endl;
			continue;
		}
		sort(begin(edges), end(edges), [](Edge p, Edge q) {
			return p.w < q.w;
		});
		for (int i = 1; i <= n; ++i) p[i] = i, rnk[i] = 0;
		bool arr[m]; memset(arr, 0, sizeof arr);
		int ans = 0;
		components = n;
		for (int i = 0; i < m; ++i) {		
			if (merge(edges[i].a, edges[i].b)) {
				ans += edges[i].w;
				arr[i] = 1;
			}
		}
		bool fun = 1;
		if (components != 1) fun = 0;
		components = n;
		for (int i = 1; i <= n; ++i) p[i] = i, rnk[i] = 0;
		for (int i = 0; i < m; ++i) {		
			if (arr[i]) continue;
			if (merge(edges[i].a, edges[i].b)) {
				ans += edges[i].w;
			}
		}
		if (components != 1) fun = 0;
		if (not fun) cout << "No way!" << endl;
		else cout << ans << endl;
	}
	return 0;
}
