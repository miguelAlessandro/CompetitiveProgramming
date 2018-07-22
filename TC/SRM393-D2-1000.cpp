class PowerAdapters {

	public:
	
		std::vector<int> adj[120];
		bool comp[120][120];
		int Set[120];
		int n, t;

		int needed(std::vector<string> adapters, std::vector<string> itinerary, std::string homeCountry) {
			using namespace std;
			map<string, int> id;
			t = 0;
			id[homeCountry] = t++; 

			for (string it : itinerary) {
				if (not id.count(it))
					id[it] = t++;
			}

			memset(comp, 0, sizeof comp);
 
			for (string line : adapters) {

				string s1, s2;
				istringstream(line) >> s1 >> s2;
				if (not id.count(s1)) 
						id[s1] = t++;
				if (not id.count(s2))
						id[s2] = t++;
				
				adj[id[s1]].emplace_back(id[s2]);
			}

			for (int i = 0; i < t; ++i)	dfs(i, i);

			memset(Set, 0, sizeof Set);
			n = itinerary.size();
			for (int j = 0; j < itinerary.size(); ++j)
				for (int i = 0; i < t; ++i)
					if (comp[i][id[itinerary[j]]]) 
						Set[i] |= (1<<j);
			
			return backtrack(1, Set[0]);
		} 
	
		bool vis[120][1<<17];
		int memo[120][1<<17];
		int backtrack(int pos, int mask) {
			if (pos == t) return mask+1 == (1<<n) ? 0 : 1e5;
			if (vis[pos][mask]) return memo[pos][mask];
			vis[pos][mask] = 1;
			return memo[pos][mask] = min(backtrack(pos+1, mask), 1 + backtrack(pos+1, mask | Set[pos]));
		}

		void dfs (int root, int x) {
			comp[root][x] = 1;
			for (int v : adj[x])
				if (not comp[root][v])
					dfs(root, v);
		}
};
