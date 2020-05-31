/**
 * @author Miguel Mini
 * @tag dp, xor, retrieve the answer
 * @idea
 *      - dp(pos, taked_bits)
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 52;
long long a[maxn];
int mx, n;
bool vis[maxn][70];
bool memo[maxn][70];
int tr[maxn][70];

bool dp(int pos, int on_bits) {
	if (pos == n) return on_bits == 0;
	if (vis[pos][on_bits]) return memo[pos][on_bits];
	bool &ans = memo[pos][on_bits] = false;
	int t = __builtin_popcountll(a[pos]);
	for (int i = 0; i <= min(t, on_bits); ++i) {
		if ((t - i) + (on_bits - i) + i <= mx + 1) {
			bool temp = dp(pos + 1, t + on_bits - 2 * i);
			if (temp) {
				tr[pos][on_bits] = i;
				ans = true;
				break;
			}
		}
	}
	vis[pos][on_bits] = 1;
	return ans;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		mx = max(mx, 63 - __builtin_clzll(a[i]));
	}
	if (not dp(0, 0)) cout << "impossible" << endl; 	
	else {
		long long r = 0;
		int on_bits = 0;
		for (int pos = 0; pos < n; ++pos) {
		 	int t = __builtin_popcountll(a[pos]);
			int p = tr[pos][on_bits];
			int x = t, y = p;
			a[pos] = 0;
			for (int i = 0; i <= mx; ++i) {
				if ((r>>i)&1) {
					if (y > 0) {					
						a[pos] |= 1ll<<i;
						y -= 1;
						x -= 1;
					}
				}	
			}
			for (int i = 0; i <= mx; ++i) {
				if ((r>>i)&1^1) {
					if (x > 0) {
						a[pos] |= 1ll<<i;
						x -= 1;
					}
				}
			}
			cout << a[pos] << " ";
			r ^= a[pos];
			on_bits += t - 2 * p;
		}
		cout << endl;
	}
	return 0;
}
