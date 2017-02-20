#include <iostream>
#include <cstdio>
using namespace std;

int t;
long long n;

long long joseph (long long n, int k) {
	if (n == 1)  return 0;
	if (k == 1)  return n-1;
	if (k > n)  return (joseph (n-1, k) + k) % n;
	long long cnt = n / k;
	long long res = joseph (n - cnt, k);
	res -= n % k;
	if (res < 0)  res += n;
	else  res += res / (k - 1);
	return res;
}

int main(){

	scanf("%d", &t);
	while(t--){
		scanf("%lld", &n);
		printf("%lld\n", joseph(n, 2)+1);
	}

	return 0;
}
