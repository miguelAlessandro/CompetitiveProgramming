/**
 *	@name COCI 2009 xor
 *	@author Miguel Mini
 *	@tag geometry, math, PIE
 *	@idea
 *		- the PIE to xor operation
 *		is equal to:
 *			\sum |Ai| - 2\sum |A_i \cap A_j|
 *			+ 4\sum |A_i \cap A_j \cap A_k|
 *			... 2^{k-1} \sum |A_{i1} \cap ... A_{ik}|
 *
 *		- note that the intersection of two triangles
 *		is a triangle.
 *
 *		- the intersection of triangles (x1, y1, r1) and
 *		(x2, y2, r2) is the triangle:
 *		
 *			(max(x1, x2), max(y1, y2), 
 *				min(x1+y1+r1, x2+y2+r2)-max(x1, x2)-max(y1, y2))
 *		- note that r >= 0.
 */

#include <bits/stdc++.h>
using namespace std;
const int maxn = 12;
int n;
int X[maxn], Y[maxn], R[maxn];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> X[i] >> Y[i] >> R[i];
	}
	long long ans = 0;
	for (int s = 1; s < 1<<n; ++s) {	
		int x = 0, y = 0, r = 4e6;		
		for (int i = 0; i < n; ++i) {
			if (s & (1<<i)) {
				r = min(X[i] + Y[i] + R[i], x + y + r);
				x = max(x, X[i]);
				y = max(y, Y[i]);
				r -= x + y;
				r = max(0, r);

			}
		}
		int sz = __builtin_popcount(s);
		ans += (sz & 1) ? (1ll<<sz-1) * r * r : - (1ll<<sz-1) * r * r;
	}
	cout << (ans >> 1);
	if (ans&1) cout << ".5";
	else cout << ".0";
	cout << endl;
	return 0;
}
