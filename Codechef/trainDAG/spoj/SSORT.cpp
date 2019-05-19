#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e3 + 10;
int a[maxN], val[maxN];
bool vis[maxN];
int n;

int main() {
	int nc = 1;
	while (scanf("%d", &n), n) {
		printf("Case %d: ", nc++);
		memset(vis, 0, sizeof vis);
		memset(val, 0, sizeof val);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", a+i);
			val[a[i]] = 1;
		}
		int t = 1;
		for (int i = 1; i <= 1000; ++i) {
			if (val[i]) val[i] = t++;
		}
		int mn = *min_element(a+1, a+n+1);
		int ans = 0;
		for (int i = 1; i <= n; ++i) {		
			if (vis[i]) continue;
			int mnt = 1e9, cnt = 0, x = i;
			int sum = 0;
			while (not vis[x]) {
				vis[x] = 1;
				cnt += 1;
				sum += a[x];
				mnt = min(mnt, a[x]);
				x = val[a[x]];
			}
			ans += min(sum + (cnt - 2) * mnt, sum + (cnt + 1) * mn + mnt);
		}
		printf("%d\n\n", ans);
	}
	return 0;
}
