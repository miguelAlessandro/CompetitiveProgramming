#include <iostream>
using namespace std;

const int N = 1005;
int A[N][N], dp[N][N];
int n, m;

int main(){

	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			cin >> A[i][j];


	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j){
			if(i == 1 and j == 1) dp[i][j] = A[i][j];
			else if(i == 1) dp[i][j] = dp[i][j-1] + A[i][j];
			else if(j == 1) dp[i][j] = dp[i-1][j] + A[i][j];
			else dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + A[i][j];	
		}


	return 0;
}
