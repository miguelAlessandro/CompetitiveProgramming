/**
 *	Restaurant
 *	==========
 * 
 *	@autor Miguel Min\'i
 *      @tag geometry, sweep line, function
 *	@idea
 *              - Note than the surface inducted by distance is a rhombus (for both points)
 *		- also, you need the union of two rhombus for each point C, and intersect all those:
 *              #############\ /#########################
 *              ##############C##########################
 *              #############/##\########################
 *               A #########/####\##################### B
 *              ############\###/########################
 *              #############\#/#########################
 *              #############/ \#########################
 *              ############/   \########################   
 *
 *
 *		- they rhombus are symmetric to horizontal line A --- B
 *		- (consider upper to line A---B) rhombus has divided in two parts (left and right):
 * 
 *			#\     /###
 *			##\   /####
 *			###\ /#####
 *                      ####C######      
 *
 *	        - (consider right part) such than a right appear, the points:
 *
 *                
 *                .     
 *                .           .               .
 *                .           .               .
 *          (c.x, c.y+3)      .               .         ...
 *          (c.x, c.y+2) (c.x+1, c.y+2) (c.x+2, x.y+2)
 *          (c.x, c.y+1) (c.x+1, c.y+1)
 *          (c.x, c.y  )
 *
 *    
 *     - let f be a function, with f(c) = c.x - c.y, note than if  
 *     two points appear, let E and F with E.x == F.x, so if f(E) <= f(F),     
 *    (E.x + k, E.y + k) <= (F.x + k, F.y + k), futhermore if E.x > F.x 
 *    and F.x + k1 = E.x, then (E.x + k2, E.y + k2) <= (F.x + k1 + k2, F.y + k1 + k2) 
 *
 *    - so we only need maintain the point with minimum f (symmetrically to left part).
 *
 *    note:
 *    in the input, ever A.x == 0 and B.x == m-1 or visceversa
 */

#include <bits/stdc++.h>
using namespace std;
const int maxn = 6e4 + 10;
int x[maxn], y[maxn];
int roll[maxn], ans[maxn];
int n, m, t;
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &m, &n);
		m -= 1;
		for (int i = 0; i < n; ++i) {
			scanf("%d %d", x+i, y+i);
		}
		int r = y[0];
		if (x[0] > x[1]) {
			swap(x[0], x[1]);
		}
    
    //transform line A---B to axis
		for (int i = n-1; i >= 0; --i) { 
			y[i] -= y[0];
			if (y[i] < 0) y[i] = -y[i];
		}
    
    
    //maintain function f (right part)
		memset(roll, 1, sizeof roll);
		for (int i = 0; i < n; ++i) {
			roll[x[i]] = min(roll[x[i]], y[i] - x[i]);
		}
		int left = 1e9;
		for (int i = 0; i <= m; ++i) {
			left = min(left, roll[i]);
			ans[i] = left+i;
		}
    
    //maintain function f (left part)
		memset(roll, 1, sizeof roll);
		for (int i = 0; i < n; ++i) {
			roll[x[i]] = min(roll[x[i]], y[i]-m+x[i]);
		}
		int right = 1e9;
		for (int i = 0; i <= m; ++i) {
			right = min(right, roll[m-i]);
			ans[m-i] = min(ans[m-i], right+i);
		}
    
    //calculating contribution (dont forget limits of points 0 <= x < m and 0 <= y < m)
		for (int i = 0; i <= m; ++i) {
			if (ans[i] == 0) continue;
			ans[i] -= 1;
			ans[i] = min(ans[i], r) + min(ans[i], m-r) + 1;
		}
    
		long long res = 0;
		for (int i = x[0]; i <= x[1]; ++i) {
			res += ans[i];
		}
		printf("%lld\n", res);
	}
	return 0;
}
