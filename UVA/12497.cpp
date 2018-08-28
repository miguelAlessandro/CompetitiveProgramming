/** 
 *  UVA - 12407
 *  @overview give n speed zones, find minimum time to traverse this
 *  - observations:
 *      - it's better to traverse on rect line in each speed zone
 *      - considere angle orientation : \theta_i
 *      - with s_i speed then, we need:
 *  - system:
 *      min sum_{i=1}^{n} t_i
 *       (1)  sum_{i=1}^{n} s_i t_i cos(\theta_i) = D
 *       (2)  s_i t_i sin(\theta_i) = 100
 *
 *   - merge (1) and (2):
 *
 *        sum_{i=1}^{n} sqrt((s_i t_i)^2 - 100^2) = D
 *    
 *   - use lagrange multiplier: (material: https://pastebin.com/B7jVNs65)
 *    solve:
 *        100 * sum_{i=1}^{n} sqrt((s_i \lambda)^2 / (1 - (s_i lambda)^2)) = D 
 *  
 *   - note: above function is increasing (use binary search)
 *   - reemplace in t_i = sqrt(100^2 / (1 - (s_i \lambda)^2)) / s_i (lagrange multiplier)
 */


#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e2 + 10;
int t, n, d, nc=1;
int s[MAX_N];

bool p(long double lambda) {
	long double sum = 0.;
	for (int i = 1; i <= n; ++i) {
		long double x = s[i] * lambda;
		sum += sqrt((x*x) / (1. - x*x));
	}

	return 100*sum <= d;
}


int main() {

	scanf ("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &d);
		for (int i = 1; i <= n; ++i)
			scanf("%d", s+i);

		long double lo = 0., hi = 1.;
		for (int i = 1; i <= n; ++i) {
			hi = min(hi, 1.L / s[i]);
		}
		
		for (int iter = 0; iter < 50; ++iter) {
			long double mid = lo + (hi-lo)/2.;
			if (p(mid)) lo = mid;
			else hi = mid;
		}

		long double sumTime = 0.;
		for (int i = 1; i <= n; ++i) {
			long double x = s[i] * lo;
			sumTime += sqrt(10000 / (1 - x*x)) / s[i];
		}	

		printf ("Case %d: %.10Lf\n", nc++, sumTime);
	}

	return 0;
}
