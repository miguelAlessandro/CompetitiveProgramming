#include <iostream>
using namespace std;


int h1, h2, a, b;

int main(){

	cin >> h1 >> h2 >> a >> b;

	if(8*a + h1 >= h2) cout << 0 << endl;
	else if(a - b <= 0) cout << -1 << endl;
	else cout << (h2 - h1 + 4*a - 12*b - 1)/12/(a-b) << endl;


	return 0;
}
