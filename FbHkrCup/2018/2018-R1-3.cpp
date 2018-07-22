#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5 + 10;
int a[MAX_N], b[MAX_N];
int h[MAX_N], d[80], u[80];
int L[MAX_N], U[MAX_N];
long double hl[MAX_N], hu[MAX_N];
int w, x, y, z, t, nc=1, n, m;


bool p(long double x) {
	long double l1, r1, l2, r2;

	for (int i = 0; i < n; ++i) {
		hl[i] = max(0.L, h[i] - x); 
		hu[i] = h[i] + x;
	}
	for (int i = 0; i+1 < n; ++i) {
		l1 = max(0.L, hl[i] - L[i]);
		r1 = hu[i] + U[i];		

		l2 = hl[i+1];
		r2 = hu[i+1];		

		if (r2 < l1 or r1 < l2) return 0;
		else {
			hl[i+1] = max(l1, l2);
			hu[i+1] = min(r1, r2);
		}
	}
	for (int i = 0; i < n; ++i)
		if (hl[i] > hu[i]) return 0;

	return 1;
}


int main () {
	
	scanf ("%d", &t);
	while (t --) {
			scanf ("%d %d", &n, &m);
			scanf ("%d %d %d %d %d %d", h, h+1, &w, &x, &y, &z);
		
			for (int i = 2; i < n; ++i) {
				h[i] = (w * 1ll * h[i-2] + x * 1ll * h[i-1] + y) % z;
			}

			memset(U, 1, sizeof U);
			memset(L, 1, sizeof L);

			for (int i = 0; i < m; ++i) {
				scanf ("%d %d %d %d", a+i, b+i, u+i, d+i);

				a[i] --;
				b[i] --;
					
				if (a[i] > b[i]) {
					swap(a[i], b[i]);
					swap(u[i], d[i]);
				}
		
				for (int j = a[i]; j < b[i]; ++j) {
					U[j] = min(U[j], u[i]);
					L[j] = min(L[j], d[i]);	
				}
			}

			long double lo = 0, hi = 1e7;
			for (int it = 0; it <= 100; ++it) {
				long double mid = (hi+lo)/2.;
				if (p(mid)) hi = mid;
				else lo = mid;
			}

			printf ("Case #%d: %.8Lf\n", nc++, lo);
	}

	return 0;	
}
