/**
 * @name NOI 2017 RMQ 
 *	@author Miguel Mini
 *	@tag greedy, sweep_line
 *	@idea 
 *			- we have two types of constraints:	
 *				
 *				* every range query define a 
 *				range zone to a value.
 *
 *				* every range query define a
 *				minimum value.
 *	
 *			- the first restriction is solvable 
 *			with a greedy approach, considering 
 *			the intersection of the ranges for 
 *			each value in the input, take the 
 *			result range that ends first and set 
 *			its assigned value in the first position
 *			available.
 *
 *			- the second restriction is solvable
 *			with a second greedy approach, to every 
 *			value assign lowest disponible element.
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int L[maxn], R[maxn];
bool S[maxn];
int n, q;

void add(int l, int r, int u) {
	if (not S[u]) {
		L[u] = 0;
		R[u] = n-1;
	}
	L[u] = max(L[u], l);	
	R[u] = min(R[u], r);
	S[u] = 1;
}

void BAD() {
	for (int i = 0; i < n; ++i) {
		cout << -1 << " ";
	}
	cout << endl;
}

int main() {
	cin >> n >> q;
	vector<vector<int>> F(n+1);
	add(0, n-1, 0);
	F[0].push_back(0);
	for (int i = 1; i <= q; ++i) {
		int l, r, u;
		cin >> l >> r >> u;
		F[l].push_back(u);
		F[r+1].push_back(-(u+1));
		add(l, r, u);
	}
	multiset<int> G;
	vector<int> min_value(n);
	for (int i = 0; i < n; ++i) {
		if (L[i] > R[i]) {
			BAD();
			return 0;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int v : F[i]) {
			if (v < 0) {
				G.erase(G.lower_bound(-(v+1)));
			} else {
				G.insert(v);
			}
		}
		min_value[i] = *G.rbegin();
	}
	vector<vector<pair<int, int>>> adj(n);  
	for (int i = 0; i < n; ++i) {	
		if (S[i]) {
			adj[L[i]].push_back({R[i], i});
		}
	}
	set<pair<int, int>> Q;
	vector<int> res(n, -1);
	for (int i = 0; i < n; ++i) {
		for (auto e : adj[i]) {
			Q.insert({e.first, e.second});
		}
		if (not Q.empty()) {	
			auto q = Q.begin();
			if (R[(*q).second] < i or min_value[i] > (*q).second) {
				continue;			
			}
			res[i] = (*q).second;
			Q.erase(q);
		}
	}
	if (not Q.empty()) {
		BAD();
		return 0;
	}
	set<int> temp;
	for (int i = 0; i < n; ++i) {
		if (not S[i]) {
			temp.insert(i);
		}
	}
	for (int i = 0; i < n; ++i) {	
		if (res[i] == -1) {
			auto q = temp.lower_bound(min_value[i]);
			if (q == temp.end()) {
				break;
			}
			res[i] = *q;
			temp.erase(q);
		}
	}
	for (int i = 0; i < n; ++i) {
		if (res[i] < min_value[i]) {
			BAD();
			return 0;
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}
