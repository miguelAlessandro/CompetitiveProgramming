/** 
 *  codeforces 245 Epecial H
 *  @overview find number of palindromic substring of a substring
 *  solution:
 *  - use hashing 
 *  - number of substring from a to b is equal to 
 *    sum_{l=1}^{b-a+1} number_of_substring_from_1_to_b_of_length_l - number_of_substring_from_1_to_{a+l-1}_of_length_l
 */


#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5005;
const int mod[2] = {(int)1e9+7, (int)1e9+9};
const int p[2] = {1011, 257};
char s[MAXN];
int P[2][MAXN];
int _hash[2][2][MAXN];
int sum[MAXN], dp[MAXN][MAXN], rest[MAXN][MAXN];

int add(int a, int b, int mod) {
	return (a+b)%mod;
}

int mul(long long a, long long b, int mod) {
	return a*b%mod;
}

int ex(int a, int b, int mod) {
	int r = 1;
	while (b > 0) {
		if (b&1) r = mul(r, a, mod);
		a = mul(a, a, mod);
		b >>= 1;
	}
	return r;
}

int main () 
{
	scanf("%s", s);
	int n = strlen(s);

	for (int k = 0; k < 1; ++k) {
		P[k][0] = 1;
		for (int i = 1; i <= n; ++i)
			P[k][i] = mul(P[k][i-1], p[k], mod[k]);
	}
	int invp[2];
	for (int k = 0; k < 1; ++k)
		 invp[k] = ex(p[k], mod[k]-2, mod[k]);
	
	for (int l = 1; l <= n; ++l) {
		for (int k = 0; k < 1; ++k) { 
		
			int H = 0;
			for (int i = 0; i < l; ++i) {
				H = add(H, mul(s[i], P[k][i], mod[k]), mod[k]);
			}
	
			_hash[k][0][0] = H;
			for (int i = l; i < n; ++i) {
				H = add(H, mod[k] - s[i-l], mod[k]);
				H = mul(H, invp[k], mod[k]);
				H = add(H, mul(s[i], P[k][l-1], mod[k]), mod[k]);
				_hash[k][0][i-l+1] = H;
			}
		
			H = 0;
			for (int i = 0; i < l; ++i) {
				H = add(H, mul(s[n-1-i], P[k][i], mod[k]), mod[k]);
			}
	
			_hash[k][1][n-l] = H;
			for (int i = l; i < n; ++i) {
				H = add(H, mod[k] - s[n+l-1-i], mod[k]);	
				H = mul(H, invp[k], mod[k]);		
				H = add(H, mul(s[n-1-i], P[k][l-1], mod[k]), mod[k]);
				_hash[k][1][n-1-i] = H;
			}
		}		

		for (int i = 0; i < l; ++i) sum[i] = 0;
		sum[l-1] = (_hash[0][0][0] == _hash[0][1][0] and _hash[1][0][0] == _hash[1][1][0]);
		for (int i = 1; i+l-1 < n; ++i) {
			sum[l-1+i] = sum[l+i-2] + (_hash[0][0][i] == _hash[0][1][i] and _hash[1][0][i] == _hash[1][1][i]);
		}

		for (int i = 0; i < n; ++i) {
			dp[l][i] = dp[l-1][i] + sum[i];
			rest[l][i] = rest[l-1][i] + (i+l-1 < n ? sum[i+l-1] : 0);
		}
	}

	int q;
	scanf("%d", &q);
	while (q--) {
		int a, b;
		scanf("%d %d", &a, &b);

		int res = 0;
		if (a != 1) {
			res = rest[b-a+1][a-2];
		}
	
		printf("%d\n", dp[b-a+1][b-1] - res);
	}

	return 0;
}
