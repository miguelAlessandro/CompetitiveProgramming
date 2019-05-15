#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
long long ft[2][maxN];
int a[maxN];
int n;

void upd(int k, int pos, long long v) {
	while (pos <= n) {
		ft[k][pos] += v;
		pos += pos&-pos;
	}
}

long long qry(int k, int pos) {
	long long ans = 0;
	while (pos > 0) {
		ans += ft[k][pos];
		pos -= pos&-pos;
	}
	return ans;
}


int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a+i);
		a[i] = n - a[i] + 1;
	}
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += qry(1, a[i]-1);
		upd(1, a[i], qry(0, a[i]-1));
		upd(0, a[i], 1);
	}
	printf("%lld\n", ans);
	return 0;
}
