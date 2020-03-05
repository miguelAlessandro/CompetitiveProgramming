/**
 *	@name COCI 2008 trezor
 *	@author Miguel Mini
 *	@tag brute_force, inclusion-exclusion principle
 *	@idea:
 *			
 *			- the visible points are the points
 *			with irreductible fraction.
 *
 *			- to a fixed row, we need the numbers
 *			of coprime numbers up to L with i x (a+b-i)
 *			this is the visible points to both.
 *
 *			- the secure points are the number of
 *			coprime numbers up to L with i and (a+b-i)
 *			- 2 * (intersection answer)
 *
 *			- to calculate the coprime points, we
 *			can use inclusion exlucion principle
 *			over the numbers multiples of prime
 * 		factors of our number.
**/

#include <bits/stdc++.h>
using namespace std;

int get(int x, int y, int r) {
	if (x == 0 or y == 0) return 1;
	set<int> f;
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			while (x % i == 0) x /= i;
			f.insert(i);
		}
	}
	if (x > 1) f.insert(x);
	for (int i = 2; i * i <= y; ++i) {	
		if (y % i == 0) {
			while (y % i == 0) y /= i;
			f.insert(i);
		}
	}
	if (y > 1) f.insert(y);
	int ans = 0;
	vector<int> F;
	for (int e : f) F.push_back(e);
	for (int s = 0; s < 1<<F.size(); ++s) {
		int m = 1;
		for (int i = 0; i < F.size(); ++i) {
			if (s & (1<<i)) {
				m *= F[i];
			}
		}	
		if (__builtin_popcount(s)&1) ans -= r / m;
		else ans += r / m;
	}
	return ans;
}

int main() {
	int a, b, l;
	cin >> a >> b >> l;
	long long ans1=0, ans2=0, ans3=0;
	for (int i = 0; i <= a+b; ++i) {
		int t = get(i, (a+b-i), l);
		int x = get(i, 1, l);
		int y = get(a+b-i, 1, l);
		ans1 += t;
		ans2 += x + y - 2 * t;
		ans3 += l + t - x - y;
	}
	cout << ans3 << endl;
	cout << ans2 << endl;
	cout << ans1 << endl;
	return 0;
}
