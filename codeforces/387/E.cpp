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

const int N = 1000000;
string s;
int t = 0;
vector<string> v[N];

bool dfs(int dep){
	
	t = max(t, dep);
	
	getline(cin, s, ',');
	if(s == "") return false;

	v[dep].push_back(s);	

	int l;
	cin >> l;
	cin.ignore();
	for(int i = 0; i < l; ++i)
		dfs(dep+1);

	return true;
}

int main(){
		
	while(dfs(0));

	cout << t+1 << endl;
	for(int i = 0; i <= t; ++i){
		for(int j = 0; j < v[i].size(); ++j)
			cout << v[i][j] << " ";

		cout << endl;
	}

	return 0;
}
