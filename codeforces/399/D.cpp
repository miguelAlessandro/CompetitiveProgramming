#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-7;
const int N = 1005;
int k, q, p, f = 1;
double dp[N];
int ans[N];

int main(){

	cin >> k >> q;
	
	dp[0] = 1;
	for(int i = 1; f <= 1000; ++i){
		for(int j = k; j > 0; --j)
			dp[j] = (j*dp[j] + (k-j+1)*dp[j-1])/k;
		
		while(f <= 1000 and 2000*dp[k] >= f-eps)
			ans[f++] = i;
		
		dp[0] = 0;
	}

  

	while(q--){
		cin >> p;
		cout << ans[p] << endl;
	}

	return 0;
}
