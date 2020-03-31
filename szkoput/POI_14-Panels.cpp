/**
 *	@name POI 2014 Panels
 *	@author Miguel Mini
 *	@tag math, sweep_line
 *	@idea:
 *		
 *		- we need to find max(gcd(x, y))
 *		with l1 <= x <= r1 and l2 <= y <= r2.
 *
 *		- if we fix d = gcd(x, y), we must
 *		verify that ceil(l1/d)*d <= r1
 *		and ceil(l2/d)*d <= r2.
 *
 *		- then, ceil(li/d) <= sqrt(ri) or	
 *		d <= sqrt(ri).
 *
 *			- to d <= sqrt(ri) just is a simple
 *			check.
 *
 *			- if ceil(li/d) == m, then: 
 *					m-1 < li/d <= m
 *			=> d <= floor(li/(m-1))-1
 *			and ceil(li/m) <= d.	
 *
 *			- in the final step we must
 *			find the maximum point in both
 *			set of segments. we could use
 *			a simple sweepline approach,
 *			go from most right segment and 
 *			update its left part, we can
 *			verify that solution exist if
 *			current segment interset with
 *			the most left segment checked.
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {	
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		using ii = pair<int, int>;
		vector<ii> s;
		int ans = 1, n = sqrt(max(r1, r2)) + 1;
		s.push_back({l1, r1});
		s.push_back({l2, r2});	
		for (int d = 2; d <= n; ++d) {	
			if ((l1+d-1)/d*d <= r1 and (l2+d-1)/d*d <= r2) {
				ans = d;
			}
			s.push_back({(l1+d-1)/d, min(r1/d, l1/(d-1)-1)});
			s.push_back({(l2+d-1)/d, min(r2/d, l2/(d-1)-1)});
		}
		sort(s.begin(), s.end(), [](ii p, ii q) {
			return p.second > q.second or 
				p.second == q.second and 
				p.first > q.first;
		});
		int mx = 2e9;
		for (auto e : s) {
			if (e.second < e.first) continue;
			if (mx <= e.second) {
					ans = max(ans, e.second);
					break;
			}
			mx = min(mx, e.first);
		}
		cout << ans << endl;
	}
	return 0;
}
