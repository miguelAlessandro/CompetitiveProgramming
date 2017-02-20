#include <iostream>
using namespace std;

int n;

int main(){

	cin >> n;

	int r1 = 0, r2 = 0;
	int x;

	for(int i = 0; i < n; ++i){
		cin >> x;
		r1 ^= x;
	}

	for(int i = 0; i+1 < n; ++i){
		cin >> x;
		r1 ^= x;
		r2 ^= x;
	}

	for(int i = 0; i+2 < n; ++i){
		cin >> x;
		r2 ^= x;
	}

	cout << r1 << endl;
	cout << r2 << endl;

	return 0;
}
