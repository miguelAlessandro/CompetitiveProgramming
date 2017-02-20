#include <iostream>
using namespace std;


const int N = 100005;
int n, k;

int main(){

	cin >> n >> k;
	if(k < n/2){
		cout << -1 << endl;
		return 0;
	}
	
	if(n == 1){
		if(k == 0) cout << 1 << endl;
		else cout << -1 << endl;
		return 0;
	}

	int x;
	x = k - (n/2);
	if(x == 0){
		for(int i = 1; i <= n; ++i)
			cout << i << " ";
		cout << endl;
	}
	else{
		int g = x + 1;
		cout << g << " " << 2*g << " ";
		for(int i = 1; i < n-1; ++i)
			cout << 2*g + i << " ";
				
		cout << endl; 
	}


	return 0;
}
