#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

const int N = 240;

long long d[N][N];
int n, m;


int main(){

	scanf("%d %d", &n, &m);
	for(int i = 1; i < n; ++i)
		for(int j = i+1; j <= n; ++j)
			d[j][i] = d[i][j] = INT_MAX;
	
	for(int i = 1; i <= n; ++i) d[i][i] = 0;

	for(int x, y, w, i = 0; i < m; ++i)
		scanf("%d %d %d", &x, &y, &w), 
		d[x][y] = d[y][x] = w;
	
	for(int k = 1; k <= n; ++k)
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	long long Bmax = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
				Bmax = max(Bmax, d[i][j]);
	
	printf("%lld\n", Bmax);

	return 0;
}
