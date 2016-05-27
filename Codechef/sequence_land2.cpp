#include <iostream>
#include <cstdio>
#include <queue>
#include <unordered_set>
using namespace std;

const int N = 305;
int n, k;
unordered_set<int> id[N];
bool vis[N];

bool proof(int a, int b){
	int r = 0;
	if(id[a].size() > id[b].size()) swap(a, b);
	for(unordered_set<int>::iterator it = id[a].begin(); it != id[a].end(); ++it)
		r += id[b].find(*it) != id[b].end(); 

	return r >= k;
}

int bfs(int x){
	int t = 1;
	vis[x] = true; 
	queue<int> Q; Q.push(x);
	while(not Q.empty()){
		int q = Q.front(); Q.pop();
		for(int i = 0; i < n; ++i)
			if(not vis[i] and proof(q, i)){
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
			id[i].insert(x);
		}
	}
	printf("%d\n", bfs(0));

	return 0;
}
