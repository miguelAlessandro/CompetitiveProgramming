/**
 *  Codeforces Beta Round 7
 *  @find palindrome degre for all prefix (palindrome degre is defined: if s is empty, then PD = 0, else if 
 *  s es palindrome, PD(s) = 1 + min(PD(preffix of length |s|/2), PD(suffix of length |s|/2))
 *
 *  - hint: note than if s is palindrome, then PD(s) = 1 + PD(preffix of length |s|/2)
 */



#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e6 + 10;
const int mod = 1e9 + 7;
const int p = 257;
char s[MAXN];
int Hash[MAXN], rHash[MAXN];
int P[MAXN], iP[MAXN];
int d[MAXN];
int n;

int add(int a, int b) {
	if (a+b > mod) return a+b-mod;	
	return a+b;
}

int mul(long long a, long long b) {
	return a*b%mod;
}

int ex(int a, int b) {
	int r = 1;
	while (b > 0) {
		if (b&1) r = mul(r, a);
		a = mul(a, a);
		b >>= 1; 
	} 
	return r;
}

int range(int l, int r) {
	if (l == 0) return Hash[r];
	return mul(add(Hash[r], mod - Hash[l-1]), iP[l]);
}

int rrange(int l, int r) {
	if (r == n-1) return rHash[l];
	return mul(add(rHash[l], mod - rHash[r+1]), iP[n-1-r]);
}

bool isPalindrome(int a, int b) {
	return range(a, b) == rrange(a, b);
}

int main() {
	scanf("%s", s);
	n = strlen(s);
	int invp = ex(p, mod-2);
	iP[0] = P[0] = 1;
	for (int i = 1; i <= n; ++i) {
		P[i] = mul(P[i-1], p);
		iP[i] = mul(iP[i-1], invp);
	}
	
	Hash[0] = s[0];
	rHash[n-1] = s[n-1];
	for (int i = 1; i < n; ++i) {
		Hash[i] = add(Hash[i-1], mul(s[i], P[i]));	
		rHash[n-1-i] = add(rHash[n-i], mul(s[n-1-i], P[i]));
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (i == 0) d[0] = 1;
		else d[i] = isPalindrome(0, i) ? 1 + d[(i>>1) - (!(i&1))] : 0; 
		ans += d[i];
	}
	
	printf("%d\n", ans);
	return 0;
}
