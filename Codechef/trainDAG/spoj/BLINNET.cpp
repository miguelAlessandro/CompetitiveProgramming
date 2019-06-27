#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e4 + 10;
struct Edge {
	int u, v;
	unsigned w;
};
int t, n;
int p[maxN], rnk[maxN];

int get(int x) {return x == p[x] ? x : p[x] = get(p[x]);}

unsigned mst = 0;
void merge(int x, int y, unsigned w) {
	x = get(x);
	y = get(y);
	if (x == y) return;
	if (rnk[x] < rnk[y]) swap(x, y);
	p[y] = x;
	mst += w;
	rnk[x] += rnk[x] == rnk[y];
}


int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		//map<string, int> id;	
		vector<Edge> edges;
		for (int i = 1; i <= n; ++i) {
			string s;
			cin >> s;
			//id[s] = i;
			int m; cin >> m;
			for (int j = 1; j <= m; ++j) {
				int u; unsigned w; cin >> u >> w;
				edges.push_back({i, u, w});
			}
		}
		for (int i = 1; i <= n; ++i) p[i] = i, rnk[i] = 0;

		sort(begin(edges), end(edges), [](Edge p, Edge q) {
			return p.w < q.w;
		});
		mst = 0;
		for (auto e : edges) merge(e.u, e.v, e.w);
		cout << mst << endl;
	}
	return 0;
}
