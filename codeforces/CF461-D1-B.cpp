/**
 * @author Miguel Mini
 * @tag dp on trees, connect component approach
 * @idea
 *    - connect component aplication
 *
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n), c(n);
	const int mod = 1e9 + 7;
	auto add = [](int a, int b)->int {return (a + b) % mod;};
	auto mul = [](long long a, long long b)->int {return a*b % mod;};
	for (int i = 1; i < n; ++i) cin >> v[i];
	vector<vector<int>> dp(n, vector<int>(2, 0));
	for (int i = 0; i < n; ++i) cin >> c[i], dp[i][c[i]] = 1;
	for (int i = n-1; i > 0; --i) {
		dp[v[i]][1] = mul(dp[v[i]][1], add(dp[i][0], dp[i][1]));
		dp[v[i]][1] = add(dp[v[i]][1], mul(dp[v[i]][0], dp[i][1]));	
		dp[v[i]][0] = mul(dp[v[i]][0], add(dp[i][0], dp[i][1]));
	}
	printf("%d\n", dp[0][1]);
	return 0;
}
