#include <bits/stdc++.h>
using namespace std;

const int N = 505;
int n, k;
int a[N], b[N];
int c[N];
bool dp[N][N];
int dp2[N][N];
bool dp3[N][N];
bool vis[N][N];

bool solve(int x, int l, int r){

	if(r - l + 1 == 1) return a[l] == x;
	if(vis[l][r]) return dp[l][r];

	bool ans = false;
	for(int i = l; i <= r; ++i){
		int r = c[i] - c[l-1];
		if(solve(x - r) and solve(r)){
			
			dp2[l][r] = i;
			dp3[l][r] = (x-r > r);
			vis[l][r] = true;
			return dp[l][r] = true;
		}
	}
	
	vis[l][r];
	return dp[l][r] = false;
}

void path(int l, int r){

	if(l == r) return;
	path(l, dp2[l][r]);
	path(dp2[l][r]+1, r);	

}

int main(){

	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", a+i);
		c[i] = c[i-1] + a[i];
	}

	scanf("%d", &k);
	for(int i = 1; i <= k; ++i)
		scanf("%d", b+i);

	

	int last = 1;
	bool ok = true;
	int i = 1, j = 1;
	for(; i <= n and j <= k and ok; ++i){
		if(c[i] - c[last-1] == b[j]){
			memset(vis, false, sizeof vis);
			ok = ok and solve(b[j], last, i);
			j++;
			last = i+1;
		}
		else if(c[i] - c[last-1] > b[j]) ok = false;
	}

	if(i == n and j == k and ok){
		
	}
	else
		puts("NO");

	return 0;
}
