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
 *  	reduce at most an inversion.
 * 
 *		and the dificult part: 
 *		if exist an inversion 
 *		always exist a swap that 
 *		reduce a inversion
 * 
 *		proof: suppose a sequence
 *		with 2n elements where two 
 *		consecutive elements are different
 *		and k first elements are differents
 *		and k is maximum, then the element
 *		k+1 is different to element k and necesary
 *		is equal to some element in the first
 *		k-1 elements. then we only need
 *		swap these until we put together this
 *		elements.
 * 
 *		complexity: O(n + m) m: maximum number
 *		of swaps.
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
