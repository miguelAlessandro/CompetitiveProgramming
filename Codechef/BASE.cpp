#include <bits/stdc++.h>
#define gc getchar_unlocked
using namespace std;

int t;
long long n;

bool expfast(long long x, long long np, int k){
	long long r = 1;
	while(k){
		if(r >= (1000000000000LL + x - 1)/x) return true;
		if(k&1) r *= x;
		if(x >= (1000000000000LL + x - 1)/x and (k>>1)) return true;		
		x *= x;
		k >>= 1;
	}

	return np < r;
}

//n < 2*x^k
bool p1(long long x, int k){
	return not expfast(x, n>>1, k);
}

bool p2(long long x, int k){
	return not expfast(x, n, k); 
}

int ri() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  int ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}

long long rll() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  long long ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}

int Log2(long long n){
	int r = 0;
	while(n >= 2) n /= 2, r++;
	return r;
}

int main(){

	t = ri();
	while(t--){
		n = rll();
		
		if(n == 1){
			puts("INFINITY");
			continue;
		}
		
		int k = Log2(n);
		long long ans = 0;
		for(int i = 1; i <= k; ++i){
			long long lo1 = 2, hi1 = n;
			while(lo1 < hi1){		
				long long mid = lo1 + (hi1-lo1)/2;
				if(p1(mid, i)) lo1 = mid+1;
				else hi1 = mid;
			}

			long long lo2 = lo1, hi2 = n;
			while(lo2 < hi2){
				long long mid = lo2 + (hi2-lo2+1)/2;
				if(p2(mid, i)) lo2 = mid;
				else hi2 = mid-1;
			}
			if(p2(lo2, i)) ans += lo2 - lo1 + 1;
		}
		printf("%lld\n", ans);
	}


	return 0;
}
