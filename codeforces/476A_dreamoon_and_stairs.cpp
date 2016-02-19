#include <iostream>

using namespace::std;

int n, m;

int main( void )
{
	cin >> n >> m;
	
	if(m > n)
		cout <<	-1 << endl;
	else
		if(n%2 == 0 && (n>>1)%m == 0)
			cout << (n>>1) << endl;
		else
			cout << ((n>>1)/m + 1)*m << endl;
			

	return 0;
}
