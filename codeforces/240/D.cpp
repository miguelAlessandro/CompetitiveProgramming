#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 2005;
const int MOD = 1000000007;
int n, k;
int dp[N][N];
vector<int> factor[N];

void descomp(int n){
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j*j <= i; ++j)
			if(i%j == 0){
				factor[i].push_back(j);
				factor[i].push_back(i/j);
			}
		sort(factor[i].begin(), factor[i].end());
		factor[i].resize(unique(factor[i].begin(), factor[i].end()) - factor[i].begin());
	}
}

int main(){

	cin >> n >> k;

	descomp(n);
	for(int i = 1; i <= n; ++i) dp[i][1] = 1; 
	for(int i = 2; i <= k; ++i) dp[1][i] = 1;

	for(int i = 2; i <= n; ++i)
		for(int j = 2; j <= k; ++j)
			for(auto l : factor[i])
				dp[i][j] = (dp[i][j] + dp[l][j-1])%MOD;

	int r = 0;
	for(int i = 1; i <= n; ++i) r = (r + dp[i][k])%MOD;

	cout << r << endl;


	return 0;
}
