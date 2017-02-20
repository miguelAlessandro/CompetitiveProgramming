#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int a[4], d;
bool D[N];


int main(){

	for(int i = 0; i < 4; ++i)
		cin >> a[i];
	cin >> d;

	for(int i = 0; i < 4; ++i)
		for(int j = a[i]; j <= d; j += a[i])	
			D[j] = true;

	int r = 0;
	for(int i = 1; i <= d; ++i)
		r += D[i];
	
	cout << r << endl;

	return 0;
}
