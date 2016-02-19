#include <iostream>
#define f(x, y, z) for(int x = y; x < z; x++)

using namespace::std;
int n, l, m;

int main( void )
{
	cin >> n;
	
	l = n*n;
	m = 1;	
	

	f(i, 0, n*n/2)
	{
		cout << (l--) << " ";
		cout << (m++) << endl;
	}
	return 0;
}
