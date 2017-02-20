#include <iostream>
using namespace std;

int a, b, c;

int main(){

	cin >> a >> b >> c;
	if(c == 0){
		if(a == b) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	else if((b-a)%c == 0){
		if((b-a)/c >= 0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	else
		cout << "NO" << endl;


	return 0;
}
