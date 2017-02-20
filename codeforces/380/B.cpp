#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1005;
int mat[N][N];
int u[N][N], l[N][N];
int r[N], c[N];
int n, m;

int main(){

	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			scanf("%d", &mat[i][j]);

	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j){
				r[i]+= mat[i][j];
				c[j]+= mat[i][j];
				u[i][j] = u[i-1][j] + mat[i][j];
				l[i][j] = l[i][j-1] + mat[i][j];		
		}
		
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			if(not mat[i][j]){
				if(u[i][j]) ans++;
				if(l[i][j]) ans++;
				if(r[i] - l[i][j]) ans++;
				if(c[j] - u[i][j]) ans++;
			}

	printf("%d\n", ans);

	return 0;
}
