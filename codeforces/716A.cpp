#include <iostream>
using namespace std;

const int N = 100005;
int n, c;
int a;

int main(){
	cin >> n >> c;
	int r = 1;
	cin >> a;
	for(int b, i = 1; i < n; ++i){
		cin >> b;
		if(b - a <= c) r++;		
		else r = 1;

		a = b;
	}	

	cout << r << endl;

	return 0;
}
