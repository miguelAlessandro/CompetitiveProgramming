#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
int n, q, c, x, y;
long long ft[N];

void update(int x, long long v){
	while(x <= n){
		ft[x] += v;
		x += x&-x;
	}
}

long long query(int x){
	long long sum = 0;
	while(x > 0){
		sum += ft[x];
		x -= x&-x;
	}
	return sum;
}


int main(){

	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; ++i){
		scanf("%lld%*c", &x);
		update(i, x);
	}

	while(q--){
		c = getchar();
		scanf("%d %d%*c", &x, &y);		
		if(c == 'S') printf("%lld\n", query(y+1) - query(x));
		else if(c == 'G') update(x+1, y);
		else if(c == 'T') update(x+1, 0-y);
	}
	

	return 0;
}
