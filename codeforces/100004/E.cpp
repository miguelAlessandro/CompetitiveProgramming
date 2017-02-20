#include <bits/stdc++.h>
using namespace std;

int n, l, t, tc;
int P[26][1005], E[26][1005]; 
long long dp[26][1000005];
bool vis[26][1000005];

long long backtracking(int day, int e){

	if(day == n+1) return abs(l-e);
	if(vis[day][e]) return dp[day][e];

	long long ans = LLONG_MAX;
	for(int i = 0; i < t; ++i)
		ans = min(ans, backtracking(day+1, P[day][i]) + E[day][i] + abs(e - P[day][i]));

	vis[day][e] = true;
	return dp[day][e] = ans;
}

int main(){

	scanf("%d", &tc);
	while(tc--){
		scanf("%d %d %d", &n, &t, &l);

		for(int i = 1; i <= n; ++i) memset(vis[i], false, sizeof vis[i]);

		for(int i = 1; i <= n; ++i)
			for(int j = 0; j < t; ++j)
				scanf("%d %d", &P[i][j], &E[i][j]);

		printf("%I64d\n", backtracking(1, 0));
	}


	return 0;
}
