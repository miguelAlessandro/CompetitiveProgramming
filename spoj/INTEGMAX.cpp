#include <bits/stdc++.h>
using namespace std;

const int N = 10005;
int n;
int X[N], Y[N], D[N];

int main(){

	
	while(scanf("%d", &n), n != -1){
		
		for(int i = 0; i < n; ++i) scanf("%d", X+i); 
		for(int i = 0; i < n; ++i) scanf("%d", Y+i);

		D[0] = X[1]-X[0];
		D[n-1] = X[n-1]-X[n-2];

		for(int i = 1; i+1 < n; ++i)
			D[i] = X[i+1] - X[i-1];

		sort(Y, Y+n);
		sort(D, D+n);

		long long r = 0;
		for(int i = 0; i < n; ++i)
			r += Y[i]*1LL*D[i];

		if(r&1LL) printf("%lld.5\n", r>>1);
		else printf("%lld.0\n", r>>1);
	}

	return 0;
}
