#include <iostream>
using namespace std;

int T, a, b;
int sumI(int n){
    return n*(n+1)/2 - (n/2)*(n/2+1);
}

int main() {
	
	cin >> T;
	for(int i = 1; i <= T; ++i){
	    cin >> a >> b;
	    cout << "Case " << i << ": " << sumI(b) - sumI(a-1) << endl;
	}
	
	return 0;
}
