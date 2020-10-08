/**
 *  @author Miguel Mini
 *  @tag BIT, greedy, priority_queue, binary_search
 *  @idea
 *
 *    - Suppose that the value of b is decreasing.
 *    
 *    - We can optimize the values by "b" regardless 
 *    of the values "a" and then choose the best m "a"s.
 *
 *    - Now, there exists a k less than or equal to m 
 *    such that in the first s + k values, k are taken 
 *    "a" and s are taken "b" and the rest are taken 
 *    greedily
 *
 *    - We can keep in a fenwick tree those "a" that we 
 *    have not taken from highest to lowest and have the 
 *    sum of the best in logarithmic time.
 *
 *    - We can add the element s + i and calculate the 
 *    best distribution in s "b"s and i "a"s.
 *
 *    - We must realize that in each step add a new element
 *    with a change value new_element.a - new_element.b.
 *
 *    = If we maintain which are the best exchange values 
 *    for both the first s and the following i, we can realize
 *    that the number of interchangeable elements j_i fulfills 
 *    j_i <= i and j_i <= j_{i-1} + 1, therefore we can't add 
 *    or subtract from the best changes set more than n times 
 *    in total.
 *
 *    @complexity O(max(maxA, maxB) + nlog(max(maxA, maxB))) or O(nlogn)
**/

#include <bits/stdc++.h>
using namespace std;
 
const int maxN = 1<<19;
using ll = long long;
struct Pair {
		int a, b, id;
} arr[maxN], temp_arr[maxN];
int n, m, s;
int invS[maxN], pS[maxN];
ll ds[maxN];
pair<int, ll> ft[maxN];
 
void update(int x, int u, int v) {
	while (x < maxN) {
		ft[x].first += u;
		ft[x].second += v;
		x += x&-x;
	}
}
 
ll query(int need) {
	ll ans = 0, cur = 0;
	for (int pos = 18; pos >= 0; --pos) {
		if (need >= ft[cur + (1<<pos)].first) {
			ans += ft[cur + (1<<pos)].second;
			need -= ft[cur + (1<<pos)].first;
			cur += (1<<pos);
		}
	}
	return ans;
}
 
const int maxAB = maxN / 3;
int cnt[maxAB];
 
int main() {
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &arr[i].a, &arr[i].b);
		cnt[arr[i].b] += 1;
	}
	for (int i = 1; i <= maxAB; ++i) {
		cnt[i] += cnt[i-1];
	}
	ll add = 0;
	for (int i = 0, j = 0; i < n; ++i) {
		int cur_pos = cnt[arr[i].b]--;
		arr[i].id = n - cur_pos;
		if (arr[i].id < s) {
			ds[j++] = arr[i].a - arr[i].b;
			add += arr[i].b;
		}
	}
	sort(ds, ds+s, greater<>());
	for (int i = 0; i <= maxAB; ++i) cnt[i] = 0;
	for (int i = 0; i < n; ++i) {
		cnt[arr[i].a] += 1;
		temp_arr[i] = arr[i];
	}
	for (int i = 1; i <= maxAB; ++i) {
		cnt[i] += cnt[i-1];
	}
	for (int i = 0; i < n; ++i) {
		int cur_pos = cnt[temp_arr[i].a]--;
		arr[n - cur_pos] = temp_arr[i];
	}
	for (int i = 0, j = 0; i < n; ++i) {
		if (arr[i].id < s) continue;
		invS[arr[i].id] = ++j;
		pS[arr[i].id] = i;
		update(invS[arr[i].id], 1, arr[i].a);
	}
	priority_queue<int, vector<int>, greater<>> kSet;
	int posS = 0;
	ll ans = -1e18;
	for (int i = 0; i <= m; ++i) {
		ans = max(ans, add + query(m - i));
		if (i == m) break;
		auto new_element = arr[pS[s+i]];
		update(invS[s+i], -1, -new_element.a);
		add += new_element.a;
		int delta = new_element.b - new_element.a;
		while (!kSet.empty() && delta > kSet.top()) {
			if (posS >= s || ds[posS] + kSet.top() < 0) {
				add -= kSet.top();
				kSet.pop();
				posS -= 1;
				add -= ds[posS];
			} else break;
		}
		if (posS >= s) {
			if (!kSet.empty() && kSet.top() < delta) {
				add += delta - kSet.top();
				kSet.pop();
				kSet.push(delta);
			}
		} else {
			if (delta + ds[posS] > 0) {
				add += delta + ds[posS++];
				kSet.push(delta);
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
