#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 10;
struct Node {
	int val;
	int l, r;
} st[maxN << 5];
int elem = 0;

int make() {
	return ++elem;
}

const int inf = 1e9;
void upd(int x, int v, int nx, int l = -inf, int r = inf) {
	if (x < l or r < x) return;
	if (l == r) {
		st[nx].val = v;
		return;
	}
	if (st[nx].l == 0) st[nx].l = make();
	if (st[nx].r == 0) st[nx].r = make();
	int mid = l + (r-l)/2;		
 	upd(x, v, st[nx].l, l, mid);
	upd(x, v, st[nx].r, mid+1, r);
	st[nx].val = st[st[nx].l].val + st[st[nx].r].val;
}

int kth(int k, int nx, int l = -inf, int r = inf) {
	if (st[nx].val < k) return -inf - 1;
	if (l == r) return r;
	int mid = l + (r-l)/2;
	if (st[st[nx].l].val >= k) return kth(k, st[nx].l, l, mid);
	return kth(k-st[st[nx].l].val, st[nx].r, mid+1, r);
}

int count(int x, int nx, int l=-inf, int r=inf) {
	if (l >= x) return 0;
	if (r < x) return st[nx].val;
	int mid = l + (r-l)/2;
	int ans = 0;
	if (st[nx].l) ans += count(x, st[nx].l, l, mid); 
	if (st[nx].r) ans += count(x, st[nx].r, mid+1, r);
	return ans;
}

int main() {
	int q;
	scanf("%d\n", &q);
	int root = make();
	while (q--) {
		int ch = getchar();
		int x;
		scanf("%d\n", &x);
		if (ch == 'I') upd(x, 1, root);		
		if (ch == 'D') upd(x, 0, root);
		if (ch == 'K') {
			int ans = kth(x, root);
			if (ans < -inf) puts("invalid");
			else printf("%d\n", ans);	
		}
		if (ch == 'C') printf("%d\n", count(x, root));
	}
	return 0;
}
