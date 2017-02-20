#include <iostream>
using namespace std;

int n;
int x1, y1, x2, y2;
int r;

int main(){

	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> x1 >> y1 >> x2 >> y2;
		r += (x2-x1+1)*(y2-y1+1);	
	}
	cout << r << endl;

	return 0;
}
