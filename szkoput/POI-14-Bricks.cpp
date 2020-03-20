/**
 * @name POI 2014 Bricks
 *	@author Miguel Mini
 *	@tag constructive, greedy
 *	@idea
 *		- first let's forget 
 *		the extreme bricks.
 *		
 *		- we can build with a
 *		next process, take the
 *		most repeated element.
 *
 *		- put these in a row
 *	
 *		- take the second to the last
 *		most repeated element, in this
 *		order. concat all of these
 *		and put in the first row with
 *		next strategy:
 *
 *			- imagine the starting row 
 *			is in a circle, take arbitrary 
 *			position and put first element,
 *			now put to the right of that 
 *			skipping one, the next one.
 *
 *		- this strategy always works so far.
 *
 *		- in the final step, we need to put
 *		p and q, we only need cut the circle 
 *		in a position with two equal elements
 *		or if it doesnt exist in any position.
 *
 *		note: you can obtain n = 1
**/


#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int nxt[maxn];
int key[maxn];
int a[maxn];
int t[maxn];
vector<int> mx[maxn];

int elem = 0;
void make(int node, int e) {
	nxt[node] = -1;
	key[node] = e;
}

int ins(int node, int v) {
	make(++elem, v);
	nxt[elem] = nxt[node];
	nxt[node] = elem;
	return elem;
}

int final_key(int node) {
	if (nxt[node] == -1) return key[node];
	return final_key(nxt[node]);
}

int k, p, q;

int main() {
	scanf("%d%d%d", &k, &p, &q);
	int sum = 0;
	for (int i = 1; i <= k; ++i) {
		scanf("%d", t+i);
		sum += t[i];
		if (i == p) t[i] -= 1;
		if (i == q) t[i] -= 1; 
	}
	if (sum == 1) { 
		if (p == q) printf("%d\n", p);
		else puts("0");
		return 0;
	}
	for (int i = 1; i <= k; ++i) {
		if (t[i] < 0) return puts("0"), 0;
		mx[t[i]].emplace_back(i);	
	}
	int cur = 0;
	make(cur, -1);
	for (int i = 1000000; i >= 1; --i) {	
		for (int e : mx[i]) {
			if (nxt[0] == -1) {
				for (int j = 1; j <= i; ++j) ins(cur, e);
				cur = nxt[cur];
			} else {
				for (int j = 1; j <= i; ++j) {
					cur = nxt[ins(cur, e)];
					if (cur == -1) cur = 0;
				}
			}
		}
	}
	if (nxt[0] != -1 and (key[nxt[0]] == p or key[nxt[0]] == q)) {
		if (final_key(0) == key[nxt[0]]) {	 
			int last = nxt[0];
			int fst = key[last];
			for (int i = nxt[nxt[0]]; i != -1; i = nxt[i]) {
				if (nxt[i] == -1) {
					swap(key[last], key[i]);
					break;
				}
				if (key[last] == fst and i == nxt[nxt[0]] and key[nxt[i]] != fst) {
					swap(key[nxt[0]], key[i]);
					break;
				}
				if (key[last] != fst and key[nxt[i]] != fst) {
					swap(key[nxt[0]], key[i]);
					break;
				}
				last = i;
			}
		}
	}
	int n = 0;
	for (int i = nxt[0]; i != -1; i = nxt[i]) {
		a[n++] = key[i];
		if (n >= 2 and a[n-1] == a[n-2]) return puts("0"), 0;
	}	
	if (n > 0 and (a[0] == p or a[n-1] == q)) reverse(a, a+n);
	if (n > 0 and (a[0] == p or a[n-1] == q)) return puts("0"), 0;
	if (n == 0 and p == q) return puts("0"), 0;
	printf("%d ", p);
	for (int i = 0; i < n; ++i) printf("%d ", a[i]);
	printf("%d\n", q);
	return 0;
}
