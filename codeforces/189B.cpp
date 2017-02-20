#include <bits/stdc++.h>
using namespace std;

int h, w;


int main(){
	cin >> w >> h;
	long long sum = 0; 
	for(int i = 1; 2*i <= h; ++i)
		for(int j = 1; 2*j <= w; ++j)
			sum += (h-2*i+1)*(w-2*j+1);

	cout << sum << endl;

	return 0;
}
