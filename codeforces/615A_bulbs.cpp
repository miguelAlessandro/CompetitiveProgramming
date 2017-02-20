#include <iostream>
#include <set>
using namespace std;

int n, m;
set<int> s;

int main(){

	cin >> n >> m;
	for(int x, i = 0; i < n; ++i){
		cin >> x;
		for(int y, j = 0; j < x; ++j){
			cin >> y;
			s.insert(y);
		}	
	}
	
	if(s.size() == m)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}
