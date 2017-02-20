#include <iostream>
using namespace std;

int fibonacci(int n){

	if(n == 0 or n == 1) return 1;

	return fibonacci(n-1) + fibonacci(n-2);
}


const int MOD = 1000000007;
const int N = 1000001;
int n;
int a[N];

int main(){

	cin >> n;
	//cout << fibonacci(n) << endl;

	a[0] = 1;
	a[1] = 1;
	for(int i = 2; i <= n; ++i)
		a[i] = (a[i-1] + a[i-2])%MOD;

	cout << a[n] << endl;

	return 0;
}
