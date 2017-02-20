#include <bits/stdc++.h>
using namespace std;

int p;
int expfast(int a, int n){
	int r = 1;
	while(n){
		if(n&1) r = (r*1LL*a)%p;
		a = (a*1LL*a)%p;
		n >>= 1;
	}
	return r;
}


int main(){

	cin >> p;
	
	int x = p-1;
	int phi = x;
	vector<int> f;

	for(int i = 2; i*i <= x; ++i)
		if(x%i == 0){
			while(x%i == 0) x /= i;
			
			f.push_back((p-1)/i);
			phi -= phi/i;
		}

	if(x > 1){
		phi -= phi/x;
		f.push_back((p-1)/x);
	}
	
		
	for(int a = 2; a <= p-1; ++a){
		bool ok = true;
		for(int i = 0; i < f.size() and ok; ++i)	
			if(expfast(a, f[i]) == 1)
				ok = false;

		if(ok){
			cout << a << " ";
			break;
		}
	}

	cout << phi << endl;

	return 0;
}
