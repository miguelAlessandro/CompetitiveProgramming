/**
 *	@name COI 2014 Krave
 *	@author Miguel Mini
 *	@tag segment_tree, tournament_tree
 *	@idea
 *		-	we can build 2 segment tree,
 *		maintaining horizontal and 
 *		vertical segments, respectively.
 *	
 *		if we add horizontal segment x = p
 *		in range [ll, rr], we can handle 
 * 	this with a segment tree on log(1e5) 
 *		nodes.
 *	
 *		note that we dont need push information
 *		in segment tree and save values in 
 *		a set by node instead.
 *	
 *		in each query we look and return to above and below
 *		segment to respective point in O(log^2 1e5).
 *
 *		this ideas are typical in tournament tree.
 */

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
set<int> st[2][maxn<<2];
 
void add_st(int t, int ll, int rr, int p, int nx=1, int l=0, int r=1e5) {
	if (rr < l or r < ll) return;
	if (ll <= l and r <= rr) {
		st[t][nx].insert(p);
		return;
	}
	int mid = (l+r)/2;
	add_st(t, ll, rr, p, nx<<1, l, mid);
	add_st(t, ll, rr, p, nx<<1|1, mid+1, r);
}
 
const int INF = 1e8;
pair<int, int> nil = {0, INF};
pair<int, int> query(int t, int pos, int v, int nx=1, int l=0, int r=1e5) {
	if (pos < l or r < pos) return nil;	
	pair<int, int> L = nil, R = nil, M = nil;
	if (l != r) {
		int mid = (l + r) / 2;
		L = query(t, pos, v, nx<<1, l, mid);
		R = query(t, pos, v, nx<<1|1, mid+1, r);
	}
	if (not st[t][nx].empty())	{
		auto q = st[t][nx].lower_bound(v);
      		if (q == st[t][nx].end()) --q;
		if (*q > v) {
			M.second = *q;
		} else {
			M.first = *q;
		}
		if (q != st[t][nx].begin()) --q;
		if (*q < v) {
			M.first = max(M.first, *q);
		}
	}
	return {max({L.first, M.first, R.first}), 
				min({L.second, M.second, R.second})};
}
 
int main() {
	int A, B, N;
	cin >> A >> B >> N;
	add_st(0, 0, A, 0);
	add_st(0, 0, A, B);
	add_st(1, 0, B, 0);
	add_st(1, 0, B, A);
	for (int i = 1; i <= N; ++i) {
		int x, y, d;
		cin >> x >> y >> d;
		pair<int, int> P = query(0, x, y);
		pair<int, int> Q = query(1, y, x);
		long long a1, a2;
		if (d == 1) {
			a1 = (y - P.first) *1ll* (Q.second - Q.first);
			a2 = (P.second - y) *1ll* (Q.second - Q.first);
			add_st(0, Q.first, Q.second, y);
		} else {
			a1 = (P.second - P.first) *1ll* (x - Q.first);
			a2 = (P.second - P.first) *1ll* (Q.second - x);
			add_st(1, P.first, P.second, x);
		}
		if (a1 > a2) swap(a1, a2);
		cout << a1 << " " << a2 << endl;
	}
	return 0;
}
