#include <bits/stdc++.h>
using namespace std;

int n;
int main(){

	cin >> n;
	for(int i = 1; i <= n; ++i){

		cout << "0 ";
		int ans = 1, r=-1;
		for(int j = 1; j <= i; ++j){
			int a = __builtin_popcount(j);
			int b = __builtin_popcount(i-j); 
			int c = __builtin_popcount(i);
			cout << a+b-c << " ";

			if(a+b==c) ans += j+1;
			if(a+b == c+1) r = j+1;  
		}
		cout << " -> ";
		if(r==-1) cout << 0 << endl;
		else cout << ans << " + " << r << " = " << ans+r << endl;
	}

	return 0;
}
