#include <bits/stdc++.h>
using namespace std;

const int N = 80;
long long a[2*N][2*N];
int n, t;

int main(){
	
	scanf("%d", &t);
	while(t--){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			scanf("%lld", &a[i][j]);

	for(int i = 1; i <= 2*n; ++i)
		for(int j = 1; j <= 2*n; ++j)
			if(i > n) a[i][j] = a[i-n][j];
			else if(j > n) a[i][j] = a[i][j-n];

	for(int i = 1; i <= 2*n; ++i)
		for(int j = 1; j <= 2*n; ++j)
			a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];		

	long long maximum = LLONG_MIN;
	for(int i = 1; i <= 2*n; ++i)
		for(int j = 1; j <= 2*n; ++j)
			for(int k = i; k-i+1 <= n and k <= 2*n; ++k)
				for(int l = j; l-j+1<=n and l <= 2*n; ++l)
					maximum = max(maximum, a[k][l]-a[k][j-1]-a[i-1][l]+a[i-1][j-1]);

	printf("%lld\n", maximum);	
	}

	return 0;
}
