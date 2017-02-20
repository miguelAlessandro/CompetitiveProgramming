#include <iostream>
#include <cstring>
using namespace std;

int dp[1<<16];
int n;
int h[20];

bool triangle(int a, int b, int c){
	return a+b > c and b+c > a and a+c > b;
}

int backtracking(int bitmask){
	if(bitmask+1 == (1<<n)) return 0;
	if(dp[bitmask] != -1) return dp[bitmask];

	int ans = 0;
	for(int i = 0; i < n; ++i) if((~bitmask)&(1<<i))
		for(int bm = bitmask|(1<<i), j = i+1; j < n; ++j)	if((~bm)&(1<<j))
			for(int bm2 = bm|(1<<j), k = j+1; k < n; ++k) if((~bm2)&(1<<k))
				ans = max(ans, backtracking(bm2|(1<<k)) + triangle(h[i], h[j], h[k]));

	return dp[bitmask] = ans;
}


int main(){

	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> h[i];

	memset(dp, -1, sizeof dp);

	cout << backtracking(0) << endl;

	return 0;
}
