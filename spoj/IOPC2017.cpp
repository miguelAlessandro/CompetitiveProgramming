/**
 *  spoj iopc2017
 *  @overview given a ortohedron, make xor 1 the cubes
 *  that have one of their three coordinates in a range 
 *  and consult in another orthohedron how many have xor 1
 *  - How does one dimension affect others?
 *  - valid cases with xor 1: 1 0 0, 0 1 0, 0 0 1, 1 1 1.
 */


#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5;
const int OFF_SET = 2;
int st[MAX_N<<2 + OFF_SET][3];
bool lazy[MAX_N<<2 + OFF_SET][3];

void upd(int ny, int nx, int l, int r) {
	st[nx][ny] = r-l+1 - st[nx][ny];
	lazy[nx][ny] ^= 1;
}

void push(int ny, int nx, int l, int r, int mid) {
	if (lazy[nx][ny]) {
		upd(ny, nx<<1, l, mid);
		upd(ny, nx<<1|1, mid+1, r);
		lazy[nx][ny] = 0;
	}
}

void update (int a, int b, int ny, int nx = 1, int l = 0, int r = MAX_N) {
	if (b < l or a > r) return;
	if (a <= l and r <= b) {
		upd (ny, nx, l, r);
		return;
	}
	int mid = (l+r)/2;
	push(ny, nx, l, r, mid);
	update(a, b, ny, nx<<1, l, mid);
	update(a, b, ny, nx<<1|1, mid+1, r);
	st[nx][ny] = st[nx<<1][ny] + st[nx<<1|1][ny];
}

int query (int a, int b, int ny, int nx = 1, int l = 0, int r = MAX_N) {
	if (b < l or a > r) return 0;
	if (a <= l and r <= b) return st[nx][ny];
	int mid = (l+r)/2;
	push(ny, nx, l, r, mid);
	return query(a, b, ny, nx<<1, l, mid) + query(a, b, ny, nx<<1|1, mid+1, r);
}

int t, q;
int main() {
	
	scanf ("%d", &t);
	while (t--) {
		scanf ("%*d %*d %*d %d", &q);
		memset(lazy, 0, sizeof lazy);
		memset(st, 0, sizeof st);
		while (q--) {
			int op;
			scanf ("%d", &op);
			if (op < 3) {
				int a, b;
				scanf ("%d %d", &a, &b);
				update(a, b, op);
			} else {
				int x_1, y_1, z_1, x_2, y_2, z_2;	
				scanf ("%d %d %d %d %d %d", &x_1, &y_1, &z_1, &x_2, &y_2, &z_2);
	
				int rx = query(x_1, x_2, 0); 
				int ry = query(y_1, y_2, 1);
				int rz = query(z_1, z_2, 2);
				
				int gx = x_2-x_1+1 - rx;
				int gy = y_2-y_1+1 - ry;
				int gz = z_2-z_1+1 - rz;
	
				printf ("%lld\n",  rx * (ry *1ll* rz + gy *1ll* gz) + 
								   gx * (ry *1ll* gz + gy *1ll* rz));
			}
		}
	}
	
	return 0;
}
