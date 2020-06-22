/**
 *	@name POI 2007 Gas Pipelines
 *	@author Miguel Mini
 *	@tags	sorting, greedy
 *	@idea:
 *		- affirmation: every perfect match 
 *		is a minimum cost perfect match.
 *	
 *		proof: in a minimum cost match
 *		(p_i, q_i) 1 <= i <= n, cost	
 *		is equal to sum x'_{q_i} - x_{p_i}
 *		+ y_{p_i} - y'_{q_i} equal to
 *		sum y_i - x_i + x'_{i} - y'_{i}. 
 *
 *		- traverse points left to right 
 *		and up to down. For all distribution 
 *		points at the time of finding it, 
 *		select greedily the closest extraction 
 *		point found.
 */

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
struct Point {
	int x, y;
	int ind;
	bool operator <(const Point& p) const {
		return x < p.x or x == p.x and y > p.y;
	}
};

int main() {
	int n;
	cin >> n;
	set<Point> P;
	long long min_total_lenght = 0;
	for (int i = 0; i < 2*n; ++i) {
		int x, y;
		cin >> x >> y;	
		P.insert({x, y, i});
		min_total_lenght += i < n ? y - x : x - y; 
	}
	cout << min_total_lenght << endl;
	set<pair<int, int>> Q;
	for (auto p : P) {
		if (p.ind < n) {	
			Q.insert({p.y, p.ind});
		} else {
			auto q = Q.lower_bound({p.y, -1});
			cout << q->second + 1 << " " << p.ind + 1 - n << endl;
			Q.erase(q);
		}
	}
	return 0;
}
