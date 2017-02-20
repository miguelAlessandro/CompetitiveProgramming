#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

typedef pair<long long, pair<int, int> > iii;
const int N = 100003;
vector<int> graph[N];
int n, m, p, k, s, t;
int gangster[12];
int money[12];
int dis[12][N];
long long dis2[N];
bool vis[12][N];
queue<int> Q;
priority_queue<iii, vector<iii>, greater<iii> > pQ;


void bfs(int gi, int x){
	Q.push(x);
	dis[gi][x] = 0; vis[gi][x] = true;
	while(not Q.empty()){
		int q = Q.front(); Q.pop();	
		for(auto v : graph[q])
			if(not vis[gi][v]){
				vis[gi][v] = true;
				dis[gi][v] = dis[gi][q] + 1;
				Q.push(v);
			}
	}
}

long long dijkstra(int x = s){
	
	for(int i = 1; i <= n; ++i) dis2[i] = 1000000000000LL;
	int set = 0;
	long long ww = 0;
	for(int i = 0; i < p; ++i)
		if(dis[i][x] <= k){
			ww += money[i]; 
			set |= (1<<i);
		}

	pQ.push({ww, {x, set}});
	dis2[x] = ww;
	
	while(not pQ.empty()){
		iii q = pQ.top(); pQ.pop();
		int u = q.second.first;
		int ss = q.second.second;
		long long www = q.first;

		for(int v : graph[u]){

			int sss = 0;
			long long wwww = 0;
			for(int i = 0; i < p; ++i)
				if(dis[i][v] <= k and (~ss)&(1<<i)){
					sss |= (1<<i);
					wwww += money[i];
				}

			sss |= ss;

			int next = www + wwww;			
			if(next < dis2[v]){
				dis2[v] = next;
				pQ.push({next, {v, sss}});
			}
		}
	}

	return dis2[t];
}

int main(){

	scanf("%d %d %d %d", &n, &m, &p, &k);
	for(int i = 0; i < p; ++i)
		scanf("%d", gangster+i);
	for(int i = 0; i < p; ++i)
		scanf("%d", money+i);

	for(int x, y, i = 0; i < m; ++i){
		scanf("%d %d", &x, &y);
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	scanf("%d %d", &s, &t);

	for(int i = 0; i < p; ++i)
		bfs(i, gangster[i]);	
	
	printf("%lld\n", dijkstra(s));

	return 0;
}
