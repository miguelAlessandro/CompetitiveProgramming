#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 505;
int t, n;
int a[N];
int dp[N][25][25];



int backtracking(int pos, int a1, int a2){

	if(pos == n-1) return a1 != a[pos] and a2 != a[pos];
	if(dp[pos][a1][a2] != -1) return dp[pos][a1][a2];

	int ans = 1000000000;
	if(a[pos] == a1 or a[pos] == a2) ans = min(ans, backtracking(pos+1, a1, a2));
	if(a[pos] != a1) ans = min(ans, backtracking(pos+1, a[pos], a2) + 1);
	if(a[pos] != a2) ans = min(ans, backtracking(pos+1, a1, a[pos]) + 1);	
	
	return dp[pos][a1][a2] = ans;
}


int main(){	

	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		
		for(int i = 0; i < n; ++i)
			scanf("%d", a+i);			 

		memset(dp, -1, sizeof dp);
		printf("%d\n", backtracking(0, 0, 0));
	}

	return 0;
}
