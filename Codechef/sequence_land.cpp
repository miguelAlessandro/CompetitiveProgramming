#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

const int N = 305;
int n, k;
int id1[N], id2[N];
bool vis[N];

int bfs(int x){
	int t = 1;
	vis[x] = true; 
	queue<int> Q; Q.push(x);
	while(not Q.empty()){
		int q = Q.front(); Q.pop();
		for(int i = 0; i < n; ++i)
			if(not vis[i] and __builtin_popcount(id1[q]&id1[i]) + __builtin_popcount(id2[q]&id2[i]) >= k){
				vis[i] = true; 
				t = t + 1;
				Q.push(i);
			}
	}
	return t;
}


int main(){

	scanf("%d %d", &n, &k);
	for(int p, i = 0; i < n; ++i){
		scanf("%d", &p);
		for(int x, j = 0; j < p; ++j){
			scanf("%d", &x);
			if(x < 60) id1[i] |= (1ll<<x);
			else id2[i] |= (1ll<<(x-60));
		}
	}
	printf("%d\n", bfs(0));

	return 0;
}
