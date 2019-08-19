#include <bits/stdc++.h>
using namespace std;
const int maxN = 5e5 + 10;
int in[maxN], f[maxN];
int n;
bool vis[maxN];

int dfs(int x, int c) {
	vis[x] = 1;
	in[f[x]] -= 1;
	int res = c; 
	if (not vis[f[x]] and (in[f[x]] == 0 or c == 1)) {
		res += dfs(f[x], 1-c);
	}
	return res;
} 

int main() {
	scanf("%d", &n);	
	for (int i = 1; i <= n; ++i) {
		scanf("%d", f+i);
		in[f[i]] += 1;
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		if (in[i] == 0 and not vis[i]) {
			res += dfs(i, 1);
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (not vis[i]) 
			res += dfs(i, 0);
	}
	printf("%d\n", res);
	return 0;
}
