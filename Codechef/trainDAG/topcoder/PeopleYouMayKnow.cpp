#include <bits/stdc++.h>
using namespace std;

class PeopleYouMayKnow {
public:
	int maximalScore(vector<string> friends, int person1, int person2) {
		int n = friends.size();
		int ans = 0;
		if (friends[person1][person2] == 'Y') return -1;
		for (int i = 0; i < n; ++i) {
			if (i == person1 or i == person2) continue;
			if (friends[person1][i] == 'Y' and friends[person2][i] == 'Y') {
				ans += 1;
				for (int j = 0; j < n; ++j) {
					friends[i][j] = 'N';
					friends[j][i] = 'N';
				}
			}
		}
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			sum += friends[person1][i] == 'Y';
		}
		if (sum > 20) swap(person1, person2);
		long long cover[n][3];
		memset(cover, 0, sizeof cover);
		for (int i = 0; i < n; ++i) cover[i][0] = 1ll<<i;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (friends[i][j] == 'Y') {
					cover[i][1] |= cover[j][0];
				}
			}
		}
		long long mask = cover[person2][1];
		for (int i = 0; i < n; ++i) {
			if (friends[person2][i] == 'Y') {
				mask |= cover[i][1];
			}
		}
		vector<int> g;
		for (int i = 0; i < n; ++i) {
			if (friends[person1][i] == 'Y') {
				g.emplace_back(i);
			}
		}
		int m = g.size();
		int add = m;
		for (int s = 0; s < 1<<m; ++s) {
			long long m1 = 0;
			int ladd = 0;
			for (int i = 0; i < m; ++i) {
				if (s & (1<<i)) {
					m1 |= (1ll<<g[i]); 
				} else {
					ladd += 1;
				}
			}
			for (int i = 0; i < n; ++i) {
				if (friends[person2][i] == 'Y') {
					if (m1 & cover[i][1]) ladd += 1;
				}	
			}
			add = min(add, ladd);
		}
		return ans + add;
	}
};
