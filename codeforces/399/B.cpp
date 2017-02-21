#include <bits/stdc++.h>
using namespace std;

long long n, l, r, k;
long long query(long long n, long long x, long long y){
	if(r < x or y < l or x > y) return 0; 
	long long mid = (y+x)>>1;
	return (l <= mid and mid <= r)*(n&1) + query(n>>1, x, mid-1) + query(n>>1, mid+1, y); 
}


int main(){

	cin >> n >> l >> r;
	long long m = n;
	while(m){
		k++;
		m>>=1;
	}
	
	cout << query(n, 1, (1LL<<k)-1) << endl;

	return 0;
}
