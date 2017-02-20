#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10;
int in[N];
string s[N]; 
int n, k;

inline 
int to_number(const string& s){
	int res = 0;
	for(int i = 0; i < k; ++i)
		res = 10*res + (s[in[i]] - '0');

	return res;
}

int main(){

	cin >> n >> k;
	for(int i = 0; i < n; ++i) 
		cin >> s[i];

	for(int i = 0; i < k; ++i) in[i] = i;
	
	int mini = -1000000000, maxi = 1000000000;
	while(true){

		int local_mini = 1000000000, local_maxi = 0;
		for(int i = 0; i < n; ++i){
			local_mini = min(local_mini, to_number(s[i]));
			local_maxi = max(local_maxi, to_number(s[i]));
		}

		if(maxi - mini > local_maxi-local_mini)
			maxi = local_maxi,
			mini = local_mini; 

		if(not next_permutation(in, in+k)) break;
	}	

	cout << maxi-mini << endl;

	return 0;
}
