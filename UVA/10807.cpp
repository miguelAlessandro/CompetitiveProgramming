#include <bits/stdc++.h>
#define all_elements_in(vect) begin(vect), end(vect)
using namespace std; 
const int maxN = 12;
const int maxM = 30;

struct Edge {
	int a, b, w;
};
int n, m;

int p[maxN], rnk[maxN];

int get(int x) {
	return x == p[x] ? x : p[x] = get(p[x]);
}

int components;

bool merge(int x, int y) {
	x = get(x); y = get(y);
	if (x == y) {
		return 0;
	}
	if (rnk[x] < rnk[y]) {
		swap(x, y);
	}
	rnk[x] += rnk[x] == rnk[y];
	p[y] = x;
	components -= 1;
	return 1;
}

void make_tree(int x) {
	components += 1;
	p[x] = x;
	rnk[x] = 0;
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
		sort(all_elements_in(edges), [](Edge p, Edge q) {
			return p.w < q.w;
		});
		for (int i = 1; i <= n; ++i) {
			make_tree(i);		
		}
		vector<int> in_mst;
		for (int i = 0; i < edges.size(); ++i) {
			if (merge(edges[i].a, edges[i].b)) {
				in_mst.push_back(i);
			}
		}
		vector<bool> block_edges(m);
		int t = in_mst.size();
		int ans = 1e9;
		for (int bit_set = 0; bit_set < 1<<t; bit_set += 2) {
			fill(all_elements_in(block_edges), 0);
			for (int i = 0; i < t; ++i) {
				if (bit_set & (1<<i)) {
					block_edges[in_mst[i]] = 1;
				}
			}
			int mst1 = 0;
			components = 0;
			for (int i = 1; i <= n; ++i) {
				make_tree(i);
			}
			for (int i = 0; i < edges.size(); ++i) {
				if (not block_edges[i] and merge(edges[i].a, edges[i].b)) {
					mst1 += edges[i].w;
					block_edges[i] = 1;
				}
			}
			if (components != 1) {
				continue;
			}
			for (int i = 0; i < t; ++i) {			
				if (bit_set & (1<<i)) {
					block_edges[in_mst[i]] = 0;
				}
			}
			int mst2 = 0;
			components = 0;
			for (int i = 1; i <= n; ++i) {
				make_tree(i);
			}	
			for (int i = 0; i < edges.size(); ++i) {
				if (not block_edges[i] and merge(edges[i].a, edges[i].b)) {
					mst2 += edges[i].w;
				}
			}
			if (components == 1) {
				ans = min(ans, mst1 + mst2);
			}
		}
		if (ans > 1e6) cout << "No way!" << endl;
		else cout << ans << endl;
	}
	return 0;
}
