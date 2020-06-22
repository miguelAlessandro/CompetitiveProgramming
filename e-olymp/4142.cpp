/**
 * @author Miguel Mini
 * @tag divide and conquer, bitmask, trie
 * @idea
 *      - simule a dense trie and use typical count.
**/

#include <bits/stdc++.h>
using namespace std;

long long get(long long x) {
	int n = 63 - __builtin_clzll(x);
	long long res = 0;
	for (int i = n; i >= 0; --i) {
		if ((x>>i)&1^1) {
			res += (1ll<<i);
		}
	}
	return res;
}

int main() {
	int q;
	long long x;
	cin >> q;
	while (q--) {
		cin >> x;
		cout << get(x) << endl;
	}
	return 0;
}
