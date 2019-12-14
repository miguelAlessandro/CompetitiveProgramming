/**
 *	@name infoarena LCDR
 *	@author Miguel Mini
 *	@tag dp, off_line
 *	@idea
 *		- we can fix l2 and build
 *		matrix dp from file 1 to i.
 *		That dp is of the form:
 *			
 *			dp_i(j : from file j to i, c : number of columns) :
 *				what is the maximum number r of rows 
 *				such that there exist a rectangle r x c.
 *				
 *		if we add a row, the new rectangles to consider  
 *		finish in the new row. we can find these in O(m*m)
 *		and propagate to every last row in O(n*m).
 *
 *		we can response true every query with l2 = i if
 *		dp_i[l1][c] >= l and false in other case.
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 510;
struct Query {
	int a, b, l, id;
};
vector<Query> g[maxn];
int temp[maxn];
int dp_max[maxn][maxn];
const int maxm = 5e5 + 10;
bool ans[maxm];
int mx[maxn];
int n, m, q;
char mat[maxn][maxn];

int main() {
	freopen("lcdr.in", "r", stdin);
	freopen("lcdr.out", "w", stdout);
	scanf("%d %d %d\n", &n, &m, &q);
	for (int i = 0; i < n; ++i) {
		scanf("%s\n", mat[i]);
	}
	for (int i = 0; i < q; ++i) {
		int l, c, l1, l2;
		scanf("%d %d %d %d", &l, &c, &l1, &l2);
		--l1; --l2;
		if (l1 > l2) swap(l1, l2);
		g[l2].push_back({l, c, l1, i});
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			mx[j] = mat[i][j] == '1' ? mx[j] + 1 : 0;
		}
		memset(temp, 0, sizeof temp);
		for (int j = 0; j < m; ++j) {
			int t = 1000;
			for (int k = j; k < m; ++k) {
				t = min(t, mx[k]);
				if (t == 0) break;
				if (temp[k-j+1] < t) {
					temp[k-j+1] = t;
				}
			}
		}
		for (int k = 0; k <= m; ++k) dp_max[i][k] = temp[k] > 0;
		for (int j = i-1; j >= 0; --j) {
			for (int k = 0; k <= m; ++k) {
				dp_max[j][k] = max(dp_max[j][k], 
						j + temp[k] - 1 >= i ? i - j + 1 : temp[k]);
				dp_max[j][k] = max(dp_max[j][k], dp_max[j+1][k]);
			}
		}
		for (auto e : g[i]) {
			ans[e.id] = dp_max[e.l][e.b] >= e.a;
		}
	}
	for (int i = 0; i < q; ++i) {
		printf("%d\n", ans[i]);
	}
	return 0;
}
