#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e4 + 10;
int ten[] = {1000, 100, 10, 1};
vector<int> prime;
bool composite[maxN];
int t;

void sieve(int n = maxN) {
	for (int i = 2; i < n; ++i) {
		if (not composite[i]) {
			prime.push_back(i);
		}
		for (int p : prime) {
			if (p * i >= n) break;
			composite[p * i] = 1;
			if (i % p == 0) break;
		}
	}
}

bool vis[maxN];
int dist[maxN];

int bfs(int src, int snk) {
	queue<int> Q;
	memset(vis, 0, sizeof vis);
	Q.push(src);
	dist[src] = 0;
	vis[src] = 1;
	while (not Q.empty()) {
		int q = Q.front(); Q.pop();
		int f = q;
		for (int k = 3; k >= 0; --k) {
			int y = f%10;
			for (int d = -y + (k==0); d <= 9-y; ++d) {
				int nx = d * ten[k] + q;
				if (nx < 1000 or nx >= 10000) continue;
				if (composite[nx]) continue;
				if (vis[nx]) continue;
				vis[nx] = 1;
				dist[nx] = dist[q] + 1;
				Q.push(nx);
			}
			f /= 10;
		}
	}
	return vis[snk] ? dist[snk] : -1;
}

int main() {
	sieve();
	scanf("%d", &t);
	while (t--) {
		int src, snk;
		scanf("%d %d", &src, &snk);
		int dis = bfs(src, snk);
		if(dis == -1) puts("impossible");
		else printf("%d\n", dis);
	}
	return 0;
}
