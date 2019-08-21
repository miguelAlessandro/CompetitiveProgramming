/**
 * @name AtCoder 012 AGC D
 * @author Miguel Mini
 * @tag greedy
 * @idea
 *	- if x = y = infinity then answer = n! / prod((#c[i])!)
 *	- let c[i] == c[j] and w[i] + w[j] <= x then i and j are swapeables 
 *	- let minw[c[i]] equal to min weight with color c[i], 
 *	if w[i] + minw[c[i]] <= x then set w[i] = minw[c[i]] (are swapeables) 
 *	- let c[i] != c[j] and w[i] + w[j] <= y then i and j are swapeables
 *	- first greedy observation: the graph with nodes from 1 to n and edges 
 *	(i, j) with i and j swapeables can permute. Let t = min(minw[c[i]]),
 *	only the graph with root t has distinct colors. 
 *	- second greedy observation: let u = second min(minw[c[i]]) then
 *	every node in this graph distinct of t and u have an edge to u or t.
 */

#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 10;
const int mod = 1e9 + 7;
int c[maxN], w[maxN];
int minw[maxN];
int f[maxN], r[maxN], rf[maxN];
int cnt[maxN];
int n, x, y;

int main() {
	f[0] = rf[0] = r[1] = 1;
	for (int i = 1; i < maxN; ++i) {
		if (i > 1) r[i] = (mod - (mod/i)*1ll*r[mod%i]%mod)%mod;
		f[i] = f[i-1]*1ll*i%mod;
		rf[i] = rf[i-1]*1ll*r[i]%mod;
	}
	cin >> n >> x >> y;
	for (int i = 1; i <= n; ++i) minw[i] = 2e9;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i] >> w[i];
		minw[c[i]] = min(minw[c[i]], w[i]);
	}
	for (int i = 1; i <= n; ++i) {
		if (minw[c[i]] + w[i] <= x) w[i] = minw[c[i]];
	}
	int color = min_element(minw+1, minw+n+1) - minw;
	int best = minw[color];
	int second = 2e9;
	for (int i = 1; i <= n; ++i) {
		if (i == color) continue;
		second = min(second, minw[i]);
	}
	int k = 0;
	int comm = 1;
	auto add = [&](int c) {
		k += 1;
		cnt[c] += 1;
	};
	for (int i = 1; i <= n; ++i) {
		if (color != c[i]) {
			if (best + w[i] <= y) add(c[i]);
		} else {
			if (best == w[i]) {			
				if (comm) {
					add(c[i]);
					comm = 0;
				} else {
					if (best + w[i] <= x or second + w[i] <= y) add(c[i]);
				}
			} else {
				if (second + w[i] <= y) add(c[i]);
			}
		}
	}
	int ans = f[k];
	for (int i = 1; i <= n; ++i) ans = ans*1ll*rf[cnt[i]]%mod;
	cout << ans << endl;
	return 0;
}
