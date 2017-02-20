#include <iostream>
using namespace std;

int n;
string x;
char block[700][700];
string B[700];
int len;

int bi_sqrt(int n){
	int lo = 0, hi = n;
	while(lo < hi){
		int mid = lo + (hi-lo+1)/2;
		if(mid*mid <= n) lo = mid;
		else hi = mid-1;
	}
	return lo;
}

void init(int n){
	len = bi_sqrt(n) + 1;
		
	for(int i = 0; i < n; ++i)
		block[i/len][i-(i/len)*len] = x[i];
	
	for(int i = 0; i < len; ++i)
		B[i] = Block[i*len];
}


int query1(int l, int r, int k){
	bool ok = true;
	while(l <= r)
		if(l%len == 0 and l + len - 1 <= r) ok |= block[l/len], l += len; 
		else ok |= 
}


int main(){

	cin >> x;
	init(x.size());
	cin >> n;
	while(n--){
		


	}

	return 0;
}
