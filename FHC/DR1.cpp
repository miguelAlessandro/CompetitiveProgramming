#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int N = 2005;
int t, n, m, nc=1;
int R[N];
int inv[N], fm[N<<1];

int expfast(int a, int n){
	int r = 1;
	while(n){
		if(n&1) r = (1LL*r*a)%MOD;
		a = (1LL*a*a)%MOD;
		n >>= 1;
	}
	return r;
}

int main(){

	for(int i = 2; i < N; ++i) inv[i] = expfast((i*i - i)/2, MOD-2);

	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &m);
		
		int len = 0;
		for(int i = 0; i < n; ++i){
			scanf("%d", R+i);	
			len += 2*R[i];
		}

		if(n == 1){
			printf("Case #%d: %d\n", nc++, m);
			continue;
		}

		for(int i = 0; i < 2*N; ++i){
			fm[i] = 1;
			for(int j = 1; j <= n; ++j)
				fm[i] = (1LL*(m-len+i+j)*fm[i])%MOD;
		}

		int ans = 0;
		for(int i = 0; i < n; ++i)
			for(int j = i+1; j < n; ++j)
				if(m + R[i] + R[j] >= 1 + len) ans = (ans + fm[R[i]+R[j]-1])%MOD;

		ans = (1LL*ans*inv[n])%MOD;
		printf("Case #%d: %d\n", nc++, ans);
	}

	return 0;
}
