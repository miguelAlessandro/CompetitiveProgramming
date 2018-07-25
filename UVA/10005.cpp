/**
 *	UVA 10005
 *	@overview see if any circle of radius R 
 *  can contain a set of n points
 *
 * 	- I can always move the circle so that 
 * 	it touches two points.
 *	- calculate center in O(log n) with
 * 
 *	d = dist (P_i, P_j)
 *	df = +- sqrt ((2R)^2 - d^2) / d
 *		   		 | 1  -df| (P_j - P_i)
 * 	P_i +  0.5 x | df	1|
 *
 * 	- brute force solution with center fix.
 */

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 105;
int x[MAX_N], y[MAX_N];
int n;
long double R;
const long double eps = 1e-8;

int main () {

	while(scanf ("%d", &n), n) {
		for (int i = 0; i < n; ++i)
			scanf ("%d %d", x+i, y+i);

		scanf ("%Lf", &R);

		bool ok = n == 1;
		for (int i = 0; i < n; ++i) {
			for (int j = i+1; j < n; ++j) {
				long double d2 = (x[i] - x[j]) * 1ll * (x[i] - x[j]) + 
								 (y[i] - y[j]) * 1ll * (y[i] - y[j]);
				
				if (d2 > 4 * R * R) continue;
				long double vx = x[i] - x[j];
				long double vy = y[i] - y[j];

				long double df = sqrt((4 * R * R - d2) / d2) ;
				long double cx = x[j] + 0.5 * (vx - vy * df);
				long double cy = y[j] + 0.5 * (vx * df + vy);


				ok = 1;	
				for (int k = 0; ok and k < n; ++k) {
					if ((cx - x[k]) * (cx - x[k]) + (cy - y[k]) * (cy - y[k]) >= eps + R * R) ok = 0;
				}

				if (ok) break;

				cx = x[j] + 0.5 * (vx + vy * df);
				cy = y[j] + 0.5 * (-vx * df + vy);

				ok = 1;	
				for (int k = 0; ok and k < n; ++k) {
					if ((cx - x[k]) * (cx - x[k]) + (cy - y[k]) * (cy - y[k]) >= eps +  R * R) ok = 0;
				}

				if (ok) break;
			}

			if (ok) break;
		}

		puts (ok ? "The polygon can be packed in the circle." : "There is no way of packing that polygon.");
	}
	return 0;
}
