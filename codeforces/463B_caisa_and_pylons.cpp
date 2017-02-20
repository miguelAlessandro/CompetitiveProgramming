#include <iostream>
using namespace std;

int n;

int main(){
	
	cin >> n;
	int e = 0, h = 0;
	int r = 0;

	for(int x, i = 0; i < n; ++i){
		cin >> x;
		if(x >= h)
			if(e >= x-h) e -= x-h;
			else{
				r += x-h-e;
				e = 0;
			}  
		else	
			e += h-x;			

		h = x;
	}

	cout << r << endl;

	return 0;
}
