#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e6 + 10;
int s[maxN];
int rnk[maxN];
int id[maxN];
int best[maxN];

int get(int x) {return x==id[x]?x:id[x]=get(id[x]);}

void merge(int x, int y) {
	x = get(x);
	y = get(y);
	if (x == y) {
		puts("Invalid query!");
		return;
	}
	if (s[x] == s[y]) return;
	if (rnk[x] < rnk[y]) swap(x, y);
	best[x] = s[x] > s[y] ? best[x] : best[y];  
	id[y] = x;
	s[x] = max(s[x], s[y]);
	rnk[x] += rnk[x] == rnk[y];
}

int t, n, q;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			id[i] = i;
			best[i] = i;
			rnk[i] = 0;
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d", s+i);
		}
		scanf("%d", &q);
		while (q--) {
			int type;
			scanf("%d", &type);
			if (type) {
				int x;
				scanf("%d", &x);
				printf("%d\n", best[get(x)]);
			} else {
				int x, y;
				scanf("%d %d", &x, &y);
				merge(x, y);
			}
		}
	}
	return 0;
}
