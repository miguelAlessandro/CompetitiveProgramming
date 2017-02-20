#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 5005;
int k, n, T;
int dp[2000005];
int X[N], Y[N], W[N];

int main(){

	scanf("%d", &k);
	while(k--){
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i){
			scanf("%d %d", X+i, Y+i);
			W[i] = Y[i]*Y[i] - (Y[i]-Y[1])*(Y[i]-Y[1]);		
		}

		memset(dp, -1, sizeof dp);
		dp[X[1]]=0;

		for(int i = 2; i <= n; ++i)
			for(int j = X[i]-1; j >= X[1]; --j){
				if(dp[j]==-1) continue; 
				if((X[i]-j)*(X[i]-j) > W[i]) break;
				
				int& ans = dp[2*X[i]-j];
				if(ans==-1) ans = dp[j]+1;	
				else ans = min(ans, dp[j]+1);

				if(2*X[i]-j >= X[n])
					if(dp[X[n]]==-1) dp[X[n]] = ans;
					else dp[X[n]] = min(dp[X[n]], ans);
			}
			
		if(dp[X[n]]>0) printf("%d\n", dp[X[n]]);
		else puts("-1");
	}

	return 0;
}
