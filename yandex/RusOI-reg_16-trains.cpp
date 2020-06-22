/**
 *	@name RusOI regional stage 2016 day 1 Trains
 *	@author Miguel Mini
 *	@tag greedy, sweep_line
 *	@idea
 *		- this is a modified "line segment covering problem"
 *		the difference is that you receive complement segments.
 *		
 *		- we can maintain a maximum set with begin point 
 *		from position i of every segment and set the best 
 *		segment to cover a point.
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n, m, k, q;
typedef pair<int, int> pii;
vector<pii> g[maxn];
const int LOG = 21;
int st[maxn][LOG];
int val[maxn];

int main() {
	//freopen("train.in", "r", stdin);
	//freopen("train.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m; ++i) {
		int s, t, a;
		scanf("%d %d %d", &s, &t, &a);
		g[t].push_back({s, a});
	}
	set<pii, greater<pii>> s;
	for (int i = 1; i <= k; ++i) {
		s.insert({val[i] = n+1, i});
	}
	for (int i = n+1; i >= 1; --i) {
		st[i][0] = max((s.begin())->first, i);
		for (int k = 1; k < LOG; ++k) {
			st[i][k] = st[st[i][k-1]][k-1];
		}
		for (auto e : g[i]) {
			s.erase({val[e.second], e.second});
			val[e.second] = e.first;
			s.insert({val[e.second], e.second});
		}
	}
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		int f, d;
		scanf("%d %d", &f, &d);
		int ans = 0;
		for (int j = LOG-1; j >= 0; --j) {
			if (st[f][j] < d) {
				f = st[f][j];
				ans |= (1<<j);
			}
		}
		if (st[f][0] >= d) ans += 1;
		else ans = -1;
		printf("%d\n", ans);
	}
	return 0;
}
