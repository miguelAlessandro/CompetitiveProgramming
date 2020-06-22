/**
 * @name vertex cover
 *	@author Miguel Mini
 * @tag extremal_graph_theory, dp
 *	@idea
 *			- use simple recursion with
 *			dp.
 *			- complexity:
 * 			number of states is 
 *				T[n], consider a node
 *				in solution then T[n]
 *				depend of T[n-1], if 
 *				take maximum degree node
 *				and not consider this,
 *				T[n] depend of T[n - 1 - degree]
 *				then: 
 *					T[n] <= T[n-1] + T[n-3] + O(max_n)
 *				then T[n] ~ n * 1.47**n
 *				with n <= 36 then number of
 *				operations is ~ 3e7.
 *
 *				we can reduce more if consider
 *				solutions to paths and cycles.
 */	

#include <bits/stdc++.h>
using namespace std;
const int maxn = 40;
int MOD;
int n, m;
long long mask[maxn];
int W[maxn], w[maxn];
long long target;
 
int add(int a, int b, int mod = MOD) {
	return (a + b) % mod;
}
 
int mul(long long a, long long b, int mod = MOD) {
	return a * b % mod;
}
 
unordered_map<long long, int> dp;
 
int bt(long long Mask) {
	if (Mask == 0) return 1;
	if (dp.count(Mask)) return dp[Mask];	
	int lso = 63 - __builtin_clzll(Mask & -Mask);
	for (int i = lso + 1; i < n; ++i) {
		if (Mask & (1ll<<i)) {
			if (__builtin_popcountll(Mask & mask[i]) > __builtin_popcountll(Mask & mask[lso])) {
				lso = i;
			}
		}
	}	
	int W = 1;
	for (int i = 0; i < n; ++i) {
		if ((Mask&(1ll<<i)) and (mask[lso] & (1ll<<i)) and i != lso) {
			W = mul(W, w[i]); 
		}
	}
	int ans = 0;
	int temp = bt(Mask ^ (1ll<<lso));
	ans = add(ans, mul(w[lso], temp));
	if (mask[lso] != (1ll<<lso)) {
		ans = add(ans, mul(W, bt(Mask & ~mask[lso])));
	} else {
		ans = add(ans, temp);
	}
	dp[Mask] = ans;
	return ans;
}
 
int main() {
	int t;
	cin >> t;
	for (int nc = 1; nc <= t; ++nc) {
		dp.clear();
		cin >> n >> m >> MOD;
		for (int i = 0; i < n; ++i) cin >> w[i];
		target = (1LL<<n) - 1;
		for (int i = 0; i < n; ++i) {
			mask[i] = 1ll<<i;
			W[i] = 1;
		}
		for (int i = 1; i <= m; ++i)	{
			int u, v;
			cin >> u >> v;
			u -= 1; v -= 1;
			mask[u] |= (1LL<<v);
			W[u] = mul(W[u], w[v]);
			mask[v] |= (1LL<<u);
			W[v] = mul(W[v], w[u]);
		}
		cout << "Case #" << nc << ": " << bt(target) << endl;
	}
	return 0;	
}
