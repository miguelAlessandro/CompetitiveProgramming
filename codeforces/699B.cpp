#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int col[N], row[N]; 
int n, m, l;
string s[N];
bool ok;

int main(){

	cin >> n >> m;

	for(int i = 0; i < n; ++i){	
		cin >> s[i];
		for(int j = 0; j < m; ++j)
			if(s[i][j] == '*'){
				col[j]++;
				row[i]++;
				l++;
			}
	}

	ok = false;
	int x, y;
	for(int i = 0; i < n and not ok; ++i)
		for(int j = 0; j < m and not ok; ++j)
			if(s[i][j] == '*' and row[i] + col[j] == l+1)
				x = i+1, y = j+1, ok = true;
			else if(s[i][j] == '.' and row[i] + col[j] == l)		
				x = i+1, y = j+1, ok = true;

	if(ok){
		cout << "YES" << endl;
		cout << x << " " << y << endl;
	}
	else cout << "NO" << endl;

	return 0;
}
