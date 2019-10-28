/**
 *	@name POI 2010 sheep
 *	@author Miguel Mini
 *	@tag geometry, sweep_line, dp
 *	@idea
 *			- if we know that a line 
 *			divides into two equal parts 
 *			and does not pass through 
 *			any point, we can compute
 *			dp in the following form:
 *
 *				dp[l][r] = sum dp[l][i] * dp[i][r]
 *			
 *			dp[l][r] number of partitions
 *  		in the polygon p[l], p[l+1],
 *			..., p[r]. and i in range [l+1, r-1]
 *			this range is cyclic.			
 *	
 *			- to compute the first part,
 *			we observing than if point
 *			if in triangle [p[i], p[k], p[k+1]]
 *			then [p[i+1], p[l], p[l+1]] gets
 *			l to right of k, then if increase
 *			i, necessary increase k.
 */

#include <bits/stdc++.h>
using namespace std;

const int maxn = 602;
const int maxk = 20002;
struct Node {
	int x, y;
	Node(int x=0, int y=0): x(x), y(y) {}
	Node operator -(Node p) {
			return Node(x-p.x, y-p.y);
	}
	bool operator ==(Node p) {
		return x == p.x and y == p.y;
	}
} p[maxn], q[maxn + maxk];
int n, k, m;
bool sum[maxn][maxn], block[maxn][maxn];

int cross(Node p, Node q) {
	return p.x * q.y - p.y * q.x;
}

int mul(int a, int b) {
	return a*b%m;
}

int add(int a, int b) {
	a += b;
	if (a >= m) a -= m;
	return a;
}

int nxt(int a) {return a == n-1 ? 0 : a+1;}	
int prv(int a) {return a == 0 ? n-1 : a-1;}

typedef long long ll;
ll memo[maxn][maxn];
bool vis[maxn][maxn];
ll dp(int l, int r) {
	if (l == r) return 1;
	if (nxt(l) == r) return 1;
	if (vis[l][r]) return memo[l][r];
	vis[l][r] = 1;
	ll &ans = memo[l][r] = 0;
	for (int i = nxt(l); i != r; i = nxt(i)) {
		if (not (block[l][i] | block[i][r])) {
			ans = add(ans, mul(dp(l, i), dp(i, r)));
		}
	}
	return ans;
}

bool in_triangle(Node q, int j, int l, int r) {
	return cross(p[l] - p[j], q - p[j]) <= 0 and
		cross(p[r] - p[j], q - p[j]) >= 0;
}

bool in_line(Node q, int i, int j) {
	return cross(p[j] - p[i], q - p[i]) == 0;
}

int main() {
	scanf("%d %d %d", &n, &k, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &p[i].x, &p[i].y);
	}
	for (int i = 0; i < k; ++i) {
		scanf("%d %d", &q[i].x, &q[i].y);
	}
	for (int i = 0; i < k; ++i) {	
		for (int j = 0, t = 1; j < n; ++j) {
				if (j == t) t = nxt(t);
				while (!in_triangle(q[i], j, t, nxt(t))) {
					t = nxt(t);
				}
				sum[j][nxt(t)] ^= 1;
				block[j][nxt(t)] |= in_line(q[i], j, nxt(t));
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j < n; ++j) {
			int t = (i + j) % n;
			sum[i][t] ^= sum[i][prv(t)];
			block[i][t] |= sum[i][t];
		}
	}
	ll ans = dp(0, n-1);
	printf("%lld\n", ans);
	return 0;
}
