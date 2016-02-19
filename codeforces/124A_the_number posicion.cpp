#include <iostream>

using namespace::std;

int main( void )
{
	int a, b, n;

	cin >> n >> a >> b;
	
	cout << min(n-a, b+1) << endl;

	return 0;
}
