/**
 *	@name POI 2006 invasion
 *	@author Miguel Mini
 *	@tags sorting, geometry
 *	@idea
 *		- Let L_{i, j} be the line that 
 *		passes through the points, vertices 
 *		of the polygon, i and j. and Left(L)
 *		the sum of values of nodes to left 
 *		of line L. Then the answer is:
 *		 
 *			max Left(L_{i, j}) + Left[L_{j, k}] 
 * 			+ Left(L_{k, i}) - 2 * total_sum_of_values
 *		
 *		with i -> j -> k -> i in clockwise order.
 *
 *		- We can calculate Left to all line:
 *	
 *			- fix the point i.
 *			- sort the values by smaller angle and 
 *			greater distance.
 *			- traverse in order calculating the sum 
 *			and each time a vertex is found, answer 
 *			the current sum.
 *
 *		note: to avoid precision error, instead of
 *		compare angles we can look sign of cross 
 *		product.
 */

#include <bits/stdc++.h>
using namespace std;
const int maxn = 610;
const int maxm = 10010;
struct Point {
	int x, y, w, ind;
} p[maxn], q[maxm + maxn];	
int n, m;
int sum[maxn][maxn];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		q[i] = p[i] = {x, y, 0, i};
	}
	scanf("%d", &m);
	int total_sum = 0;
	for (int i = 0; i < m; ++i) {
		int x, y, w;
		scanf("%d %d %d", &x, &y, &w);
		q[n+i] = {x, y, w, -1};
		total_sum += w;
	}
	for (int i = 0; i < n; ++i) {
		sort(q, q+n+m, [&](const Point& A, const Point& B)->bool {
			if (A.ind == i) return 1;
			if (B.ind == i) return 0; 
			int temp = (A.x - p[i].x) * (B.y - p[i].y) - (A.y - p[i].y) * (B.x - p[i].x);
			return temp > 0 or temp == 0 and A.ind < B.ind;
		});
		int cur_sum = 0;
		for (int j = 0; j < n+m; ++j) {
			if (~q[j].ind) {
				sum[i][q[j].ind] = cur_sum;
			}
			cur_sum += q[j].w;
		}
	}
	total_sum *= 2;
	int res = INT_MIN;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			for (int k = j + 1; k < n; ++k) {
				res = max(res, sum[i][j] + sum[j][k] + sum[k][i] - total_sum);
			}
		}
	}
	printf("%d\n", res);
	return 0;
}
