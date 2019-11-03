/**	
 *	@name NKMARS Mars Map
 *	@author Miguel Mini
 *	@tag geometry
 *	@idea
 *		- coordinate compresion to x and y
 *		- use sweep line with segment tree
 *  	- in segment tree use lazy propagation
 *		- and query for minimum value.
 */

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
struct Node {
	int min, sum;
} st[maxn<<2];
int lazy[maxn<<2];
int n, m, p;
int diff_y[maxn];
int pos_x[maxn], pos_y[maxn];
map<int, int> map_x, map_y;

Node merge(Node p, Node q) {
	if (p.min < q.min) return p;
	if (p.min > q.min) return q;
	return {p.min, p.sum + q.sum};
}

void build(int nx=1, int l=0, int r=m-1) {
	if (l == r) {
		st[nx] = {0, diff_y[r]};
		return;
	}
	int mid = (l+r)/2;
	build(nx<<1, l, mid);
	build(nx<<1|1, mid+1, r);
	st[nx] = merge(st[nx<<1], st[nx<<1|1]);
}

void update_node(int x, int v) {
	lazy[x] += v;
	st[x].min += v;
}

void push(int x) {
	if (lazy[x] != 0) {
		update_node(x<<1, lazy[x]);
		update_node(x<<1|1, lazy[x]);
		lazy[x] = 0;
	}
}

void update(int ll, int rr, int add, int nx=1, int l=0, int r=m-1) {
	if (rr < l or r < ll) return;
	if (ll <= l and r <= rr) {
		update_node(nx, add);
		return;
	}
	int mid = (l+r)/2;
	push(nx);
	update(ll, rr, add, nx<<1, l, mid);
	update(ll, rr, add, nx<<1|1, mid+1, r);
	st[nx] = merge(st[nx<<1], st[nx<<1|1]);
}


struct Event {
	int x, l, r, v;	
};

int main() {
	cin >> n;
	vector<Event> P;
	for (int i = 0; i < n; ++i) {
		int x_1, y_1, x_2, y_2;
		cin >> x_1 >> y_1 >> x_2 >> y_2;
		map_x[x_1]; map_x[x_2];
		map_y[y_1]; map_y[y_2];
		if (x_1 > x_2) swap(x_1, x_2);
		if (y_1 > y_2) swap(y_1, y_2);
		P.push_back({x_1, y_1, y_2, 1});
		P.push_back({x_2, y_1, y_2, -1});
	}
	for (auto& e : map_x) {
		pos_x[p] = e.first;
		e.second = p++;
	}
	for (auto& e : map_y) {
		pos_y[m] = e.first;
		if (m >= 1) diff_y[m] = pos_y[m] - pos_y[m-1]; 
		e.second = m++;
	}
	build();
	sort(P.begin(), P.end(), [](Event p, Event q) {
		return p.x < q.x or p.x == q.x and p.v < q.v;	
	});
	int last = pos_x[0]; 
	long long area = (pos_y[m-1] - pos_y[0]) * 1ll * (pos_x[p-1] - pos_x[0]);
	for (int i = 0; i < P.size();) {
		int cur = P[i].x;
		if (st[1].min == 0) {
			area -= (cur - last) *1ll* st[1].sum;  
		}
		while (i < P.size() and P[i].x == cur) {
			update(map_y[P[i].l]+1, map_y[P[i].r], P[i].v);
			i += 1;
		}
		last = cur;
	}
	cout << area << endl;
	return 0;
}
