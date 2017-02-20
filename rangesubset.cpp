#include <iostream>
#include <vector>
using namespace std;

const int N = 20;
vector<int> v;
int d[N];
int n, a, b;

void backtracking(int mask, int pos, int sum){

	if(pos == n){
		if(sum >= a) v.push_back(mask);
		return;
	}

	if(d[pos] + sum <= b) backtracking(mask|(1<<pos), pos+1, sum + d[pos]);
	
	backtracking(mask, pos+1, sum);

}

int main(){

	cin >> n >> a >> b;
	for(int i = 0; i < n; ++i)
		cin >> d[i];

	backtracking(0, 0, 0);

	for(int i = 0; i < v.size(); ++i){
		for(int j = 0; j < n; ++j)
			if(v[i]&(1<<j))
				cout << d[j] << " ";
		cout << endl;
	}

	return 0;
}
