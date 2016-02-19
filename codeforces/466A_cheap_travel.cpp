#include <iostream>

using namespace::std;


int n, m, a, b;

int main( void )
{
	int s = 0;
	cin >> n >> m >> a >> b;
	if(b < m*a)
	{
		s += (n/m)*b;
		n %= m;
		if(n == 0)
			cout << s << endl;
		else
		{
			if(n*a > b)
				cout << s + b << endl;
			else
				cout << s + n*a << endl;
		}		
	}
	else
		cout << (n*a) << endl;
	return 0;
}
