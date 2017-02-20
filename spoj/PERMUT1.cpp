#include <iostream>
using namespace std;

int n, k, d, dp[13][100];

int main(){

	dp[1][0] = 1;
	for(int i = 1; i <= 12; ++i)
		for(int j = 0; 2*j <= i*(i-1); ++j)
			for(int k = 0; k <= min(i-1, j); ++k)	
				dp[i][j] += dp[i-1][j-k];

	cin >> d;
	while(d--){
		cin >> n >> k;
		cout << dp[n][k] << endl;
	}

	return 0;
}
