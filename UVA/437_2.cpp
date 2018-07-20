#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 35;
int n;
long long a[N][5];
long long dp[3*N][N][5];

bool p(int j, int k, int l, int m){
	int j1 = a[j][(k+1)%3], j2 = a[j][(k+2)%3],
		l1 = a[l][(m+1)%3], l2 = a[l][(m+2)%3];
	if(j1 < j2) swap(j1, j2);
	if(l1 < l2) swap(l1, l2);
	return j1 < l1 and j2 < l2;
}

int main(){

	int nc = 1;
	while(scanf("%d", &n), n){
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < 3; ++j)
				scanf("%lld", &a[i][j]);		
		
		memset(dp, 0, sizeof dp);
		
		for(int i = 0; i < n; ++i) 
			for(int j = 0; j < 3; ++j)
				dp[0][i][j] = a[i][j];

				
		for(int i = 1; i < 3*n; ++i)
			for(int j = 0; j < n; ++j)
				for(int k = 0; k < 3; ++k)
					for(int l = 0; l < n; ++l)
						for(int m = 0; m < 3; ++m)
							if(p(j, k, l, m) and dp[i-1][l][m] + a[j][k] > dp[i][j][k])
								dp[i][j][k] = dp[i-1][l][m] + a[j][k];
	
		long long maxi = 0;
		for(int i = 0; i < 3*n; ++i)
			for(int j = 0; j < n; ++j)
				for(int k = 0; k < 3; ++k)
					maxi = max(maxi, dp[i][j][k]);
		
		printf("Case %d: maximum height = %lld\n", nc++, maxi);
	}

	return 0;
}
