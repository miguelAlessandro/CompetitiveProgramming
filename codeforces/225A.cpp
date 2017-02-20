#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n;
int L[N], R[N];
int top, back;



int main(){
	scanf("%d %d", &n, &top);
	for(int i = 0; i < n; ++i)
		scanf("%d %d", L+i, R+i);

	int bitmask;
	back = 7-top;
	bool ok = true;
	for(int i = 0; i < n; ++i){
		bitmask = 0;
		bitmask |= (1<<L[i]);
		bitmask |= (1<<R[i]);
		bitmask |= (1<<7-L[i]);
		bitmask |= (1<<7-R[i]);
		if(bitmask&(1<<back)) ok = false;		
	}
	puts(ok?"YES":"NO");

	return 0;
}
