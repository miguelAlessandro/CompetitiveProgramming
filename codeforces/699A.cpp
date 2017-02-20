#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int n;
string s;
int a[N], front;

int main(){

	cin >> n;
	cin >> s;
	for(int i = 0; i < n; ++i)
		cin >> a[i];

	front = 0;
	for(; front < n and s[front] != 'R'; ++front);
		

	int mini = INT_MAX;
	for(int i = front + 1; i < n; ++i)
		if(s[i] == 'L') mini = min(mini, (a[i]-a[front])/2); 
		else front  = i;			

	if(mini != INT_MAX)
		cout << mini << endl;
	else cout << -1 << endl;	

	return 0;
}
