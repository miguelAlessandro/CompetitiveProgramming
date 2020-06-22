#include <bits/stdc++.h>
using namespace std;
typedef long long llong;
llong dp[2][2520][2][50];
int lcm[1<<8], idx[2550];
int g[2550][10];
int k[2550][10];
int f[10], mask[50];
int n;
vector<int> s;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}


int main() {
	set<int> ss;
	for (int i = 0; i < 1<<8; ++i) {
		lcm[i] = 1;	
		for (int j = 0; j < 8; ++j) {
			if (i & (1<<j))
				lcm[i] *= (j + 2) / gcd(j+2, lcm[i]);
		}
		ss.insert(lcm[i]);
	}
	int nc = 0;
	for (int e : ss) {
		mask[nc] = e;
		idx[e] = nc++;
		for (int i = 0; i <= 9; ++i) {
			g[e][i] = i == 0 ? e : e * i / gcd(e, i);
		}	
	}	
	
	for (int i = 0; i < 2520; ++i) {
		for (int j = 0; j <= 9; ++j) {
			k[i][j] = (i * 10 + j) % 2520;
		}
	}

	for (int e : ss)
		for (int i = 0; i <= 9; ++i)
			g[e][i] = idx[g[e][i]];

	int t;
	cin >> t;
	while (t--) {
		llong x[2];
		long long ans = 0;
		for (int i = 0; i < 2; ++i) {	
			cin >> x[i];
			if (i == 0) x[i] -= 1;
			s.clear();
			if (x[i] == 0) s.push_back(0);
			else {
				while (x[i] > 0) {
					s.push_back(x[i] % 10);	
					x[i] /= 10;
				}
				reverse(begin(s), end(s));
			}
			n = s.size();
			llong lans = 0;
			for (int mod = 0; mod < 2520; ++mod)			
				for (int f = 0; f < 2; ++f)
					for (int set = 0; set < nc; ++set)
						dp[n&1][mod][f][set] = mod % mask[set] == 0;

			for (int pos = n-1; pos >= 0; --pos)
				for (int mod = 0; mod < 2520; ++mod)
					for (int r = 0; r < 2; ++r)
						for (int set = 0; set < nc; ++set) {
							llong& ans = dp[pos&1][mod][r][set] = 0;
							for (int d = 0; d <= (r ? s[pos] : 9); ++d) 
								ans += dp[pos&1^1][k[mod][d]][r and s[pos] == d][g[mask[set]][d]];
						}
			
			lans = dp[0][0][1][0];
			if (i == 0) ans -= lans;
			else ans += lans;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
