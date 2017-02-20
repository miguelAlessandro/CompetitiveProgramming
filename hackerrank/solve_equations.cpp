#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcdex(ll a, ll b, ll& x, ll& y){
	if(b == 0){
		x = 1; y = 0;
		return a;
	}
	ll x1, y1;
	ll gcd = gcdex(b, a%b, x1, y1);
	x = y1;
	y = x1 - (a/b)*y1;
	return gcd;
}

int q;
ll a, b, c, xg, yg, g;

inline long double cua(long double x){return x*x;}
inline long double f(long double x){return cua(xg+b*x) + cua(yg-a*x);}



int main(){
		
	scanf("%d", &q);
	while(q--){
		scanf("%lld %lld %lld", &a, &b, &c);
		g = gcdex(a, b, xg, yg);
				
		b /= g; a /= g;
		xg *= c/g; yg *= c/g;

		ll lo = (b-xg)/b, hi = (INT_MAX-xg)/b;
		while(lo < hi){
			ll mid = (lo+hi)>>1;
			if(f(mid) <= f(mid+1)) hi = mid;
			else lo = mid+1;
		}

		if(f(lo-1) <= f(lo) and xg+b*lo > b) lo--; 

		printf("%lld %lld\n", xg + b*lo, yg - a*lo);
	}

	return 0;
}	

