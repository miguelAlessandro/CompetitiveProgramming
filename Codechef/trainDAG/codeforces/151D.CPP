#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 10;
const int mod = 1e9 + 7;
int id[maxN];
int rnk[maxN];

int get(int x) {return x==id[x]?x:id[x]=get(id[x]);}

void Union(int x, int y) {
	x = get(x);
	y = get(y);
	if (x == y) return;
	if (rnk[x] < rnk[y]) swap(x, y);
	id[y] = x;
	rnk[x] += rnk[x] == rnk[y];
}


int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) {
		id[i] = i;
	}
	for (int i = 1; i <= n; ++i) {
		if (i + k - 1 <= n) {
			for (int j = 0; j+j < k; ++j) {	
				Union(i + j, i + k - 1 - j);
			}
		} else break;
	}
	int ans = 1;
	for (int i = 1; i <= n; ++i) {
		if (id[i] == i) {
			ans = ans *1ll* m % mod;
		}
	}
	cout << ans << endl;
	return 0;
}
