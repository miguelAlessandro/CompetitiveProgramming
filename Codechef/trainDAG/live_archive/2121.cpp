#include <bits/stdc++.h>
using namespace std;
 
int f(char c) {
	if (isdigit(c)) return c - '0';
	return c - 'A' + 10;
}
 
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
char ch[] = { '-', '|', '_', '|'};
const int maxN = 22;
char mat[maxN][maxN];
int n, m;
 
int main() {
	while (scanf("%d %d%*c", &n, &m), n+m) {
		memset(mat, ' ', sizeof mat);
		priority_queue<pair<pair<int, int>, int>> Q;
		for (int i = n-1; i >= 0; --i) {
			for (int j = m-1; j >= 0; --j) {
				char block;
				scanf("%c%*c", &block);
				int mask = f(block);
				mat[2*i	 ][2*j  ] = '+';
				mat[2*i+2][2*j  ] = '+';
				mat[2*i  ][2*j+2] = '+';
				mat[2*i+2][2*j+2] = '+';
				int cx = 2*i+1;	
				int cy = 2*j+1;
				for (int k = 0; k < 4; ++k) {
					int nx = cx + dx[k];
					int ny = cy + dy[k];
					Q.push({{nx, ny}, ((mask>>k)&1)?ch[k]:' '});
				}
			}
		}
		while (not Q.empty()) {
			auto q = Q.top(); Q.pop();
			mat[q.first.first][q.first.second] = q.second;
			if (not Q.empty() and Q.top().first == q.first) {
				if (q.second != Q.top().second) {
					if (q.first.first&1) {
						mat[q.first.first][q.first.second] = 'X';
					} else {
						mat[q.first.first][q.first.second] = 'x';
					}
				}
				Q.pop();
			}
		}
		for (int i = 0; i <= 2*n; ++i) {
			for (int j = 0; j <= 2*m; ++j) {
				if (j%2 == 1) {
					for (int k = 0; k < 2; ++k) {
						putchar(mat[i][j]);
					}
				}
				putchar(mat[i][j]);
			}
			puts("");
		}
		puts("");
	}
	return 0;
}
