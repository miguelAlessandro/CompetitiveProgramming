#include <iostream>
using namespace std;

int n;

int main(){

	int r = 0;
	cin >> n;
	for(int x = 0, a, b, i = 0; i < n; ++i){
		cin >> a >> b;
		x += b - a;
		r = max(r, x);
	}

	cout << r << endl;

	return 0;
}
