#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int k;
string s;
int a[N][30], r1, r2;

bool proof(int lo, int x){
	int t = 0;
	if(lo == 0){
		for(int i = 0; i < 26; ++i)
			if(a[x][i] != 0) t++;
	}
	else	
		for(int i = 0; i < 26; ++i)
			if(a[x][i] != a[lo-1][i]) t++;

	return t <= k;
}


int main(){

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> k >> s;

	a[0][s[0]-'a'] = 1;
	for(int i = 1; i < s.size(); ++i){
		for(int j = 0; j < 26; ++j)
			a[i][j] += a[i-1][j];

		a[i][s[i]-'a'] += 1; 
	}


	int len = 0, l, r;
	for(int i = 0; i < s.size(); ++i){
		int lo = i, hi = s.size()-1;
		while(lo < hi){
			int mid = lo + (hi-lo+1)/2;
			if(proof(i, mid)) lo = mid;
			else hi = mid-1;
		}
		if(proof(i, lo) and len < lo-i+1){
			len = lo-i+1;
			l = i;
			r = lo;
		}
	}

	cout << l+1 << " " << r+1 << endl;	

	return 0;
}
	
