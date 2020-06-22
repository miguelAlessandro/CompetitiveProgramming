/**
 *	@name POI-04-Maximal
 *	@author Miguel Mini
 *	@tag dp, group_theory, greedy
 *	@idea
 *		- we need sum x_i <= n
 * 	with max(product x_i).
 *		
 *		- if gcd(x_i, x_j) > 1, 
 *		we set u_i = x_i/d, 
 *		u_j = x_j/d, u_k = d
 *		and replace {x_i, x_j} 
 * 	with {u_i, u_j, u_k}.
 *		we have x_i + x_j <= 
 *		d * (u_i + u_j) <=
 *		d + u_i + u_j (d > 1).
 *		
 *		- if p, q prime divide x_i
 *		then x_i = (p^a)(q^b)y, reeplace 
 *		x_i with {p^a, (q^b)y}.
 *
 *		- to solve dp, use log instead 
 *		usual product.
 *
 * 	- greedy_choice: use x_i in order.
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 2;
const int maxp = 930;
bool composite[maxn];
vector<short> prime;
float Log[maxn];
float memo[maxp][maxn];
bool vis[maxp][maxn];
short tr[maxp][maxn];

void sieve(int n) {
	for (int i=2; i<=n; ++i) {
		if (not composite[i]) {
			prime.emplace_back(i);
			Log[i] = log(i);
		}
		for (auto p : prime) {
			if (p*i>n) break;
			composite[p*i]=1;
			if (i%p==0) break;
		}
	}
}

float dp(int pos, int n) {
	if (pos == maxp) return 0;
	if (vis[pos][n]) return memo[pos][n];
	int p = 1;
 	float &ans = memo[pos][n] = dp(pos+1, n);
	tr[pos][n] = -1;
	for (int k = 0; k <= 13; ++k) {
		if (n < p) break;
		float temp = k * Log[prime[pos]] + dp(pos+1, n-p);
		if (ans < temp) {
			ans = temp;
			tr[pos][n] = p;
		}
		p *= prime[pos];
	}
	vis[pos][n] = 1;
	return ans;
}


int main() {
	sieve(1e4);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		dp(0, n);
		int pos = 0;
		vector<int> ranges;
		while (pos < maxp) {
			if (~tr[pos][n]) {
				int p = tr[pos][n];
				ranges.emplace_back(p);
				n -= p;
			}
			pos += 1;
		}
		for (int k = 0; k < n; ++k) {
			ranges.emplace_back(1);
		}
		int i = 1;
		sort(ranges.begin(), ranges.end());
		for (int p : ranges) {
			for (int k = 1; k < p; ++k) cout << i + k << " ";
			cout << i << " ";
			i += p;
		}
		cout << endl;
	}
	return 0;
}
