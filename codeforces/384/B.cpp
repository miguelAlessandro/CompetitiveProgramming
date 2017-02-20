#include <iostream>
using namespace std;

int n;
long long k;
long long p;


int main(){

	cin >> n >> k;
	p = (1LL<<n)-1;
	int r = n;	


	while(true){
		if(k == (p+1)/2) break;  
		else if(k > (p+1)/2) k -= (p+1)/2;
		
		p >>= 1;
		r--; 
	}

	cout << r << endl;

	return 0;
}
