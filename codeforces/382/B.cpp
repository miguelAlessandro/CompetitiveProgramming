#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n, n1, n2;
int a[N];


int main(){

	scanf("%d %d %d", &n, &n1, &n2);
	for(int i = 0; i < n; ++i)
		scanf("%d", a+i);

	sort(a, a+n);
	
	if(n1 > n2) swap(n1, n2);

	int d = n - n1 - n2;

	long long sum2 = 0;
	for(int i = d; i < n2+d; ++i)
		sum2 += a[i];

	long long sum1 = 0;
	for(int i = n2+d; i < n; ++i)
		sum1 += a[i];

	printf("%Lf\n", (long double)(1.0*sum1*n2 + 1.0*sum2*n1)/(1.0*n1*n2));
	

	return 0;
}
