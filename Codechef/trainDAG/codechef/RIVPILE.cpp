#include <bits/stdc++.h>
using namespace std;
const int maxN = 255;
int t, n, m, w;

typedef long long ll;
bool intersect(ll x_1, ll y_1, ll r_1, ll x_2, ll y_2, ll r_2) {
	return (x_1 - x_2) * (x_1 - x_2) + (y_1 - y_2) * (y_1 - y_2) <= (r_1 + r_2) * (r_1 + r_2);
}

vector<pair<pair<int, int>, int>> g[maxN][maxN];
typedef pair<long long, pair<int, int>> Event;
ll dis[maxN][maxN];
int x[maxN], y[maxN];
int r[maxN], c[maxN];

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> m >> w;
		for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
		for (int i = 0; i < m; ++i) cin >> r[i] >> c[i];
		typedef pair<int, int> ii;
		vector<ii> disks;	
		for (int i = 0; i < m; ++i) disks.emplace_back(r[i], c[i]);
		sort(rbegin(disks), rend(disks));
		for (int i = 1; i < m; ++i) 
			disks[i].second = min(
				disks[i].second, 
				disks[i-1].second
			);
		for (int i = 0; i < n; ++i) 
			for (int j = 0; j < m; ++j)
				g[i][j].clear();
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				if (i == j) {
					for (int k = 1; k < m; ++k)
						g[i][k].push_back({{i, k-1}, disks[k-1].second - disks[k].second});
					continue;
				}
				for (int a = m-1, b = 0; a >= 0; --a) {
					while (b+1 < m and intersect(x[i], y[i], disks[a].first, x[j], y[j], disks[b+1].first)) b += 1;
					if (intersect(x[i], y[i], disks[a].first, x[j], y[j], disks[b].first))
						g[i][a].push_back({{j, b}, disks[b].second});
				}
			}
		for (int i = 0; i < n; ++i) 
			for (int j = 0; j < m; ++j)
				dis[i][j] = LLONG_MAX;
		priority_queue<Event, vector<Event>, greater<Event>> Q;	
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (y[i] <= disks[j].first) {
					Q.push({disks[j].second, {i, j}});
					dis[i][j] = disks[j].second;	
				}
		long long ans = LLONG_MAX;
		while (not Q.empty()) {
			auto event = Q.top(); Q.pop();
			ll W = event.first;
			int i = event.second.first;
			int j = event.second.second;
			if (y[i] + disks[j].first >= w) ans = min(ans, W);
			if (dis[i][j] != W) continue;
			for (auto node : g[i][j]) {
				ll temp = W + node.second;
				int ni = node.first.first;
				int nj = node.first.second;
				if (temp < dis[ni][nj]) {
					dis[ni][nj] = temp;
					Q.push({temp, {ni, nj}});
				}
			}
		}
		if (ans == LLONG_MAX) cout << "impossible" << endl;
		else cout << ans << endl;
	}
	return 0;
}
