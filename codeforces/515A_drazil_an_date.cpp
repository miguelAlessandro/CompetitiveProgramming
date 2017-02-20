#include <iostream>
#include <algorithm>
using namespace std;

int n, m, s;

int main(){
	cin >> n >> m >> s;
	if(abs(n)+abs(m) <= s and (n+m-s)%2 == 0) cout << "Yes" << endl;
	else cout << "No" << endl;

	
	return 0;
}
