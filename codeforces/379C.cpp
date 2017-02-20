#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int m, k;
long long n, x, s;
long long a[N], b[N], c[N], d[N];


int main(){

	scanf("%lld %d %d", &n, &m, &k);
	scanf("%lld %lld", &x, &s);
	for(int i = 0; i < m; ++i) scanf("%lld", a+i);
	for(int i = 0; i < m; ++i) scanf("%lld", b+i);
	for(int i = 0; i < k; ++i) scanf("%lld", c+i);
	for(int i = 0; i < k; ++i) scanf("%lld", d+i);

	long long r = n*x;
	
	for(int i = 0; i < m; ++i)
		if(b[i] <= s)
			r = min(r, a[i]*n);

	for(int i = 0; i < k; ++i)
		if(d[i] <= s)
			r = min(r, max(0LL,n-c[i])*x);
	

	for(int i = 0; i < m; ++i)
		if(b[i] <= s){

			int lo = 0, hi = k-1;
			while(lo < hi){
				int mid = lo + (hi-lo+1)/2;
				if(b[i] + d[mid] <= s) lo = mid;
				else hi = mid-1;
			}

			if(b[i] + d[lo] <= s) r = min(r, max(0LL, n-c[lo])*a[i]); 
		}

	printf("%lld\n", r);

	return 0;
}
