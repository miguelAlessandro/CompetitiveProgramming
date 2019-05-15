#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
typedef long long ll;
const ll inf = 1e15;
struct Node {
	ll maxSum;
	ll sum;
	Node() {}
	Node(ll x):maxSum(x), sum(x) {}
	Node(ll x, ll y):maxSum(x), sum(y) {}
	bool operator ==(Node p) {
		return maxSum == p.maxSum and sum == p.sum;
	}
} st[maxN<<2], add[maxN<<2];
bool lazy[maxN<<2];
int A[maxN];
int n, q;
ll ans[maxN];
vector<pair<int, int>> g[maxN]; 
const Node id = {-inf, -inf};

void calc(int nx, Node v) {
	if (lazy[nx]) {
		add[nx].maxSum = max(add[nx].maxSum, add[nx].sum + v.maxSum);
		add[nx].sum += v.sum;
	} else {
		add[nx] = v;
	}
	lazy[nx] = 1;
	if (st[nx] == id) {
		st[nx] = v;	
	} else {
		st[nx].maxSum = max(st[nx].maxSum, st[nx].sum + v.maxSum);
		st[nx].sum += v.sum;
	}
}

void build(int nx=1, int l=1, int r=n) {
	if (l == r) {
		st[nx] = id;
		return;
	}		
	int mid = (l+r)/2;
	build(nx<<1, l, mid);
	build(nx<<1, mid+1, r);
	st[nx] = id;
}

void push(int nx) {
	if (lazy[nx]) {
		calc(nx<<1, add[nx]);
		calc(nx<<1|1, add[nx]);
		lazy[nx] = 0;
	}
}

Node merge(Node p, Node q) {
	if (p == id) return q;
	if (q == id) return p;
	return {
		max(p.maxSum, q.maxSum),
		max(p.sum, q.sum)
	};
}

void upd(int a, int b, int v, int nx=1, int l=1, int r=n) {
	if (a > r or b < l) return;
	if (a <= l and r <= b) {
		calc(nx, Node(v));
		return;
	}
	push(nx);
	int mid = (l+r)/2;
	upd(a, b, v, nx<<1, l, mid);
	upd(a, b, v, nx<<1|1, mid+1, r);
	st[nx] = merge(st[nx<<1], st[nx<<1|1]);
}

Node qry(int a, int b, int nx=1, int l=1, int r=n) {
	if (a > r or b < l) return id;
	if (a <= l and r <= b) return st[nx];
	push(nx);
	int mid = (l+r)/2;
	return merge(
		qry(a, b, nx<<1, l, mid), 
		qry(a, b, nx<<1|1, mid+1, r)
	);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", A+i);
	}
	scanf("%d", &q);
	for (int i = 1; i <= q; ++i) {
		int l, r;
		scanf("%d %d", &l, &r);
		g[r].emplace_back(l, i);
	}
	map<int, int> last;
	build();
	for (int i = 1; i <= n; ++i) {
		int l = last[A[i]] + 1;
		upd(l, i, A[i]);
		last[A[i]] = i;
		while (not g[i].empty()) {
			pair<int, int> q = g[i].back();
			ans[q.second] = qry(q.first, i).maxSum;
			g[i].pop_back();
		}
	}
	for (int i = 1; i <= q; ++i) {
		printf("%lld\n", max(0ll, ans[i]));
	}
	return 0;
}
