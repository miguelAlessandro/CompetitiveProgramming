#include <bits/stdc++.h>
using namespace std;

int dp[64*1024 + 1][16][3];
int n;
long long X[16][3];

long long H(int i, int j){
	return X[i][j];
}

long long area(int i, int j, int k, int l){
	return max(X[i][(j+1)%3], X[i][(j+2)%3]) >= max(X[k][(l+1)%3], X[k][(l+2)%3]) and
		   min(X[i][(j+1)%3], X[i][(j+2)%3]) >= min(X[k][(l+1)%3], X[k][(l+2)%3]);
}

long long backtrack(int bitmask, int top, int pos){
	if(bitmask == (1<<n)-1) return 0;	
	if(dp[bitmask][top][pos] != -1) return dp[bitmask][top][pos];

	long long r = 0;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < 3; ++j)
			if(not(bitmask&(1<<i)) and area(top, pos, i, j))
				r = max(r, backtrack(bitmask|(1<<i), i, j) + H(i, j));

	return dp[bitmask][top][pos] = r;						
}


int main(){

	cin >> n;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < 3; ++j)
			cin >> X[i][j];

	for(int i = 0; i < (1<<n); ++i)
		for(int j = 0; j < n; ++j)
			for(int k = 0; k < 3; ++k)
				dp[i][j][k] = -1;

	long long r = 0;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < 3; ++j)
			r = max(r, backtrack(1<<i, i, j) + H(i, j));	
	
	cout << r << endl;

	return 0;
}
