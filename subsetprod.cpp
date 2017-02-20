#include <iostream>
#include <vector>
using namespace std;

const int N = 20;
vector<int> set;
int n;
int a[N];

void f(vector<int> s, int pos){

	if(pos == n){
		
		for(int i = 0; i < s.size(); ++i)
			cout << s[i] << " ";
		cout << "\n";		
		
		return;
	}

	s.push_back(a[pos]);
	  f(s, pos+1);
	s.pop_back();
	f(s, pos+1);
}


int main(){

	cin >> n;
	for(int i = 0; i < n; ++i) cin >> a[i];

	f(set, 0);

	return 0;
}
