#include <iostream>
using namespace std;

int comb(int n, int k){
	
	if(k == 0 or n == k) return 1; 

	return comb(n-1, k-1) + comb(n-1, k) + 1;
}

int n, k;

int main(){

	cin >> n >> k;
	cout << comb(n, k) << endl;

	return 0;
}	
