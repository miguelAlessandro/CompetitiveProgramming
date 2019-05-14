#include <bits/stdc++.h>
using namespace std;
const int maxN = 1<<10;
int ft[maxN][maxN], a[maxN][maxN];
int t, n;

void upd(int x, int y, int v) {
	for (int tx = x; tx < n; tx |= tx+1) {
		for (int ty = y; ty < n; ty |= ty+1) {
			ft[tx][ty] += v;
		}
	}
}

int qry(int x, int y) {
	int ans = 0;
	for (int tx = x; tx>=0; tx = (tx&(tx+1)) - 1 ) {
		for (int ty = y; ty>=0; ty = (ty&(ty+1)) - 1) {
			ans += ft[tx][ty];
		}
	}
	return ans;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d\n", &n);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				ft[i][j] = a[i][j] = 0;
			}	
		}
		char s[5];
		int x, y, num;
		int x_1, x_2, y_1, y_2;
		while(scanf("%s", s) , s[0] != 'E') {
			if (s[2] == 'T') {
				scanf("%d %d %d\n", &x, &y, &num);
				upd(x, y, num - a[x][y]);
				a[x][y] = num;
			} else {
				scanf("%d %d %d %d\n", &x_1, &y_1, &x_2, &y_2);
				printf("%d\n", qry(x_2, y_2) - qry(x_2, y_1-1) - qry(x_1-1, y_2) + qry(x_1-1, y_1-1));
			}
		}
		puts("");
	}
	return 0;
}
