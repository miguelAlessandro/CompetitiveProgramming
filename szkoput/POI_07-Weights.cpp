/**
 * @name POI 2007 Weights
 * @author Miguel Mini
 * @tag binary_search, greedy
 * @idea
 *		- if we fix the answer k, 
 *		we can verify with the 
 *		following algorithm:
 *
 *			- we must verify to the first
 *			minor k.
 *
 *			- like these what elements are
 *			necesary, we will try to place 
 *			the largest of these in the one 
 *			with the most possible space.
 *			this reduce to k-1 elements.
 *
 *		- obviulsy if it is possible
 *		to k elements, then is possible
 *		to k-1, we can use binary search
**/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int w[maxn], c[maxn];
int n, m;

bool p(int m) {
	priority_queue<int> Q;
	for (int i = 0; i < n; ++i) Q.push(w[i]);
	for (int i = m-1; i >= 0; --i) {
		if (Q.empty() or Q.top() < c[i]) return 0;
		int q = Q.top(); Q.pop();
		q -= c[i];
		if (q != 0) Q.push(q);
	}
	return 1;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> w[i];
	for (int i = 0; i < m; ++i) cin >> c[i];
	sort(c, c+m);
	int lo = 0, hi = m;
	while (lo < hi) {
		int mid = lo + (hi-lo+1)/2;
		if (p(mid)) lo = mid;
		else hi = mid-1;
	}
	cout << lo << endl;
	return 0;
}
