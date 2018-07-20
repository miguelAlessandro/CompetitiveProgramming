#include <bits/stdc++.h>
using namespace std;
int n, a, b;

bool isPrime(int n) 
{
	if (n < 2) return 0;
	for (int i = 2; i*i <= n; ++i)
		if (n%i == 0) return 0;
	return 1;
}
int main () 
{
	cin >> n;
	while (n --) {
		cin >> a >> b;
		a = abs(a); b = abs(b);
		if (a > b) swap(a, b);
		puts( (a == 0 ? b%4 == 3 and isPrime(b) : isPrime(a*a + b*b)) ? "P" : "C" ) ;
	}
	return 0;
}
