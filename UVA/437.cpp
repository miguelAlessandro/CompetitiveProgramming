#include <iostream>
#include <cstdio>
using namespace std;

const int N = 35;
int n, H[N][3];
long long dp[N][N][3];
int bitmask[N][N][3];


int main(){

	while(scanf("%d", &n), n){
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < 3; ++j)
				scanf("%d", &H[i][j]);
				
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < 3; ++j){
				dp[0][i][j] = H[i][j];
				bitmask[0][i][j] |= (1<<i);
			} 

		for(int i = 1; i < n; ++i)
			for(int j = 0; j < n; ++j)
				for(int h = 0; h < 3; ++h)
					for(int k = 0; k < n; ++k)
						for(int l = 0; l < 3; ++l)
							if((1<<j)&~bitmask[i-1][k][l] and H[k][(l+1)%3]*H[k][(i+2)%3] >= H[j][(h+1)%3]*H[j][(h+2)%3] 
								and dp[i][j][h] < dp[i-1][k][l] + H[j][h]){
								dp[i][j][h] = dp[i-1][k][l] + H[j][h];
								bitmask[i][j][k] = bitmask[i-1][k][l] | (1<<j);
							}
		
		long long maxi = 0;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < 3; ++j)
				maxi = max(maxi, dp[n-1][i][j]);
		printf("%lld\n", maxi);
	}	

	return 0;
}
