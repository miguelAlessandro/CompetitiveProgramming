#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
int st[maxN<<2];
bool lazy[maxN<<2];
int n, m, q, a, b;

void updNode(int nx, int l, int r) {
	st[nx] = r - l + 1 - st[nx];
	lazy[nx] ^= 1;
} 

void push(int nx, int l, int mid, int r) {
	if (lazy[nx]) {
		updNode(nx<<1, l, mid);
		updNode(nx<<1|1, mid+1, r);
		lazy[nx] = 0;
	}
} 

void upd(int ll, int rr, int nx=1, int l=1, int r=n) {
	if (rr < l or r < ll) return;
	if (ll <= l and r <= rr) {
		updNode(nx, l, r);
		return;
	}
	int mid = (l+r)/2;
	push(nx, l, mid, r);
	upd(ll, rr, nx<<1, l, mid);
	upd(ll, rr, nx<<1|1, mid+1, r);
	st[nx] = st[nx<<1] + st[nx<<1|1];
}

int qry(int ll, int rr, int nx=1, int l=1, int r=n) {
	if (rr < l or r < ll) return 0;
	if (ll <= l and r <= rr) return st[nx];
	int mid = (l+r)/2;
	push(nx, l, mid, r);
	return qry(ll, rr, nx<<1, l, mid) + qry(ll, rr, nx<<1|1, mid+1, r);
}


int main(){
	scanf("%d %d", &n, &m);
	while (m--){
		scanf("%d %d %d", &q, &a, &b);
		if (q) printf("%d\n", qry(a, b));
		else upd(a, b);
	}
	return 0;
}
