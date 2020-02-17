/**
 *	@name POI 2014 couriers
 *	@author Miguel Mini
 *	@tag binary search, probabilistic
 *	@idea
 *		- we can solve this problem 
 *		with persistent segment tree
 *		or wavelet tree, but a simple
 *		solution is possible with binary
 *		search.
 *
 *		- if element exist, the probability 
 *		is >= 1/2 of finding it. if I use 
 *		k iterations the probility of 
 *		success is >= 1 - (1 - 1/2)^k
 *		
 *		- I select k = 25, and the check
 * 	can be done with a binary search	
 *		over the positions that this item		
 *		appears.
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
vector<int> arr[maxn];
int a[maxn];
int n, m;

int query(int l, int r, int x) {
		return upper_bound(arr[x].begin(), arr[x].end(), r) -
				lower_bound(arr[x].begin(), arr[x].end(), l);
}

int main() {	
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a+i);
		arr[a[i]].push_back(i);
	}
	for (int i = 1; i <= m; ++i) {
		int l, r;
		scanf("%d %d", &l, &r);
		vector<int> temp;
		bool fun = 0;
		for (int i = 0; i <= 25; ++i) {
			int x = uniform_int_distribution<int>(l, r)(rng);
			if (query(l, r, a[x]) > (r - l + 1) / 2) {
				printf("%d\n", a[x]);
				fun = 1;
				break;
			}
		}
		if (not fun) puts("0"); 
	}
	return 0;
}
