#include <bits/stdc++.h>
using namespace std;

int q;
long long n, m, s;

long long ck(long long m){
	long long lo = 1, hi = n;
	while(lo < hi){
		long long mid = lo + (hi - lo + 1)/2;
		if(mid*(mid-3) <= 2*(m-n)) lo = mid;
		else hi = mid-1;
	}
	return lo;
}


int main(){

	scanf("%d", &q);
	while(q--){
		scanf("%lld %lld %lld", &n, &m, &s);
		long long C = (n-1)*(n-2)/2;
		if(n == 2){
			printf("%lld\n", s);
			continue;
		}

		long long k = ck(m);
		long long mx = max(s/(k-1), 1LL);
		long long CK = k*(k-1)/2;
		long long ans = (m - CK)*(s-k) + m;
		ans = min(s + (m-n+1)*((s+n-2)/(n-1)), ans);

		printf("%lld\n", ans);
	}

	return 0;
}
