#include <iostream>
#include <cstdio>
#include <climits>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <queue>
#include <set>
using namespace std;

int n, c;
int d[30];
string s;
int vo[4] = {'A', 'C', 'G', 'T'};

int main(){

	cin >> n;
	cin >> s;

	for(int i = 0; i < n; ++i)
		if(s[i] != '?') d[s[i] - 'A']++;
	
	if(n%4){
		cout << "===" << endl;
		return 0;
	}

	for(int i = 0; i < 4; ++i)
		if(d[vo[i] - 'A'] > n/4){
			cout << "===" << endl;
			return 0;
		}

	vector<int> vv;
	for(int i = 0; i < 4; ++i)
		for(int j = 0; j < n/4 - d[vo[i] - 'A']; ++j)
			vv.push_back(vo[i]);
	
	//for(int i = 0; i < vv.size(); ++i)
	//	cout << vv[i] << endl;
	
	for(int i = 0; i < n; ++i)
		if(s[i] == '?'){
			cout << char(vv.back());
			vv.pop_back();
		}
		else
			cout << s[i];
	
	cout << endl;

	return 0;
}
