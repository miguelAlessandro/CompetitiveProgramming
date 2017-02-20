#include <iostream>
#include <cmath>
using namespace std;

long long r, x, y, xp, yp;
long long dis2(long long x, long long y, long long xp, long long yp){
	return (xp-x)*(xp-x) + (yp-y)*(yp-y);
}

long long bisqrt(long long x){
	long long lo = 0, hi = x;
	while(lo < hi){
		long long mid = lo+(hi-lo)/2;
		if(mid*mid < x) lo = mid+1;
		else hi = mid;
	}
	return lo;
}

int main(){

	cin >> r >> x >> y >> xp >> yp;
	if(x == xp and y == yp) cout << 0 << endl;
	else cout << (long long)(floor((sqrt(dis2(x, y, xp, yp)) + 2*r - 0.000001)/(2*r))) << endl;
	
	//cout << floor((sqrt(dis2(x, y, xp, yp)) + 2*r - 0.1)/(2*r)) << endl;		


	return 0;
}
