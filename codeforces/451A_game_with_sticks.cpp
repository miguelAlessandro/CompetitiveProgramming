#include <iostream>
using namespace std;


int n, m;

int main(){

	cin >> n >> m;	
	if(min(n, m)&1) cout << "Akshat" << endl;
	else cout << "Malvika" << endl;

	return 0;
}
