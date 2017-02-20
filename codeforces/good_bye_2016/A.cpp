#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n, k;


int main(){

	cin >> n >> k;
	int r = 0;
	for(int i = 0; i <= n; ++i)
		if(5*i*(i+1)/2 + k <= 240)
			r = i;
	cout << r << endl;

	return 0;
}
