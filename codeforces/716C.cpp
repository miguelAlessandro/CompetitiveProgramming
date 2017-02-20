#include <bits/stdc++.h>
using namespace std;

int n;

int main(){

	cin >> n;
	for(int i = 1; i <= n; ++i){
		if(i == 1) cout << 2 << endl;
		else cout << 1LL*i*i*i + 2LL*i*i + 1 << endl;	 	
	}


	return 0;
}

