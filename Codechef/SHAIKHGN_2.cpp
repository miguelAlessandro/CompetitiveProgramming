#include <bits/stdc++.h>
using namespace std;

const int N = 505;
int n, m, k, x;
int adj[N][N], p[N][N];
bool vis[N][N], s[N];
int d[N][N];
vector<int> cycle[N];
vector<int> r, z;
queue<int> Q;

int gcdex(int a, int b, int& x, int& y){
	if(b== 0){
		x = 1;
		y = 0;
		return a;
	}
	int x0, y0;
	int g = gcdex(b, a%b, x0, y0);
	x = y0;
	y = x0 - (a/b)*y0;
	return g;
}

void minc(int i, int j, int k){
	z.clear();
	for(int h = 0; h < cycle[i].size(); ++h) z.push_back(cycle[i][h]);
	for(int h = 0; h < cycle[j].size(); ++h) z.push_back(cycle[j][h]);
	for(int h = 0; h < cycle[k].size(); ++h) z.push_back(cycle[k][h]);
	sort(z.begin(), z.end());
	z.resize(unique(z.begin(), z.end()) - z.begin());
} 

int main(){

	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			scanf("%d", &adj[i][j]);

	for(int i = 0; i < n; ++i){
		Q.push(i);
		d[i][i] = 0; vis[i][i] = true;
		p[i][i] = i;
		while(not Q.empty()){
			int q = Q.front(); Q.pop();
			for(int j = 0; j < n; ++j)
				if(adj[q][j] and not vis[i][j]){
						vis[i][j] = true;
						p[i][j] = q;
						d[i][j] = d[i][q] + 1;
						Q.push(j);
					}
		}
	}

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j)
			if(adj[j][i] and vis[i][j])
				cycle[i].push_back(d[i][j]+1);
		sort(cycle[i].begin(), cycle[i].end());
		cycle[i].resize(unique(cycle[i].begin(), cycle[i].end()) - cycle[i].begin());
	}

	scanf("%d", &m);
	while(m--){
		scanf("%d %d", &k, &x);
		x--;
		memset(s, false, sizeof s);
		r.clear();
		for(int i = 0; i < n; ++i)
			if(vis[x][i])
				for(int j = 0; j < n; ++j)
					if(vis[i][j] and not s[j]){
						int dxij = d[x][i] + d[i][j];
						minc(x, i, j);
						if(z.size() == 0 and dxij == k) s[j] = true; 
						else if(z.size() == 1 and k >= dxij and (k-dxij)%z[0] == 0) s[j] = true;
						else if(z.size() >= 2 and k >= dxij){							
							int u, v, w;
							for(int ii = 0; ii < z.size() and not s[j]; ++ii)
								for(int jj = ii+1; jj < z.size() and not s[j]; ++jj){
									u = gcdex(z[ii], z[jj], v, w);
									//if(u == 1 and k - (z[ii]-1)*(z[jj]-1) >= dxij) s[j]	= true;				
									if(((dxij-k)*v + z[jj] - 1)/z[jj] <= ((k-dxij)*w)/z[ii]) s[j] = true;
								}
						}
						/*if(not s[j]){
							int pad = i;
							z.clear();
							for(int h = 0; h < cycle[x].size(); ++h) z.push_back(cycle[x][h]);
							while(pad != x){
								for(int h = 0; h < cycle[pad].size(); ++h) z.push_back(cycle[pad][h]);
								pad = p[x][pad];
							}
							pad = j;
							while(pad != i){	
								for(int h = 0; h < cycle[pad].size(); ++h) z.push_back(cycle[pad][h]);
								pad = p[i][pad];
							}
							sort(z.begin(), z.end());
							z.resize(unique(z.begin(), z.end()) - z.begin());
							if(z.size() == 0 and dxij == k) s[j] = true; 
							else if(z.size() == 1 and k >= dxij and (k-dxij)%z[0] == 0) s[j] = true;
							else if(z.size() >= 2 and k >= dxij){
								int u, v, w;
								for(int ii = 0; ii < z.size() and not s[j]; ++ii)
									for(int jj = ii+1; jj < z.size() and not s[j]; ++jj){
										u = gcdex(z[ii], z[jj], v, w);
										//if(u == 1 and k - (z[ii]-1)*(z[jj]-1) >= dxij) s[j]	= true;							
										if(((dxij-k)*v + z[jj] - 1)/z[jj] <= ((k-dxij)*w)/z[ii]) s[j] = true;
									}
							}
						}*/					
					}

		for(int i = 0; i < n; ++i)
			if(s[i]) r.push_back(i);
		int sol = r.size();
		printf("%d\n", sol);
		if(sol == 0) puts("-1");
		for(int i = 0; i < sol; ++i)
			printf("%d%c", r[i]+1,(i+1==sol)?'\n':' ');			 
	}

	return 0;
}
