#include <bits/stdc++.h>
using namespace std;

vector<int> lis, a;
int n;

int main(){

	cin >> n; a.resive(n);
	for(int i = 0; i < n; ++i) cin >> a[i];

	for(int i = 0; i < n; ++i){
		int lo = 0, hi = lis.size()-1;
		while(lo < hi){
			int mid = lo+(hi-lo)/2;
			if(lis[mid] <= a[i]) lo = mid+1;
			else hi = mid;
		}
		if()		

	}

	return 0;
}
