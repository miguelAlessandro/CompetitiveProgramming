#include <iostream>

using namespace::std;

int main( void )
{
	long long a, b, c;
	cin >> a >> b >> c;

	long long total = min(2*(a+b), min(a + b + c, min( 2*(a + c), 2*(b + c))));
	cout << total << endl;
	
	return 0;
}	
