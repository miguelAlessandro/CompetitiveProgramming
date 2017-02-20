#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int n;
int p[N];
int b[N];
bool vis[N];
int l, x;

int main(){

	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", p+i);
	for(int i = 0; i < n; ++i){
		scanf("%d", &b[i]);
		l += b[i];
	}

	int len = 0;
	for(int i = 1; i <= n; ++i)
		if(not vis[i]){
			vis[i] = true;
			x = p[i];

			while(not vis[x]){
				vis[x] = true;
				x = p[x];
			}
			len += 1;
		}
	
	if(len == 1) len = 0;	
	if(l%2 == 0) len += 1;

	printf("%d\n", len);


	return 0;
}
