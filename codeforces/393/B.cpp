#include <bits/stdc++.h>
using namespace std;

long long n, m, k;

bool p(long long x){
	
	long long r = m - x;
	long long l1 = min(x-1, k-1);
	long long l2 = min(n-k, x-1);

	long long r1 = 1LL*(x-l1-1)*(k-1) + 1LL*l1*(l1+1)/2;
	long long r2 = 1LL*(x-l2-1)*(n-k) + 1LL*l2*(l2+1)/2;


	return r1+r2 <= r;
}

int main(){

	scanf("%lld %lld %lld", &n, &m, &k);
	m -= n;

	int lo = 0, hi = m;
	while(lo < hi){
		int mid = lo + (hi-lo+1)/2;
		if(p(mid)) lo = mid;
		else hi = mid-1;
	}

	printf("%d\n", lo+1);

	return 0;
}
