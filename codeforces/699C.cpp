#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n;
int a[N];
int dp[N][3];

int bt(int i, int k){

	if(i == 0){
		if(a[i] == 0) return 0;
		if(a[i]&1 and k == 1) return 1;
		if(a[i] >= 2 and k == 2) return 1;
		return 0;
	}	
	if(dp[i][k] != -1) return dp[i][k];
	int r = 0;
	if(k == 0){
		r = max(r, bt(i-1, 0));
		if(a[i-1] >= 2)r = max(r, bt(i-1, 2));
		if(a[i-1]&1)   r = max(r, bt(i-1, 1));
	}
	if(a[i]&1 and k == 1){
		r = max(r, bt(i-1, 0) + 1);
		if(a[i-1] >= 2) r = max(r, bt(i-1, 2) + 1);
	}
	if(a[i] >= 2 and k == 2){
		r = max(r, bt(i-1, 0) + 1);
		if(a[i-1]&1) r = max(r, bt(i-1, 1) + 1);
	}
	
	return dp[i][k] = r;
}

int main(){

	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < 3; ++j)
			dp[i][j] = -1;

	int r = bt(n-1, 0);
	if(a[n-1]&1) r = max(r, bt(n-1, 1));
	if(a[n-1]>=2) r = max(r, bt(n-1, 2));
	cout << n-r << endl;	


	return 0;
}
