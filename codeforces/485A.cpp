#include <iostream>
using namespace std;

int m, a;
int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}


int main(){
	
	cin >> a >> m;
	
	m /= gcd(a, m);

	cout << ((m&(m-1)) == 0 ? "Yes" : "No") << endl;

	return 0;
}
