#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100005;
int n, t, k;
long long a[N], b[N];

int main(){

	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &k);
		for(int i = 0; i < n; ++i)
			scanf("%lld", a+i);

		sort(a, a+n);
		for(int i = 0; i < n-1; ++i)
			b[i] = a[i] - a[i+1];

		sort(b, b+n-1);
		
		long long res = 0;
		for(int i = 0; i < k-1; ++i)
			res += b[i];

		res += a[n-1] - a[0];

		printf("%lld\n", res);
	}

	return 0;
}
