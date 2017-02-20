#include <iostream>
#include <cstdio>
using namespace std;

const int N = 200005;
int a[N];
int n, s;

int main(){

	scanf("%d %d", &n, &s);
	int ans = 0;
	for(int x, i = 1; i <= n; ++i){
		scanf("%d", &x);
		if(i == s) ans += x != 0;
		else a[x]++;
	}
	
	int number = 1;	
	for(int i = 1; number < n; ++i)
		if(not a[i]) number += 1, ans += 1;
		else number += a[i];

	printf("%d\n", ans);

	return 0;
}
