#include <iostream>
using namespace std;

const int N = 55;
long long m, exp;
int n;
int p[N];

int main(){

	cin >> n >> m;
	
	exp = 1<<n-1;

	int lo = 0, hi = n-1, val = 1;
	while(exp){
		if(2*m > exp){
			p[hi--] = val;
			m -= exp/2;
		}
		else p[lo++] = val;	
		
		exp >>= 1;
		val += 1;
	}
	
	for(int i = 0; i < n; ++i)
		cout << p[i] << " ";
	cout << endl;

	return 0;
}
