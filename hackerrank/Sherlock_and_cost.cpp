#include <bits/stdc++.h>
using namespace std;

const int N = 100002;
bool vis[N][103];
int dp[N][103];
int b[N], n, t;

int backtracking(int pos, int later){

	if(pos == n) return 0;
	if(vis[pos][later]) return dp[pos][later];

	vis[pos][later] = true;
	return dp[pos][later] = max(backtracking(pos+1, 1) + abs(later - 1), backtracking(pos+1, b[pos]) + abs(later - b[pos]));
}


int main(){

	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);	
		for(int i = 0; i < n; ++i)
			scanf("%d", b+i);

		memset(vis, false, sizeof vis);
		printf("%d\n", max(backtracking(1, 1), backtracking(1, b[0])));
	}
	
	return 0;
}
