#include <bits/stdc++.h>
using namespace std;

set<int> Y;
set<int> X;
int n;

bool half(int x){
	if(x == 1){
		Y.erase(-1);
		X.insert(1);	
		return false;
	}	
	if(Y.find(-x/2) != Y.end() and half(x/2)){
		X.insert(x/2);
		Y.erase(-x);
		return true;
	}
	if(Y.find(-x/2) == Y.end() and X.find(x/2) == X.end()){
		X.insert(x/2);
		Y.erase(-x);
		return true;
	}

	Y.erase(-x);
	X.insert(x);
	return false;
}


int main(){
	
	cin >> n;
	for(int x, i = 0; i < n; ++i){
		cin >> x;
		Y.insert(-x);
	}

	while(not Y.empty())
		half(-*Y.begin());

	for(auto it : X)
		cout << it << " ";
	cout << endl;

	return 0;
}
