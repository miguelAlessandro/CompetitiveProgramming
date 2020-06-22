/**
 *	@name Infoarena Interact
 *	@author Miguel Mini
 *	@tag interactive, constructive
 *	@idea
 *			- suppose a correct order
 *			a1, a2, ..., an then if we
 *			put the character k, t times, 
 *			then by all position i,	if there
 *			exist c character k between
 *			i and i+1, we can look this
 *			in c + 1 steps.
 *
 *			- then we can put every character
 *			in <= (max(n) + 1) * alphabet + 
 *			total length <= 101 * 26 + 100
 *
 *			- the algorithm use at most 3000 
 *			queries.
 */

#include <bits/stdc++.h>
using namespace std;
const int maxn = 300;
int cnt[maxn];

bool query(string s) {
	cout << "? " << s << endl;
	int res; cin >> res;
	return res;
}

void solve(string s) {
	cout << "! " << s << endl;
}

int main() {
	for (char i = 'a'; i <= 'z'; ++i) {
		string s = "";
		for (int k = 1; k <= 100; ++k) {
			s += i;
			if (query(s)) cnt[i] += 1;
			else break;
		}
	}
	string ans = string(cnt['a'], 'a');
	for (char i = 'b'; i <= 'z'; ++i) {
		for (int j = 0; j <= ans.size(); ++j) {
			int c = 0;			
			while (cnt[i] > 0) {
				string u = ans;
				if (query(u.insert(j, c + 1, i))) c += 1;
				else break;
				cnt[i] -= 1;
			}
			if (c > 0) {
				ans.insert(j, c, i);
			}
			j += c;
		}
	}
	solve(ans);
	return 0;
}
