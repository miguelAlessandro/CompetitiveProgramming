/**
 *	@name fibo4 infoarena
 *	@author Miguel Mini
 *	@tag dp, fibonacci
 *	@idea
 *			- hardcode fibonacci cycle-length
 *
 *			- to solve range update in l and l+1
 *			fib(k), fib(k+1) too in r and r+1
 *			-fib(r-l+k+1), -fib(r-l+k). to solve
 *			go over positions i from left to right
 *			and update i+1 and i+2 with value in i.
 */

#include <bits/stdc++.h>
#define FOR(i, j, k) for (int i = j; i < k; ++i)
using namespace std;
const int mod = 666013;
const int maxn = 1.4e6;
int arr[maxn], fib[maxn];
int n, m;

int add(int a, int b) {
	return a+b>=mod?a+b-mod:a+b;;
}

int mul(long long a, long long b) {
	return a*b%mod;
}

int main() {
	freopen("fibo4.in", "r", stdin);
	freopen("fibo4.out", "w", stdout);
	int cycle = 1332028;
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i < cycle; ++i) {
		fib[i] = add(fib[i-1], fib[i-2]);
	}
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int l, r;
		long long k;
		scanf("%d %d %lld", &l, &r, &k);
		arr[l] = add(arr[l], fib[k % cycle]);
		arr[l+1] = add(arr[l+1], fib[(k - 1) % cycle]);
		arr[r+1] = add(arr[r+1], mod - fib[(k + r - l + 1) % cycle]);
		arr[r+2] = add(arr[r+2], mod - fib[(k + r - l) % cycle]);
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d ", arr[i]);
		arr[i+1] = add(arr[i+1], arr[i]);
		arr[i+2] = add(arr[i+2], arr[i]);
	}
	puts("");
	return 0;
}
