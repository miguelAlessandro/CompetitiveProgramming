#include <bits/stdc++.h>
using namespace std;
 
class Polyline { public:
	double length(int a, int b, int x0, int y0, int x1, int y1)	{
		return sqrt(pow(min(abs(x0-x1-2*a), abs(x0-x1+2*a)), 2) +  pow(min(abs(y0-y1-2*b), abs(y0-y1+2*b)), 2));
	}
};
