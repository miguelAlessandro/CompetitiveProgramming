#include <bits/stdc++.h>
using namespace std;
const int maxN = 3e4 + 10;
struct Node {
	int l, r;
} st[maxN<<2];
bool A[maxN];
int N, M;

Node merge(Node p, Node q) {
	return {
		p.l + q.l - min(p.l, q.r),
		p.r + q.r - min(p.l, q.r)	
	};
}

void build(int nx=1, int l=1, int r=N) {
	if (l == r) {
		st[nx] = {A[r], not A[r]};
		return;
	}
	int mid = (l+r)/2;
	build(nx<<1, l, mid);	
	build(nx<<1|1, mid+1, r);
	st[nx] = merge(st[nx<<1], st[nx<<1|1]);
}

void upd(int pos, int nx=1, int l=1, int r=N) {
	if (pos < l or pos > r) return;
	if (l == r) {
		swap(st[nx].l, st[nx].r);
		return;
	}
	int mid = (l+r)/2;
	upd(pos, nx<<1, l, mid);
	upd(pos, nx<<1|1, mid+1, r);
	st[nx] = merge(st[nx<<1], st[nx<<1|1]);
}

int main() {
	int nc=1;
	while(scanf("%d\n", &N) == 1) {
		printf("Test %d:\n", nc++);
		for (int i = 1; i <= N; ++i) {
			A[i] = getchar() == '(';
		}
		build();
		scanf("%d", &M);
		for (int i = 1; i <= M; ++i) {
			int k;	
			scanf("%d", &k);
			if (k==0) puts(st[1].l + st[1].r == 0?"YES":"NO");
			else upd(k);
		}
	}
	return 0;
}
