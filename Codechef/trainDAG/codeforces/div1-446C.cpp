#include <bits/stdc++.h>
#define f(a, b, c) for (int a = b; a < c; ++a)
using namespace std;
const int maxN = 1e5 + 10;
const int mod = 1e9 + 9;

int add(int a, int b) {
	return (a+b)%mod;
}
int mul(long long a, long long b) {
	return a*b%mod;
}
struct Matrix {
	int a[2][2];
	Matrix(int t=0) {
		if (t) id();
		else zero();
	}
	void zero() {
		f(i, 0, 2) f(j, 0, 2) 
			a[i][j] = 0;
	}
	void id() {
		f(i, 0, 2) f(j, 0, 2) 
			a[i][j] = i==j;
	}
	Matrix operator *(Matrix X) {
		Matrix R(0);
		f(i, 0, 2) f(j, 0, 2) f(k, 0, 2)
			R.a[i][j] = add(R.a[i][j], mul(a[i][k], X.a[k][j]));
		return R;
	}
} fib[maxN];

int fibonacci(int x, int y, int n) {
	return add(mul(fib[n].a[0][0], x), mul(fib[n].a[0][1], y));
}

int sum(int x, int y, int n) {
	return add(fibonacci(x, y, n+1), mod - y);
}

int st[maxN<<2];
int lazy[maxN<<2][2]; 
int n, m;
int a[maxN];

void build(int nx=1, int l=1, int r=n) {
	if (l == r) {
		st[nx] = a[r];
		return;
	}	
	int mid = (l+r)/2;
	build(nx<<1, l, mid);
	build(nx<<1|1, mid+1, r);
	st[nx] = add(st[nx<<1], st[nx<<1|1]);
}

void updNode(int nx, int x, int y, int l, int r) {
	st[nx] = add(st[nx], sum(x, y, r - l + 1));
	lazy[nx][0] = add(lazy[nx][0], x);
	lazy[nx][1] = add(lazy[nx][1], y);
}

void push(int nx, int l, int r) {
	int mid = (l+r)/2;
	int x = lazy[nx][0];
	int y = lazy[nx][1];
	updNode(nx<<1, x, y, l, mid);
	updNode(nx<<1|1, fibonacci(x, y, mid + 1 - l), fibonacci(x, y, mid + 2 - l), mid+1, r);
	lazy[nx][0] = lazy[nx][1] = 0;
}

int qry(int ll, int rr, int nx = 1, int l=1, int r=n) {
	if (rr < l or r < ll) return 0;
	if (ll <= l and r <= rr) return st[nx];
	int mid = (l+r)/2;
	push(nx, l, r);
	return add(
		qry(ll, rr, nx<<1, l, mid),
		qry(ll, rr, nx<<1|1, mid+1, r)
	);
}

void upd(int ll, int rr, int nx=1, int l=1, int r=n) {
	if (rr < l or r < ll) return;
	if (ll <= l and r <= rr) {
		updNode(nx, fibonacci(1, 1, l - ll), fibonacci(1, 1, l - ll + 1), l, r);
		return;
	}
	int mid = (l+r)/2;
	push(nx, l, r);
	upd(ll, rr, nx<<1, l, mid);
	upd(ll, rr, nx<<1|1, mid+1, r);
	st[nx] = add(st[nx<<1], st[nx<<1|1]);
}

int main() {
	fib[0] = Matrix(1);
	fib[1].a[0][1] = fib[1].a[1][0] = fib[1].a[1][1] = 1;
	f(i, 2, maxN) fib[i] = fib[i-1] * fib[1];
	scanf("%d %d", &n, &m);
	f(i, 1, n+1) scanf("%d", a+i);
	build();
	while (m--) {
		int t, l, r;
		scanf("%d %d %d", &t, &l, &r);
		if (t == 1) upd(l, r);
		else printf("%d\n", qry(l, r));
	}
	return 0;
}
