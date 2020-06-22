/**
 * @author Miguel Mini
 * @tag divide and conquer, merge sort
 * @idea
 *      - run a merge sort algorithm and count in combine part.
**/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 10;
int temp[maxn];
int a[maxn];
int t, n;

long long merge(int l, int r, int mid) {
	long long res = 0;
	int i = l, j = mid+1, pos = 0;
	while (i <= mid and j <= r) {
		if (a[i] < a[j]) temp[pos++] = a[i++];
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

long long merge_sort(int l, int r) {
	if (l == r) return 0;
	int mid = (l + r) / 2;
	long long L = merge_sort(l, mid);
	long long R = merge_sort(mid+1, r);
	return L + R + merge(l, r, mid);
}

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		cout << "Optimal train swapping takes " << merge_sort(1, n) << " swaps." << endl; 
	}
	return 0;
}
