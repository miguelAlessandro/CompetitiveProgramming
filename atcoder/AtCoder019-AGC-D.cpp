/**
 * @name AtCoder 019 AGC D
 * @author Miguel Mini
 * @tags brute-force, sorting
 * @idea
 *	- if B = 0..0 then A = 0..0 necesary
 *	- else:
 *		- fix final position, then
 *		- if A[i] != B[i] is necessary 
 *		- take closer 1 to left or right.
 *		- fix r to right shift, let l = max(distance to left 1) of
 *		- indices with distance to right 1, 
 *		- greater to r, then the answer  
 *		- with this r is 2*(max(r, d) + max(l, -d)) - abs(d).		
 */

#include <bits/stdc++.h>
using namespace std;
const int maxN = 2010;
string A, B;
int L[maxN], R[maxN];
int n;

int main() {
	cin >> A >> B; 
	n = B.size();
	bool fun = 0;
	for (auto c : B) fun |= c-'0';
	if (not fun) return cout << (A == B)-1 << endl, 0;
	int fst = n, lst = -1; 
	for (int i = 0; i < n; ++i) {
		if (B[i] == '1') {
			fst = min(fst, i);
			lst = max(lst, i);
		}
	}
	for (int i = 0; i < n; ++i) L[i] = R[i] = n;
	int d = lst-n;
	for (int i = 0; i < n; ++i) {
		if (B[i] == '1') d = i;
		L[i] = min(i==0?n:L[i-1]+1, i - d);
	}
	d = n+fst;
	for (int i = n-1; i >= 0; --i) {
		if (B[i] == '1') d = i;
		R[i] = min(i==n-1?n:R[i+1]+1, d-i);
	}
	int ans = 3*n;
	for (int r = -n+1; r < n; ++r) {
		int cnt = 0, lans = abs(r);
		vector<pair<int, int>> p;
		for (int i = 0; i < n; ++i) {
			if (A[i] != B[(i+r+n)%n]) {
				cnt += 1;
				p.push_back({R[i], L[i]});
			}
		}
		if (not p.empty()) lans = 1e9;
		typedef pair<int, int> ii;
		sort(begin(p), end(p), [](ii a, ii b) {
			return a.first > b.first or a.first == b.first
			and a.second < b.second;
		});
		//cout << "**************" << endl;
		//cout << r << " " << cnt << endl;
		//for (auto e : p) cout << e.first << " " << e.second << endl;
		int mn = -1e9;
		for (auto& e : p) {
			e.second = max(e.second, mn);
			mn = e.second;
		}
		reverse(begin(p), end(p));
		p.push_back({0, 0});
		int lastx = 0;
		for (auto& e: p) {
			if (r >= 0)
				lans = min(lans, 2*(max(r, lastx) + e.second) - r);
			else
				lans = min(lans, 2*(lastx + max(e.second, -r)) + r);			
			lastx = e.first;
		}		 
		ans = min(ans, lans + cnt);
	}
	cout << ans << endl;
	return 0;
}
