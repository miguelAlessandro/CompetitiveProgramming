#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 100005;
int n;
int a[N];
long long dp[N], v[N];

int main(){

	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", a+i);

	for(int i = 0; i < n; ++i)
		v[a[i]] += 1;
	
	dp[1] = v[1];
	for(int i = 2; i < N; ++i)
		dp[i] = max(dp[i-1], dp[i-2] + i*v[i]);

	printf("%I64d\n", dp[N-1]);

	return 0;
}
