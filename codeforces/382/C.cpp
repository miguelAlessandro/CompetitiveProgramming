#include <iostream>
using namespace std;

long long n;
long long f[100];


int main(){

	cin >> n;
	
	f[0] = 1;
	f[1] = 1;
	int r = 0;
	for(int i = 2; i < 100; ++i){
		f[i] = f[i-1] + f[i-2];
		if(f[i] > n) break;
		r++;
	}

	cout << r << endl;

	return 0;
}
