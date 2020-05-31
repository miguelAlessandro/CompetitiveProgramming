/**
 * @author Miguel Mini
 * @tag divide and conquer, merge sort, binary search
 * @idea
 *      - run a merge sort algorithm and count with a binary search in combine part.
**/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e4 + 10;
int temp[maxn];
int a[maxn];
int t, n;

long long merge(int l, int r, int mid) {
	long long res = 0;
	int i = l, j = mid+1, pos = 0;
	while (i <= mid and j <= r) {
		if (a[i] < a[j]) temp[pos++] = a[i++];
		else {
			int lo = i, hi = mid;
			while (lo < hi) {
				int mi = (lo + hi) / 2;
				if (a[mi] <= a[j] + t) lo = mi+1;
				else hi = mi;
			}
			if (a[lo] > a[j] + t) {
				res += mid - lo + 1;
			}
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

long long merge_sort(int l, int r) {
	if (l == r) return 0;
	int mid = (l + r) / 2;
	long long L = merge_sort(l, mid);
	long long R = merge_sort(mid+1, r);
	return L + R + merge(l, r, mid);
}

int main() {
	while (cin >> n >> t) {
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		cout << merge_sort(1, n) << endl; 
	}
	return 0;
}
