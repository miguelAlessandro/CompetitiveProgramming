#include <bits/stdc++.h>
using namespace std;
const int maxN = 3e5 + 10;
long double b[maxN], r[maxN], s[maxN];
int a[maxN];
int n, k;

bool p(long double x) {
	for (int i = 1; i <= n; ++i) b[i] = a[i] - x; 
	long double mn = 0, mx = -1e18;
	long double sum = 0;
	for (int i = 1; i <= n; ++i) {
		sum += b[i];
		s[i] = sum;
		r[i] = sum - mn;
		if (i >= k) mx = max(r[i], mx);
		if (i >= k) mn = min(mn, s[i-k+1]);
	}
	return mx >= 0;
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a+i);
	}
	long double lo = 0, hi = 1e6;
	for (int i = 0; i <= 120; ++i) {
		long double mid = lo + (hi-lo) / 2;
		if (p(mid)) lo = mid;
		else hi = mid;
	}
	cout << fixed << setprecision(6) << lo << endl;
	return 0;
}
