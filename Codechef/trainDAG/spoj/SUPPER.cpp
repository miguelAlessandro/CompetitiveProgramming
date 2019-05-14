#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
int ft[maxN], l[maxN], r[maxN], a[maxN];
int n;

void upd(int p, int v) {
	while (p <= n) {
		ft[p] = max(ft[p], v);
		p += p&-p;
	}
}

int qry(int p) {
	int ans = 0;
	while (p > 0) {
		ans = max(ans, ft[p]);
		p -= p&-p;
	}
	return ans;
}

int main() {
	while (scanf("%d", &n) == 1) {
		for (int i = 1; i <= n; ++i) scanf("%d", a+i);
		for (int i = 1; i <= n; ++i) ft[i] = 0;
		for (int i = 1; i <= n; ++i) upd(a[i], l[i] = qry(a[i]) + 1);
		for (int i = 1; i <= n; ++i) ft[i] = 0;
		for (int i = n; i >= 1; --i) upd(n-a[i]+1, r[i] = qry(n-a[i]+1) + 1);
		int lis = *max_element(l+1, l+n+1);
		vector<int> res;
		for (int i = 1; i <= n; ++i) if (lis+1 == l[i] + r[i]) res.emplace_back(a[i]);
		printf("%d\n", (int)res.size());
		sort(begin(res), end(res));
		for (int e : res) printf("%d ", e); puts("");
	}
	return 0;
}
