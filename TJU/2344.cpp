#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int a[N][N];
int n, t;
bool vis[N][N];
int dx[] = {1, 0, -1, 0},
	dy[] = {0, -1, 0, 1};

void dfs(int x, int y, const int l, const int r){

	vis[x][y] = true;
	for(int w, z, i = 0; i < 4; ++i){
		w = x+dx[i], z=y+dy[i];
		if(w >= 1 and w <= n and z >= 1 and z <= n and a[w][z] >= l and a[w][z] <= r and not vis[w][z])
			dfs(w, z, l, r);	
	}
}


int main(){
	
	int nc = 1;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				scanf("%d", &a[i][j]);

		int r = 200;
		for(int i = a[1][1]; i <= 200; ++i){
			int lo = 0, hi = a[1][1]; 	
			while(lo < hi){
				int mid = lo + (hi-lo+1)/2;
				memset(vis, false, sizeof vis);
				dfs(1, 1, mid, i);
				if(vis[n][n]) lo = mid;
				else hi = mid-1; 
			}
			memset(vis, false, sizeof vis);
			dfs(1, 1, lo, i);
			if(vis[n][n])
				r = min(r, i-lo);
		}
		
		printf("Scenario #%d:\n%d\n\n", nc++, r);
	}


	return 0;
}
