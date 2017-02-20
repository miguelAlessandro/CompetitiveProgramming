#include <iostream>
using namespace std;

int n;
bool is_lucky(int x){
	while(x){
		if(x%10 != 4 and x%10 != 7) return false;
		x /= 10;
	}	
	return true;
}


int main(){

	cin >> n;
	bool ok = false;
	for(int i = 1; i*i <= n and not ok; ++i)
		if(n%i == 0 and (is_lucky(i) or is_lucky(n/i))) ok = true;

	if(ok) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}
