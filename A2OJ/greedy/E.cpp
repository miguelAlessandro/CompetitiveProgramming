#include <bits/stdc++.h>
using namespace std;

vector<int> divr(int n){

	vector<int> D;
	
	for(int i = 1; i*i <= n; ++i)
		if(n%i == 0){
			D.push_back(i);
			D.push_back(n/i);
		}
		
	sort(D.begin(), D.end());
	D.resize(unique(D.begin(), D.end()) - D.begin());	

	return D;
}


const int N = 1000002;
const int MOD = 1000000007;
int t, n, nc=1;
long long dp[N], dpr[N], r[N];


int expfast(long long a, int n){
	
	long long r = 1;
	while(n){
		if(n&1) r = (r*a)%MOD;
		
		a = (a*a)%MOD;
		n >>= 1;
	}	

	return r;
}

int main(){

	for(int i = 1; i < N; ++i)
		r[i] = expfast(i, MOD-2);

	dp[0] = 1;
	dpr[0] = 1;
	for(int i = 1; i < N; ++i){
		dp[i] = (i*dp[i-1])%MOD;
		dpr[i] = (r[i]*dpr[i-1])%MOD;
	}

	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);

		vector<int> di = divr(n);
		
		int ans = 0;
		for(int i = 0; i < di.size(); ++i)
			ans = (ans + (((dp[n]*expfast(dpr[di[i]], n/di[i]))%MOD)*dpr[n/di[i]])%MOD)%MOD;

		printf("Case %d: %d\n", nc++, ans);
	}



	return 0;
}
