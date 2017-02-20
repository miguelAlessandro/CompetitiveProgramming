#include <iostream>
using namespace std;

long long n, a, b, c;

int main(){

	cin >> n >> a >> b >> c;

	if(n%4 == 0) cout << 0 << endl;
	else if(n%4 == 1) cout << min(a+b, min(3*a, c)) << endl;
	else if(n%4 == 2) cout << min(b, min(2*a, 2*c)) << endl;
	else cout << min(a, min(b+c, 3*c)) << endl;

	return 0;
}
