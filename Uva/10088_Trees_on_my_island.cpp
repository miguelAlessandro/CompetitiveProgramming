/*
	pick's theorem

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int X[N], Y[N];
int n;

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

long long cross(int a, int b){
	return X[a] * 1ll * Y[b] - Y[a] * 1ll * X[b];
}

int main(){

	while(scanf("%d", &n), n){
		for(int i = 0; i < n; ++i)
			scanf("%d %d", X+i, Y+i);

		int B = 0;
		for(int i = 0; i < n; ++i)
			B += gcd(abs(X[i] - X[(i+1)%n]), abs(Y[i] - Y[(i+1)%n]));
		
		long long A = 0;
		for(int i = 0; i < n; ++i)
			A += cross(i, (i+1)%n);

		A = abs(A);
		
		printf("%lld\n", (A - B + 2)>>1);
	}
	
	return 0;
}
