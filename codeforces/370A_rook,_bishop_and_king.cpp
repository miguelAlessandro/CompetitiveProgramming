#include <iostream>
#define abs(x) (((x)>=0) ? (x) : (-1*(x)))
using namespace::std; 

int r1, r2, c1, c2;


int main( void )
{
	cin >> r1 >> c1 >> r2 >> c2;
	
	if(r1 != r2  && c1 != c2)
		cout << 2 << " ";
	else
		cout << 1 << " ";

	if(abs(r2 - r1) == abs(c2 - c1))
		cout << 1 << " ";
	else
	{ 
		if((r1&1 && c1&1) || !(r1&1 || c1&1))//banco
		{
			if((r2&1 && c2&1) || !(r2&1 || c2&1))
				cout << 2 << " ";
			else
				cout << 0 << " ";
		}
		else if((r1&1 && !(c1&1)) || (!(r1&1) && c1&1))//negro
		{
			if((r2&1 && !(c2&1)) || (!(r2&1) && c2&1))
				cout << 2 << " ";
			else
				cout << 0 << " ";
		}
	}		
	
	int k1 = abs(r2 - r1), k2 = abs(c2 - c1);
	cout << max(k1, k2) << endl;	

	return 0;
}
