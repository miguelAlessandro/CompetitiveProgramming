#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e6 + 10;
char lucky[maxN];
int n, m;
struct Node {
	int oo, ou, uu, uo;
	Node(int oo=0, int ou=0, int uu=0, int uo=0):
	oo(oo), ou(ou), uu(uu), uo(uo) {}
} st[maxN<<2];
bool lazy[maxN<<2];

Node merge(Node p, Node q) {
	return {	
		p.oo + q.oo,
		max(p.ou + q.uu, p.oo + q.ou),
		p.uu + q.uu,
		max(p.uu + q.uo, p.uo + q.oo)
	};
}

void build(int nx=1, int l=0, int r=n-1) {
	if (l == r) {
		st[nx] = lucky[r]=='7'? Node(0, 1, 1, 1) : Node(1, 1, 0, 1); 
		return;
	}
	int mid = (l+r)/2;
	build(nx<<1, l, mid);
	build(nx<<1|1, mid+1, r);
	st[nx] = merge(st[nx<<1], st[nx<<1|1]);
}

void updNode(int nx) {
	swap(st[nx].oo, st[nx].uu);
	swap(st[nx].ou, st[nx].uo);
	lazy[nx] ^= 1;
}

void push(int nx) {
	if (lazy[nx]) {
		updNode(nx<<1);	
		updNode(nx<<1|1);
		lazy[nx] = 0;
	}
}

void upd(int ll, int rr, int nx=1, int l=0, int r=n-1) {
	if (rr < l or r < ll) return;
	if (ll <= l and r <= rr) {
		updNode(nx);
		return;
	}
	int mid = (l+r)/2;
	push(nx);
	upd(ll, rr, nx<<1, l, mid);
	upd(ll, rr, nx<<1|1, mid+1, r);
	st[nx] = merge(st[nx<<1], st[nx<<1|1]);
}
	
int main() {
	scanf("%d %d\n", &n, &m);
	scanf("%s", lucky);
	char s[10];
	build();
	while (m--) {
		scanf("%s", s);
		if (s[0] == 's') {
			int l, r;
			scanf("%d %d\n", &l, &r);
			upd(l-1, r-1);
		} else {
			printf("%d\n", st[1].ou);
		}
	}
	return 0;
}
