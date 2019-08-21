/**
 * @name Atcoder 011 AGC D
 * @author Miguel Mini
 * @tags greedy, simulation
 * @idea:
 *	- let f(S) the decimal number associate to set {A=0, B=1} note than
 *	- if S = 0X then operation(S) = 1X 
 * 	- if S = 1X then operation(S) = floor((~X)/2)
 *	- note than S is ABABAB... or BABABA... in at almost 2*n iterations
 *	- and before this is a cycle of lenght n.
 */

#include <bits/stdc++.h>
using namespace std;
int n, k;
string s;

int main() {
	cin >> n >> k >> s;	
	typedef pair<int, int> ii;
	deque<ii> d, temp;
	for (auto e : s) {
		if (d.empty() or d.back().second + 'A' != e) {
			d.push_back({1, e - 'A'});	
		} else {
			d.back().first += 1;
		}
	} 
	bool color = 0;
	int add = 0;
	while (k--) {
		if (d[0].second == color) {				
			if (d[0].first == 1) d.pop_front();
			else d[0].first -= 1;	
			if (d.empty() or d.front().second != (1^color)) d.push_front({1, 1 ^ color});
			else d.front().first += 1;;
		} else {
			add += 1;
			color ^= 1;
			if (d[0].first == 1) d.pop_front();
			else d[0].first -= 1;
			if (d.empty() or d.back().second != color) d.push_back({1, color});
			else d.back().first += 1;
		}
		if (~k and add == n) {
			k %= n;
		}
	}
	for (auto& e : d) e.second ^= color;
	for (auto& e : d) {
		while (e.first--) {
			putchar('A' + e.second);
		}
	}
	puts("");
	return 0;
}
