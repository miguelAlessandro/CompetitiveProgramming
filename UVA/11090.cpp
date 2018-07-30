/**
 *	UVA 11090
 *	@overview print mediam of minimum cycle
 *	- suppose that solution is S, 
 * 	then we do this binary searchable:
 *		S = minimum (weight cycle / number of edges)
 *		f (x) : S < x <- binary searchable function
 *		-> suppose S = some cycle / k edges, then
 *		-> some cycle < x * (k edges)
 *		-> some cycle - x * (k edges) < 0
 *		-> if we subtract x for all edge, 
 *		then the above statement indicates that there is a
 *		negative cycle in the modified graph. Any other 
 *		cycle can only be less negative.
 *	- final solution binary search + bellman ford for negative 
 *	cycle detection.
 */


#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 55;
double dis[MAX_N];
struct edge {
	int u, v;
	double w;
};
vector<edge> edges;
int n, m, t, nc=1;
const int inf = 2e9;

bool bellman_ford (int s) {
	for (int i = 1; i <= n; ++i)
		dis[i] = inf;
	dis[s] = 0;
	for (int i = 1; i < n; ++i) {
		for (auto e : edges) {
			dis[e.v] = min(dis[e.v], dis[e.u] + e.w);
		}
	}
	for (auto e : edges) {
		if (dis[e.u] + e.w < dis[e.v]) {
			return 1;
		}
	}
	return 0;
}

bool p(double x) {
	vector<edge> edges2 = edges;
	
	for (auto& e : edges)
		e.w -= x;
	
	bool ans = bellman_ford(1);
	edges = edges2;
	return ans;
}

int main () {

	scanf ("%d", &t);

	while (t --) {
		scanf ("%d %d", &n, &m);
		edges.clear();
		for (int i = 0; i < m; ++i) {
			int u, v, w;
			scanf ("%d %d %d", &u, &v, &w);
			edges.push_back({u, v, (double)w});
		}

		double lo = 0, hi = 1e7;
		for (int i = 0; i < 36; ++i) {
			double mid = (lo + hi) / 2;
			if (not p(mid)) lo = mid;
			else hi = mid;
		}
		printf ("Case #%d: ", nc++);

		if (p(hi)) printf ("%.2lf\n", lo);
		else puts("No cycle found.");
	}

	return 0;
}
