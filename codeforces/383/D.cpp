#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int dp[N][N];
bool vis[N][N];
bool V[N];
bool A[N][N];
int W[N], B[N];
int WG[N], BG[N];
int n, l, m, w;
vector<int> group[N];

int backtracking(int pos, int ww){
	if(pos == l+1) return 0; 
	if(vis[pos][ww]) return dp[pos][ww];
	
	int ans = backtracking(pos+1, ww);
	if(ww + WG[pos] <= w)
		ans = max(ans, backtracking(pos+1, ww+WG[pos]) + BG[pos]);

	for(int i = 0; i < group[pos].size(); ++i)
		if(ww + W[group[pos][i]] <= w)
			ans = max(ans, backtracking(pos+1, ww + W[group[pos][i]]) + B[group[pos][i]]);

	vis[pos][ww] = true;
	return dp[pos][ww] = ans;
}

void dfs(int x, int l){
	V[x] = true;
	group[l].push_back(x);
	for(int i = 1; i <= n; ++i)
		if(A[x][i] and not V[i])
			dfs(i, l);
}

int main(){

	scanf("%d %d %d", &n, &m, &w);
	for(int i = 1; i <= n; ++i) scanf("%d", W+i);
	for(int i = 1; i <= n; ++i) scanf("%d", B+i);

	for(int x, y, i = 0; i < m; ++i){
		scanf("%d %d", &x, &y);
		A[y][x] = A[x][y] = 1;
	}
	
	l = 0;
	for(int i = 1; i <= n; ++i)
		if(not V[i]){
			l++;
			dfs(i, l);
		}
	//group[1].push_back(1);
	//for(int i = 1; i < n; ++i)
	//	if(A[i][i+1]) group[l].push_back(i+1); 
	//	else group[++l].push_back(i+1);

	for(int i = 1; i <= l; ++i)
		for(int j = 0; j < group[i].size(); ++j){
			WG[i] += W[group[i][j]];
			BG[i] += B[group[i][j]];
		}

	printf("%d\n", backtracking(1, 0));

	return 0;
}
