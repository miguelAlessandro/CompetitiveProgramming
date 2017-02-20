#include <bits/stdc++.h>
using namespace std;

const int N = 105;
vector<int> a;
int dp[N][N];

vector<int> div(int n){
	
	vector<int> a;
	for(int i = 1; i*i <= n; ++i)
		if(n%i == 0)
			a.push_back(i), 
			a.push_back(n/i);

	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());
	return a;
}



bool DP(int n, int k){
	if(n == 0) return false;
	if(dp[n][k] != -1) return dp[n][k];
	for(int x : a)
		if(n >= x and not DP(n-x, k)) return dp[n][k] = true;

	return dp[n][k] = false;
}


int main(){

	for(int i = 2; i < N; ++i){
		bool t = false;
		for(int j = 1; j < i; ++j){
			a = div(j);
			t |= (not DP(i-j, j));
		}
		cout << i << " " << t << endl;
	}
	
	return 0;
}
