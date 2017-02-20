#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int t, n, h;
int a[N];


int main(){

	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &h);;
		for(int i = 0; i < n; ++i) scanf("%d", a+i);
		
		long long ul = h+1;
		int ans = 0;
		for(int x, i = 0; i < n; ++i){
			scanf("%d", &x);
			if(not x){
				ul += a[i];
				if(ul > h){
					ans++;
					ul = 1;
				}
				else if(i == n-1)  ans++;
			}
			else ul = 1;				
		}
		
		printf("%d\n", ans);
	}

	return 0;
}
