/**
 * @author Miguel Mini
 * @tag divide and conquer, merge sort
 * @idea
 *      - run merge sort two times
 *      - run a merge sort algorithm and count in combine part.
**/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10;
typedef pair<int, int> pii;
pii temp[maxn];
pii a[maxn];
int t, n;

bool cmp(pii x, pii y, bool t) {
	if (t) return x <= y;
	swap(x.first, x.second);
	swap(y.first, y.second);
	return x <= y; 
}

long long merge(int l, int r, int mid, bool t) {
	long long res = 0;
	int i = l, j = mid+1, pos = 0;
	while (i <= mid and j <= r) {
		if (cmp(a[i], a[j], t)) temp[pos++] = a[i++];
		else {
			res += mid - i + 1;
			temp[pos++] = a[j++];
		}
	}		
	while (i <= mid) temp[pos++] = a[i++];
	while (j <= r) temp[pos++] = a[j++];
	for (int i = l; i <= r; ++i) {
		a[i] = temp[i - l];
	}
	return res;
}

long long merge_sort(int l, int r, bool t) {
	if (l == r) return 0;
	int mid = (l + r) / 2;
	long long L = merge_sort(l, mid, t);
	long long R = merge_sort(mid+1, r, t);
	return L + R + merge(l, r, mid, t);
}

int main() {
	while (cin >> n) {
		for (int i = 1; i <= n; ++i) {
			cin >> a[i].first >> a[i].second;
		}
		long long ans = 0; 
		merge_sort(1, n, 1);
		ans = merge_sort(1, n, 0);
		ans = min(ans, merge_sort(1, n, 1));
		cout << ans << endl;
	}
	return 0;
}
