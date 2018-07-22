#include <bits/stdc++.h>
using namespace std;
class LittleTree {

	public:
		vector<vector<int>> adj;
		int minCost(int N, vector<string> edges, int height) {
			
			adj.resize(N, vector<int>());
            
            string input = "";
            for (string& e : edges) {
                for (char& c : e)
                	if (c == ',') c = ' ';
                input += e;
            }
            
			stringstream ss(input);
			int u, v;
            while (ss >> u >> v) {
				adj[u].emplace_back(v);
			}
			return dfs(0, N, height);
		}

		int dp[102][102];
		int dfs (int x, int& n, int& height) {
			for (int v : adj[x])
				dfs(v, n, height);

			if (adj[x].empty()) {
				for (int h = 0; h < n; ++h)
					dp[x][h] = h > height;
			} else {
				for (int h = 0; h < n; ++h) {
					int& ans = dp[x][h] = 1000;
					if (h <= height) {
						int sum = 0;
						for (int v : adj[x])
							sum += dp[v][h+1];
						ans = min(ans, sum);
					}
					for (int i = 1; i < h; ++i)
						ans = min(ans, i + dp[x][h-i]);
				}
			}
			return dp[x][0];
		}
};
