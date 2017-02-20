#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n, k;
char s[N];
int S, T;

int main(){

	scanf("%d %d%*c", &n, &k);
	scanf("%s", s);	

	for(int i = 0; i < n; ++i)
		if(s[i] == 'G') S = i;
		else if(s[i] == 'T') T = i;

	if(S > T) swap(S, T);

	bool ok = false;
	for(int i = S + k; i < n; i += k)
		if(s[i] == '#') break;
		else if(s[i] == 'G' or s[i] == 'T') ok = true;
	
	puts(ok ? "YES" : "NO");

	return 0;
}
