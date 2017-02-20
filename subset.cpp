#include <iostream>
using namespace std;

int n;

void backtracking(int mask, int pos){

	if(pos == n){
		for(int i = 0; i < n; ++i)
			if(mask&(1<<i))
				cout << i+1 << " ";
		cout << endl;
		return;
	}
	
	backtracking(mask, pos+1);
	backtracking(mask|(1<<pos), pos+1);
}

int main(){

	cin >> n;
	backtracking(0, 0);
	

	return 0;
}
