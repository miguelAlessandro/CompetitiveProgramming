#include <iostream>
#include <algorithm>
using namespace std;

int X[2], Y[2];

int main(){

	for(int i = 0; i < 2; ++i)
		cin >> X[i] >> Y[i];

	int l1 = abs(X[1]-X[0]), 
		l2 = abs(Y[1]-Y[0]);

	if(l1 == 0){
		if(X[0] + l2 <= 1000)
			cout << X[0] + l2 << " " << Y[0] << " " <<
					X[1] + l2 << " " << Y[1] << endl;
		else if(X[0] - l2 >= -1000)
			cout << X[0] - l2 << " " << Y[0] << " " <<
					X[1] - l2 << " " << Y[1] << endl;
		else
			cout << -1 << endl;
	}
	else if(l2 == 0){
		if(Y[0] + l1 <= 1000)
			cout << X[0] << " " << Y[0] + l1 << " " <<
					X[1] << " " << Y[1] + l1 << endl;
		else if(Y[0] - l1 >= -1000)
			cout << X[0] << " " << Y[0] - l1 << " " << 
					X[1] << " " << Y[1] - l1 << endl;
		else
			cout << -1 << endl;
	}
	else if(l1 == l2)
		cout << X[0] << " " << Y[1] << " " << X[1] << " " << Y[0] << endl;
	else
		cout << -1 << endl;

	return 0;
}
