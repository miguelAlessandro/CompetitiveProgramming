#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int n, a, b, k;
string s;
int shoot[N];

int main(){

	cin >> n >> a >> b >> k;
	cin >> s;
	int l = 0;
	for(int x = 0, i = 0; i < n; ++i){
		if(s[i] == '0') x++;
		else x = 0;
		if(x == b){
			shoot[l++] = i+1;
			x = 0;	
		}
	}

	l -= a-1;
	cout << l << endl;
	for(int i = 0; i < l; ++i)
		cout << shoot[i] << " ";
	cout << endl;

	return 0;
}
