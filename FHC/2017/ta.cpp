#include <iostream>
using namespace std;

int main(){

	cout << 101*101*101 << endl;
	for(int i = 0; i <= 100; ++i)
		for(int j = 0; j <= 100; ++j)
			for(int k = 0; k <= 100; ++k)
				cout << i << " " << j << " " << k << endl;


	return 0;
}
