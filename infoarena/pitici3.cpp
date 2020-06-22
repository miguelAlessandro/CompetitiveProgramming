/**
 * @name pitici3
 *	@author Miguel Mini	
 *	@tag dp, exchange_argument
 *	@idea:
 *			- every dwarf only can 
 *			charge at most
 *				x = sum_h - d + l
 *			if we consider two dwarf
 *			with (h1, x1), (h2, x2)
 *			and is possible first
 *			one above the second one
 *			and not reverse:
 *				
 *			x1 >= h2 and h1 <= x2
 *
 *			then h1 + x1 >= h2 + x2
 *
 *			if we have that order,
 *			we can use dp[t] : the	
 *			minimum height to stack
 *			t consecutive dwarf.
**/


#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 10;
struct Node {
	int h, l;
} p[maxn];
int n, d;
int dp[maxn];

int main() {
	freopen("pitici3.in", "r", stdin);
	freopen("pitici3.out", "w", stdout);
	scanf("%d", &n);
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &p[i].h, &p[i].l);
		sum += p[i].h;
	}
	scanf("%d", &d);
	sort(p, p+n, [](Node x, Node y) {
		return x.h + x.l < y.h + y.l;
	});
	for (int i = 1; i <= n; ++i) dp[i] = 1e9;
	dp[0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = n; j >= 1; --j) {
			if (sum - dp[j-1] + p[i].l >= d) {
				dp[j] = min(dp[j], dp[j-1] + p[i].h);
			}
		}
	}
	int ans = 0;
	for (int i = n; i >= 1; --i) {
		if (dp[i] <= sum) {
			ans = i;
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}
