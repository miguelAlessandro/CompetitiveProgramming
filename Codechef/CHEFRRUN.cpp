#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int t, n;
int a[N];
bool vis[N];
int cat[N];

int main(){

	scanf("%d", &t);	
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i < n; ++i){
			scanf("%d", a+i);
			a[i]++;
		}

		for(int i = 0; i < n; ++i) vis[i] = false, cat[i]=0;

		for(int i = 0; i < n; ++i)
			if(not vis[i]){
				int x = i;
				while(not vis[x]){
					vis[x] = true;
					x = (x+a[x])%n;
				}
				
				if(cat[x] == 0){
					int y = x;
					cat[x] = 1;
					x = (x+a[x])%n;
					while(x != y){
						cat[x] = 1;
						x = (x+a[x])%n;
					}
				}
			
				int z = i;
				while(cat[z] == 0){
					cat[z] = 2;
					z = (z+a[z])%n;
				}
			}
		int r = 0;
		for(int i = 0; i < n; ++i)
			if(cat[i]==1) r++;

		printf("%d\n", r);
	}
	

	return 0;
}
