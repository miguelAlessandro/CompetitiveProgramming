/**
 * @name infoarena password2
 * @author Miguel Mini
 * @tag binary_search, greedy
 * @idea
 *	- First, we can query for 
 *	a string with n elements 
 *	for each letter to obtain
 *	the number of letters.
 *
 *	- Then we can merge these 
 *	strings, choosing the shortest 
 *	one s with the longest one r,
 *	this consumes a total of 
 *	len(s)\log len(r) queries and
 *	generate a string of len 
 *	len(s) + len(r).
 *	
 *	- Note that this joins the 
 *	longest with the smallest 
 *	to become the new longest.
 *
 *	the #query complexity is: O(nlogn)
**/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 30;
int cnt[maxn];
string s[maxn];
int N, S;

int query(string s) {
	cout << s << endl;
	int res; cin >> res;
	if (res == N) exit(0);
	return res;
}

using ii = pair<int, int>;
ii merge(int p, int q) {
	if (s[p].size() > s[q].size()) {
		swap(p, q);
	}
	int target = s[q].size(), res = 0;
	for (int i = 0; i <= s[p].size(); ++i) {
		if (target == 0) break;
		int lo = 0, hi = target;
		while (lo < hi) {
			int mid = lo + (hi-lo+1)/2;
			string cpy = s[p];
			if (query(cpy.insert(i, s[q], res, mid)) == s[p].size()+mid) lo = mid;
			else hi = mid-1;
		}
		s[p].insert(i, s[q], res, lo);
		res += lo;
		target -= lo;
		i += lo;
	}
	return {s[p].size(), p};
}
 
int main() {
	//freopen("password2.in", "r", stdin);
	//freopen("password2.out", "w", stdout);
	cin >> N >> S;
	for (char i = 0; i < S; ++i) {
		char ch = int('a') + i;
		cnt[i] = query(string(N, ch));
		s[i] = string(cnt[i], ch);
	}
	set<ii> pq;
	for (int i = 0; i < S; ++i)	{
		if (cnt[i] > 0) {
			pq.insert({cnt[i], i});
		}
	}
	while (pq.size() > 1) {	
		auto p = *pq.begin();
		auto q = *pq.rbegin();
		pq.erase(p); pq.erase(q);
		pq.insert(merge(p.second, q.second));
	}
	return 0;
}
