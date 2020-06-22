/**
 *	@name 2019 | Baltic Olympiad in Informatics | Olympiads 
 *	@author Miguel Mini
 *	@tag fracturing-search
 *	@idea
 *
 *		- when using fracturing search,
 *		our problem becomes to find the
 *		best team having found the t < k
 *		first members.
 *
 *		- so we force the first t members
 *		to have better scores in at least
 *		the first t competitions.
 *
 *		- This property is always possible 
 *		because as t events are, I can always
 *		choose the best in each event and put
 *		them together.
**/

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
int n, k, c;
int p[510][6];

struct Partition {
	vector<int> choice;
	vector<int> best;
	int cost;
	Partition(vector<int> A): choice(A) {
		vector<int> temp(k, 0);
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			if (choice[i] == 1) {
				best.push_back(i);
				for (int j = 0; j < k; ++j) {
					temp[j] = max(temp[j], p[i][j]);
				}
				cnt += 1;
			}
		}
		vector<int> tt = choice;
		for (int i = cnt; i < k; ++i) {
			int mx = -1, id;
			for (int j = 0; j < n; ++j) {
				if (tt[j] == 0 and mx < p[j][i]) {
					mx = p[j][i];
					id = j;
				}
			}
			if (mx == -1) {
				cost = INT_MIN;
				return;
			}
			best.push_back(id);
			tt[id] = 1;
			for (int j = 0; j < k; ++j) {
				temp[j] = max(temp[j], p[id][j]);
			}
		}
		cost = accumulate(all(temp), 0);
	}

	bool operator <(Partition r) const{ 
		return cost < r.cost;
	}
};

int main() {
	cin >> n >> k >> c;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			cin >> p[i][j];
		}
	}
	priority_queue<Partition> Q;
	Q.push(Partition(vector<int>(n, 0)));
	while (c--) {
		auto q = Q.top(); Q.pop();
		if (c == 0) {
			cout << q.cost << endl;
			break;
		}
		for (int i = 0; i < k; ++i) {
			if (q.choice[q.best[i]] == 0) {
				vector<int> choice = q.choice;
				choice[q.best[i]] = -1;
				for (int j = 0; j < i; ++j) {
					choice[q.best[j]] = 1;
				}
				Q.push(Partition(choice));
			}
		}
	}
	return 0;
}
