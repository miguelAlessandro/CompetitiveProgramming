#include <iostream>
using namespace std;

int n;

int main(){


	while(cin >> n){

		int l, r, A;
		for(int len = 1; len*(len+1) <= 2*n; ++len){//elijo la longitud
			A = n - (len*len + len)/2;
			if(A%len == 0){
				l = A/len + 1;
				r = l + len - 1;
			}
		}
	
		cout << n << " = " << l << "+......+" << r << endl;
	}

	return 0;
}
