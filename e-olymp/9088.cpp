/**
 * @author Miguel Mini
 * @tag meet in the middle, trie
 * @idea
 *      - split path to second diagonal, use brute force to
 *      generate xor paths and find maximum with a trie.
**/

#include <bits/stdc++.h>
using namespace std;

int trie[45][400000][2]; 
int elem[45];
void add(int x, int n) {
	int root = 0;
	for (int i = 30; i >= 0; --i) {
		bool ch = (n>>i)&1;
		if (not trie[x][root][ch]) trie[x][root][ch] = ++elem[x];
		root = trie[x][root][ch];
	}
}

int query(int x, int n) {
	int res = 0;
	int root = 0;
	for (int i = 30; i >= 0; --i) {
		bool ch = (n>>i)&1;
		if (not trie[x][root][ch]) ch ^= 1, res += 1<<i;
		root = trie[x][root][ch];
	}
	return res;
}


int main() {
	int n;
	cin >> n;
	int a[n][n];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < 1<<n-1; ++i) {
		int path = a[0][0];
		int x = 0, y = 0;
		for (int j = 0; j < n-1; ++j) {
			if (i & (1<<j)) {
				x += 1;
			} else {
				y += 1;
			}		
			path ^= a[x][y];
		}	
		add(n - 1 + x - y, path);	
	}
	int res = INT_MAX;
	for (int i = 0; i < 1<<n-1; ++i) {
		int path = a[n-1][n-1];
		int x = n-1, y = n-1;
		for (int j = 0; j < n-1; ++j) {
			if (i & (1<<j)) {
				x -= 1;
			} else {
				y -= 1;
			}	
			path ^= a[x][y];
		}
		res = min(res, query(n - 1 + x - y, path ^ a[x][y]));
	}
	cout << res << endl;
	return 0;
}
