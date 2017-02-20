#include <iostream>
#include <cstdio>
using namespace std;

const int N = 22;
const long long MOD = 1000000009;
int n, m, k, d;
long long adj[N][N];
long long r[N][N], a[N][N], c[N][N], D[N][N];

void mul(){
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			c[i][j] = r[i][j];

	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j){
			r[i][j] = 0;
			for(int k = 1; k <= n; ++k)
				r[i][j] = (r[i][j] + c[i][k]*a[k][j])%MOD;
		}
}

void cua(){
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			c[i][j] = a[i][j];

	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j){
			a[i][j] = 0;
			for(int k = 1; k <= n; ++k)
				a[i][j] = (a[i][j] + c[i][k]*c[k][j])%MOD;
		}
}

void init(){
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			r[i][j] = i == j;
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			a[i][j] = D[i][j];
}

void expfast(int m){
	init();
	while(m > 0){
		if(m&1) mul();
		cua();
		m >>= 1;
	}
}

int main(){

	scanf("%d %d %d %d", &n, &m, &k, &d);
	
	for(int x, y, i = 0; i < m; ++i){
		scanf("%d %d", &x, &y);
		adj[x][y] = adj[y][x] = 1;
	}

	long long ans = 0;

	for(int mask = 0; mask < (1<<k); ++mask){
		
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				D[i][j] = adj[i][j];
	

		for(int i = 1; i <= k; ++i)
			if(mask&(1<<i-1))
				for(int j = 1; j <= n; ++j) 
					D[i][j] = D[j][i] = 0;
				
		expfast(d-1);

		long long nans = 0;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				nans = (nans + r[i][j])%MOD;

		if(__builtin_popcount(mask)&1) ans = ((ans - nans)%MOD + MOD)%MOD;
		else ans = (ans + nans)%MOD;
	}

	printf("%lld\n", ans);

	return 0;
}
