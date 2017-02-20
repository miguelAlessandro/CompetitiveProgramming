#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int q;
ll w, x, y, z, l, r;

void expfast(ll a, ll b, ll k, ll m, ll& c, ll& d){
	c = 1; d = 0;
	ll temp1, temp2;
	while(k > 0){
		if(k&1LL){
			temp1 = c, temp2 = d;
			c = (temp1*a - temp2*b)%m;
			d = (a*temp2 + b*temp1)%m;
		}
 		
		temp1 = a; temp2 = b;
		a = (temp1*temp1 - temp2*temp2)%m;
		b = (2LL*temp1*temp2)%m;
		k >>= 1;
	}
}

int main(){

	scanf("%d", &q);
	while(q--){
		scanf("%lld %lld %lld %lld", &w, &x, &y, &z);
		expfast(w, x, y, z, l, r);		
		printf("%lld %lld\n", (z+l%z)%z, (z+r%z)%z);
	}

	return 0;
}
