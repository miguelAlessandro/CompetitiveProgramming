/**********************
round: 397
handle: _threat_
theme: string, ad-hoc
complexity: O(n)
**********************/

#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
bool vis[N], ok=true;
string s;

int main(){

	cin >> s;
	for(char it : s)
		if(not vis[it-'a']){
			vis[it-'a'] = true;
			ok &= it-'a'==t; t++;	
		} 

	puts(ok?"YES":"NO");

	return 0;
}
