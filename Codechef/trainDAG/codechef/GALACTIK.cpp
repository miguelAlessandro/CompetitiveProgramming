#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e6;
int id[maxN], rnk[maxN], value[maxN];
int components;

int get(int x) {return x==id[x]?x:id[x]=get(id[x]);}
void merge(int u, int v) {
	u=get(u); v=get(v);
	if (u == v) return;
	if (rnk[u] < rnk[v]) swap(u, v);
	id[v] = u;
	rnk[u] += rnk[u] == rnk[v];
	components -= 1;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	components = n;
	for (int i = 1; i <= n; ++i) {
		id[i] = i;
	}
	for (int i = 1; i <= m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		merge(a, b);
	}
	for (int i = 1; i <= n; ++i) {
		value[i] = INT_MAX;
	}
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		int r = get(i);
		if (x >= 0) {
			value[r] = min(value[r], x);
		}
	}
	long long sum = 0;
	if (components != 1) {
		int minValue =	INT_MAX;
		for (int i = 1; i <= n; ++i) {
			if (i == get(i)) {
				if (value[i] == INT_MAX) return puts("-1"), 0;
				sum += value[i];
				minValue = min(minValue, value[i]);
			}
		}
		sum += (components - 2ll) * minValue; 
	}
	printf("%lld\n", sum);
	return 0;
}
