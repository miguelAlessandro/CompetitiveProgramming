#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
int st[3][maxN<<2];
bool lz[3][maxN<<2];
int t, n[3], q;

void calc(int i, int nx, int l, int r) {
	st[i][nx] = (r - l + 1) - st[i][nx];
	lz[i][nx] ^= 1;
}

void push(int i, int nx, int l, int r, int mid) {
	if (lz[i][nx]) {
		calc(i, nx<<1, l, mid);
		calc(i, nx<<1|1, mid+1, r);
		lz[i][nx] = 0;
	}	
}

void upd(int i, int a, int b, int nx, int l, int r) {
	if (a > r or b < l) return;
	if (a <= l and r <= b) {
		calc(i, nx, l, r);
		return;
	}
	int mid = (l+r) / 2;
	push(i, nx, l, r, mid);
	upd(i, a, b, nx<<1, l, mid);
	upd(i, a, b, nx<<1|1, mid+1, r);
	st[i][nx] = st[i][nx<<1] + st[i][nx<<1|1];
}

int qry(int i, int a, int b, int nx, int l, int r) {
	if (a > r or b < l) return 0;
	if (a <= l and r <= b) return st[i][nx];
	int mid = (l+r)/2;
	push(i, nx, l, r, mid);
	return qry(i, a, b, nx<<1, l, mid) + qry(i, a, b, nx<<1|1, mid+1, r);
}


int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d %d", n, n+1, n+2, &q);
		memset(st, 0, sizeof st);
		memset(lz, 0, sizeof lz);
		while (q--) {
			int type;
			scanf("%d", &type);
			if (type<=2) {
				int l, r;
				scanf("%d %d", &l, &r);
				++l; ++r;
				upd(type, l, r, 1, 1, n[type]);
			} else {
				int l[3], r[3]; 		
				for (int i = 0; i < 3; ++i) {
					scanf("%d", l+i); 
					l[i]++;
				}
				for (int i = 0; i < 3; ++i)	{
					scanf("%d", r+i); 
					r[i]++;
				}
				long long c[3]; 
				for (int i = 0; i < 3; ++i) {
					c[i] = qry(i, l[i], r[i], 1, 1, n[i]);	
				}
				int m[3];
				for (int i = 0; i < 3; ++i) m[i] = r[i] - l[i] + 1;
				printf("%lld\n", c[0]*c[1]*c[2] + 
								(m[0]-c[0])*(m[1]-c[1])*c[2] + 
								c[0]*(m[1]-c[1])*(m[2]-c[2]) + 
								(m[0]-c[0])*c[1]*(m[2]-c[2]));				
			}
		}
	}
	return 0;
}
