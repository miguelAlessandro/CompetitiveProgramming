#include <bits/stdc++.h>

using namespace::std;

int main( void )
{
	string X, Y;
	cin >> X;
	cin >> Y;

	int n = X.length(),
		m = Y.length();	

	if(n != m)
		cout << "NO" << endl;
	else
	{
		bool f = true;
		char *a = &X[0],
			 *b = &Y[m-1];
		for(int i = 0; i < n; i++)
			if(*a++ != *b--)
				f = false;
		
		if(f)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;	
	}
	return 0;
}

