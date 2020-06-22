/**
 *	@name CEOI 2019 Logs
 *	@author Miguel Mini
 *	@tag	sorting, invariance
 *	@idea
 *		- we can keep the indexes of the array
 *		 ordered with elements equal to the 
 *		height of 1s for each row based on 
 *		that row.
 *  	
 *		This can be achieved since the order 
 *		of the elements with 1 in the row i 
 *		does not change with respect to 
 *		themselves but, those with 0 go to 
 *		the beginning, we can update the order 
 *		of the new elements as previous order 
 *		+ number of zeros - number of zeros 
 *		before the index in the ordered array. 
 * 
 *	 	The last one can be calculated in O(m) 
 *		by accumulating -1 in each position of 
 *		the ordered array where there is now a 0.
 */

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1550;
int ord[maxn];
int red[maxn];
int sz[maxn];
char s[maxn];
int n, m;

int main() {
	//freopen("logs.in", "r", stdin);
	//freopen("logs.out", "w", stdout);
	scanf("%d %d", &n, &m);
	int ans = 0;
	for (int i = 0; i < m; ++i) ord[i] = i;
	for (int i = 0; i < n; ++i) {
		scanf("%s", s);
		for (int j = 0; j < m; ++j) red[j] = 0;
		int t = 0;
		for (int j = 0; j < m; ++j) {
			sz[j] = s[j] == '1' ? sz[j] + 1 : 0;
			if (s[j] == '0') {
				red[ord[j]] = -1;
				ord[j] = t++;
			}
		}
		for (int j = 1; j < m; ++j) {
			red[j] += red[j-1];
		}
		for (int j = 0; j < m; ++j) {
			if (s[j] == '1') {
				ord[j] = ord[j] + red[ord[j]] + t;
			}
		}
		for (int j = 0; j < m; ++j) {
			ans = max(ans, (m - ord[j]) * sz[j]);
		}
	}	
	printf("%d\n", ans);
	return 0;
}	
