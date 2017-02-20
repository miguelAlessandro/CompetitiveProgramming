#include <iostream>
using namespace std;

int n;

int main(){

	cin >> n;
	int r = 0;
	for(int x, y, z, i = 0; i < n; ++i){
		cin >> x >> y >> z;
		if(x + y + z >= 2) r+=1;
	}

	cout << r << endl;


	return 0;
}
