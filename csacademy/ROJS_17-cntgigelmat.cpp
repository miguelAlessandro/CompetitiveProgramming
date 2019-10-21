/**
 *	@name csacademy Count Gigle Matrices
 *	@author Miguel Mini
 *	@tag	dp, sweep-line, BIT
 *	@idea
 *		- keep the sums for the 4 
 *		directions plus the diagonal, 
 *		given a position, add a range 
 *		of ones in the same diagonal 
 *		as long as it can be extended 
 *		down and to the right, and 
 *		diagonally, after that add to 
 *		a list that must be it removed, 
 *		
 *	 	- given a position, consult the
 *		maximum that can be extended to
 *		the left, up and diagonal and 
 * 	add how many ranges are active 
 *		in that range.
 */

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010;
int n, m;
int mat[maxn][maxn];
int L[maxn][maxn];
int R[maxn][maxn];
int D[maxn][maxn];
int U[maxn][maxn];
int acc[maxn][maxn];
int ft[2 * maxn][maxn];
vector<int> adj[maxn][maxn];
const int O = maxn;

void update(int idx, int pos, int v) {
	idx += O;
	while (pos < maxn) {
		ft[idx][pos] += v;
		pos += pos&-pos;
	}
}

int query(int idx, int pos) {
	idx += O;
	int ans = 0;
	while (pos > 0) {
		ans += ft[idx][pos];
		pos -= pos&-pos;
	}
	return ans;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%1d", mat[i]+j);
		}
	}
	for (int i = 0; i < n; ++i) {	
	for (int j = 0; j < m; ++j) {
			if (mat[i][j] == 0) continue;
			L[i][j] = (j == 0 ? 0 : L[i][j-1]) + 1;
			U[i][j] = (i == 0 ? 0 : U[i-1][j]) + 1;
		}
	}
	for (int i = n-1; i >= 0; --i) {	
		for (int j = m-1; j >= 0; --j) {
			if (mat[i][j] == 0) continue;
			R[i][j] = (j+1 == m ? 0 : R[i][j+1]) + 1;
			D[i][j] = (i+1 == n ? 0 : D[i+1][j]) + 1;	
		}
	}
	unsigned int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int v : adj[i][j]) update(i - j, v + 1, -1);
			adj[i][j].clear();
			if (mat[i][j]) {
			   acc[i][j] = i == 0 ? 1 : acc[i-1][j-1] + 1;
				update(i - j, i + 1, 1);
				int l = min(R[i][j], D[i][j]);
				if (i + l < n and j + l < m) {
					adj[i + l][j + l].emplace_back(i);
				}
				int r = min(min(L[i][j], U[i][j]), acc[i][j]);
				int temp = query(i - j, i + 1);
				if (i >= r and j >= r) {
					temp -= query(i - j, i - r + 1);
				}
				cnt += temp;
			}
		}
	}
	printf("%u\n", cnt);
	return 0;
}
