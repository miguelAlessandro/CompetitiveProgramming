/**
 *	@name POI 2007 Tetris
 *	@author Miguel Mini
 *	@tag invariant, math
 *	@idea:
 *		- we call the secuence
 *		of two color a and b:
 *	
 *		....a..b...a..b....
 * 
 *		an inversion, we noted 
 *		that if two color don't 
 *		form an inversion then, 
 *		we will never make a 
 *		swap between these.
 * 
 *		moreover, a swap can 
 *  		reduce at most an inversion.
 * 
 *		and the dificult part: 
 *		if exist an inversion 
 *		always exist a swap that 
 *		reduce a inversion
 * 
 *		Proof: Consider a sequence 
 *		with 2n elements in which 
 *		any two consecutive elements 
 *		are different, the first k 
 *		elements are different and k 
 *		is maximum possible. Then, 
 *		the elements (k+1) and k 
 *		are different and the element 
 *		(k+1) is necessarily equal 
 *		to some element in the first 
 *		(k-1) elements. Then, we only 
 *		need to swap these elements 
 *		until we put them together.
 * 
 *		complexity: O(n + m) m: maximum 
 *		number of swaps.
 */

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
bool vis[maxn];
int d[maxn], res[maxn * 5];
int p, t, n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < 2*n; ++i) {
		int x;
		scanf("%d", &x);
		if (vis[x]) {
			int m = 0;
			while (d[p-1-m] != x) res[t++] = p-m++;
			for (int i = 0; i < m; ++i) d[p-1-m+i] = d[p-m+i];
			p -= 1;
		} else {
			vis[d[p++] = x] = 1;
		}
	}
	printf("%d\n", t);
	for (int i = 0; i < t; ++i) printf("%d\n", res[i]);
	return 0;
}
