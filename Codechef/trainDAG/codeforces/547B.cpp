#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 10;
int id[maxN], rnk[maxN];
int n, a[maxN], o[maxN];
bool vis[maxN];
int ans[maxN];

int get(int x) {return x==id[x]?x:id[x] = get(id[x]);}

void Union(int x, int y) {
	x = get(x);
	y = get(y);
	if (x == y) {
		return;
	}
	if (rnk[x] < rnk[y]) swap(x, y);
	id[y] = x;
	rnk[x] += rnk[y];
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a+i);
	}
	for (int i = 1; i <= n; ++i) {
		id[i] = i;
		o[i] = i;
		rnk[i] = 1;
	}
	sort(o+1, o+n+1, [&](int x, int y) {
		return a[x] > a[y];
	});
	for (int i = 1; i <= n; ++i) {
		int l = 0, r = 0;
		int k = o[i];
		if (k > 1 and vis[k-1]) l = rnk[get(k-1)], Union(k-1, k); 
		if (k < n and vis[k+1]) r = rnk[get(k+1)], Union(k, k+1);
		ans[l + r + 1] = max(ans[l + r + 1], a[k]);
		vis[k] = 1;
	}
	for (int i = n-1; i >= 1; --i) {
		ans[i] = max(ans[i], ans[i+1]);
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d ", ans[i]);
	}
	puts("");
	return 0;
}
