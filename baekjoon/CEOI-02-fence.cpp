/**
 *	@name CEOI 2002 fence
 *	@author Miguel Mini
 *	@tag dp, dp_kth, math
 *	@idea
 *		- Consider a partial
 *		sequence with k elements:
 *		i1 < i2 < ... < ik, is valid
 *		then when replacing ij by j
 *		the sequence is valid too.  
 *
 *		- proof: if ij < ik then
 *		j < k.
 *
 *		- we can make a dp solution
 * 	dp(n, first_element, isIncreasing)
 *		
 *		if isIncreasing:
 *			sum dp(n-1, i, !isIncreasing) with i < first_element
 *		else:
 *			sum dp(n-1, i-1, !isIncreasing) with i > first_element
 *
 *		note: this dp is possible because
 *		in each subproblem we compress disponible elements.
 *		
 *		[1 2 ... first_element, ...n] 
 *		[1 2 ... xxx first_element, ... n-1]
 *
 *		- We can build the answer using dp sucessively
 *		and compressing the array in each step.
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 22;
bool check[maxn];
bool vis[maxn][maxn][2];
ll memo[maxn][maxn][2];
ll c;

ll add(ll x, ll y) {
	return x+y;
}

ll dp(int n, int fst, bool ch) {
	if (n == 1) return 1;
	if (vis[n][fst][ch]) return memo[n][fst][ch];
	ll &ans = memo[n][fst][ch] = 0;
	if (ch == 0) {
		for (int i = 1; i < fst; ++i) {
			ans = add(ans, dp(n-1, i, not ch));
		}
	} else {
		for (int i = fst+1; i <= n; ++i) {
			ans = add(ans, dp(n-1, i-1, not ch));
		}
	}
	vis[n][fst][ch] = 1;
	return memo[n][fst][ch] = ans;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n >> c;
		vector<pair<int, int>> id;
		for (int i = 1; i <= n; ++i) {
			id.push_back({i, i});
		}
		memset(check, 0, sizeof check);
		vector<int> sol;
		long long cur = 0;
		for (int i = 1; i <= n; ++i) {
			int k = -1;
			bool p;
			for (int j = 0; j < n; ++j) {
				if (check[id[j].second]) continue;
				if (i == 1) {
					for (int d = 0; d < 2; ++d) {
						if (add(cur, dp(n, id[j].first, d)) < c) {
							cur = add(cur, dp(n, id[j].first, d));
						} else {
							k = id[j].second;
							p = d^1;
							break;
						}
					}
				} else {
					if (p == 0 and id[j].second > sol.back()) continue;
					if (p == 1 and id[j].second < sol.back()) continue;
					if (add(cur, dp(n-i+1, id[j].first, not p)) < c) {				
						cur = add(cur, dp(n-i+1, id[j].first, not p));
					} else {
						k = id[j].second;
						break;
					}
				}		
			}
			p ^= 1;
			sol.push_back(k);
			for (int j = 0; j < n; ++j) {
				if (id[j].second > k) id[j].first -= 1;
			}
			check[k] = 1;
		}
		for (int i = 0; i < n; ++i) {
			cout << sol[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
