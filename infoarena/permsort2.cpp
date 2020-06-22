//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int a[maxn];
int ft[maxn];
int pos[maxn];
int n;
 
void upd(int pos, int v) {
	while (pos <= n) {
		ft[pos] += v;
		pos += pos&-pos;
	}
}
 
int qry(int pos) {
	int ans = 0;
	while (pos > 0) {
		ans += ft[pos];
		pos -= pos&-pos;
	}
	return ans;
}
 
int main() {
	freopen("permsort.in", "r", stdin);	
	freopen("permsort.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a+i);
		pos[a[i]] = i;
		upd(a[i], 1);
	}
	pos[0] = 0;
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += qry(pos[i]) - qry(pos[i-1]);
		if (pos[i-1] > pos[i]) {
			ans += n-i+1;
		}
		upd(pos[i], -1);
	}
	printf("%lld\n", ans);
	return 0;
}
