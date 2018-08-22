/**
 *  SPOJ / INCFSEQ
 *  @overview find number of distincts increasing subsequence with lengh k.
 *  dp[last][k] : number of increasing k-length subsequence with last element "last".
 *  dp[last][k] = sum_{i=-oo}^{k-1} dp[last][k-1] as long as add I an element to my array.
 */



#include <bits/stdc++.h>
using namespace std;

const int mod = 5e6;
const int MAX_N = 1e4 + 5;
int ft[MAX_N][55];
int val[MAX_N];
int N, K;
int add(int a, int b) {
	return (a+b)%mod;
}
void upd(int id, int x, int v) {
	while (x < MAX_N) {
		ft[x][id] = add(ft[x][id], v);
		x += x&-x;
	}
}
int query(int id, int x) {
	int ans = 0;
	while (x > 0) {
		ans = add(ans, ft[x][id]);
		x -= x&-x;
	}
	return ans;
}

int main () {
	
	int N, K;
	scanf ("%d %d", &N, &K);
	map<int, int> id;
	for (int i = 0; i < N; ++i) {
		scanf("%d", val+i);
		id[val[i]];
	}
	int t = 2;
	for (auto& v : id)
		v.second = t++;
	for (int i = 0; i < N; ++i)
		val[i] = id[val[i]];
		
	upd(0, 1, 1);
	for (int i = 0; i < N; ++i) {
		for (int j = K; j >= 1; --j) {
			int lans = query(j-1, val[i]-1);
			int rans = query(j, val[i]) - query(j, val[i]-1);
			upd(j, val[i], add(lans, mod-rans));
		}
	}
	printf ("%d\n", query(K, N+1));
	
	return 0;
}
