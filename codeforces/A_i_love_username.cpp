#include <iostream>
using namespace std;

int n;
int mini, maxi, x;

int main(){

	cin >> n;
	cin >> x;
	maxi = mini = x;

	int r = 0;
	for(int i = 1; i < n; ++i){
		cin >> x;
		if(x > maxi) r++;
		else if(x < mini) r++;
	
		maxi = max(maxi, x);
		mini = min(mini, x);
	}

	cout << r << endl;

	return 0;
}
