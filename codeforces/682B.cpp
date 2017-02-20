#include <bits/stdc++.h>
using namespace std;

int n;
map<int, int> mapa;

int main(){

	scanf("%d", &n);
	for(int x, i = 0; i < n; ++i){
		scanf("%d", &x);
		mapa[x]++;
	}

	int r = 0;
	for(auto it : mapa)
		r = min(it.first, r+it.second);

	printf("%d\n", r+1);

	return 0;
}
