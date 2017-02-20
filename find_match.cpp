const int N = 1005;
vector<int> adj[N];
int match[N];

bool dfs(int x){

	if(vis[v]) return false;
	vis[v] = true;

	for(int& v : adj[x])
		if(match[v] == -1 or dfs(match[u]))
			return match[v] = x, match[x] = v, true;

	return false;
}

int  Tdfs(){

	int ret = 0;
	memset(match, -1, sizeof match);	
	for(int i = 0; i < n; ++i)
		if(match[i] == -1){	
			memset(vis, false, sizeof vis);
			ret += find_match(i);
		}

	return ret;
}
