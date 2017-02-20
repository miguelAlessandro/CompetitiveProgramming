#include <iostream>
using namespace std;

int n;
long long x, a, b;

int main(){

	cin >> n >> a >> b;
	for(int i = 0; i < n; ++i){
		cin >> x;
		cout << ((x*a)%b)/a << " ";
	}
	cout << endl;	

	return 0;	
}
