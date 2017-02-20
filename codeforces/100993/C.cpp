#include <bits/stdc++.h>
using namespace std;

const int N = 50005;
int t, n;
int a[N];

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(){

	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) scanf("%d", a+i);
		
		int g = 0;
		for(int i = 0; i < n; ++i) g = gcd(g, a[i]); 

		int x = a[0], y = 0;
		int l = 0, t;
		for(int i = 1; i < n; ++i)
			if(gcd(a[i], x) == g){
				if(not l) t = i, l++;
				y = gcd(y, a[i]);
			}
			else{
				if(gcd(y, a[i]) != y)x = gcd(a[i], x); 
				else if(not l) t = i, l++;
			}
		
		int z = a[l], w = 0;
		for(int i = 0; i < n; ++i)
			if(i == t) continue;
			else if(gcd(a[i], z) == g){
				w = gcd(w, a[i]);
			}
			else{
				if(gcd(w, a[i]) != w) z = gcd(a[i], z);
			}


		printf("%d\n", max(min(x, y), min(z, w)));

	}

	return 0;
}
