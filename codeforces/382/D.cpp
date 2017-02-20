#include <iostream>
using namespace std;

int n;
bool IsPrime(int x){
	for(int i = 2; i*i <= x; ++i)
		if(x%i == 0) return false;
	return true;
}


int main(){

	cin >> n;
	if(n%2 == 0) cout << 1 + (n > 2) << endl;
	else if(IsPrime(n)) cout << 1 <<  endl;
	else if(IsPrime(n-2)) cout << 2 << endl;
	else cout << 3 << endl;

	return 0;
}
