#include <iostream>
#include <cstdio>
using namespace std;

const int M = 12, N = 1002;
int n, m;
int a[M], b[M], c[M], d[M];
int dp[M][N];
bool vis[M][N];

int backtracking(int pos, int dough){
	if(pos == m+1) return 0; 
	if(vis[pos][dough]) return dp[pos][dough];

	int ans = 0;
	for(int i = 0; i*b[pos] <= a[pos] and i*c[pos] <= dough; ++i)
		ans = max(ans, i*d[pos] + backtracking(pos+1, dough - i*c[pos]));

	vis[pos][dough] = true;
	return dp[pos][dough] = ans;
}


int main(){

	scanf("%d %d %d %d", &n, &m, c, d);
	for(int i = 1; i <= m; ++i)
		scanf("%d %d %d %d", a+i, b+i, c+i, d+i);
		
	printf("%d\n", backtracking(0, n));	

	return 0;
}
