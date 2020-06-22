/**
 * @author Miguel Mini
 * @tag pattern finding
 * @idea
 *      - this is a mod4 pattern.
**/

#include <bits/stdc++.h>
using namespace std;

long long get(long long x) {
	if (x%4 == 0) return x;
	if (x%4 == 1) return 1;
	if (x%4 == 2) return x + 1;
	return 0;
}

int main() {
	long long l, r;
	cin >> l >> r;
	cout << (get(l) ^ get(r) ^ l) << endl;
	return 0;
}
