#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int N = 1500;
int v[N];
int n;
int f[N], fi[N];
int dp[N][N];
bool vis[N][N];

int V(int n, int k){
	//int r = (1LL*f[n]*fi[k])%MOD;
	return (1LL*f[n]*fi[n-k])%MOD;
}

int backtracking(int pos, int piso){

	if(pos == n) return 1;
	if(vis[pos][piso]) return dp[pos][piso];

	int ans = 0;
	for(int i = pos; i < min(n, piso+pos); ++i)	
		if(v[i] == v[pos])
			ans = (ans + 1LL*V(piso, i-pos+1)*backtracking(i+1, i-pos+1))%MOD;
		else break;
	
	vis[pos][piso] = true;
	return dp[pos][piso] = ans;
}

int expfast(long long a, int b){
	int r = 1;
	while(b){
		if(b&1) r =(r*a)%MOD;
		a =(a*a)%MOD;
		b >>= 1;
	}
	return r;
}


int main(){

	f[0] = 1;
	for(int i = 1; i < N; ++i)
		f[i] = (1LL*i*f[i-1])%MOD;

	fi[0] = 1;
	for(int i = 1; i < N; ++i)
		fi[i] = (1LL*expfast(i, MOD-2)*fi[i-1])%MOD;	


	scanf("%d", &n);

	int t = 0;
	int x;
	scanf("%d", &x);
	v[0] = 0;
	for(int y, i = 1; i < n; ++i){
		scanf("%d", &y);
		if(x <= y) v[i] = t;
		else v[i] = ++t;
		x = y;
	}

	//for(int i = 0; i < n; ++i)
	//	cout << v[i] << " ";
	//cout << endl;

	int ans = 0;
	for(int i = 0; i < n; ++i)
		if(v[i] == 0)
			ans = (ans + backtracking(i+1, i+1))%MOD;
		else break;

	printf("%d\n", ans);

	return 0;
}
