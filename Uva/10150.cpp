#include <bits/stdc++.h>
using namespace std;

int t;
string x, y;
map<string, bool> vis;
map<string, string> p;
map< string, vector<string> > adj;

void bfs(string x, string y){
	queue<string> Q; Q.push(x);
	vis[x] = true;		
	while(not Q.empty()){
		string s = Q.front(); Q.pop();
		if(s==y) return;
		for(auto it : adj[s])
			if(not vis[it]){
				vis[it] = true;
				p[it] = s;
				Q.push(it);
			}	
	}
}

void path(string x, string y){
	if(x != y)
		path(x, p[y]);	
	cout << y << endl;
}

int main(){

	while(getline(cin, x), x[0] != '\0'){
		adj[x];
		for(auto& v : adj){
			int diff = 0;
			if(x.size() == v.first.size())
				for(int i = 0; i < x.size() and diff < 2; ++i)
					if(x[i] != v.first[i])	diff++;
			if(diff == 1) 
				v.second.push_back(x),
				adj[x].push_back(v.first);			
		}
	}
	int nc = 0;
	while(cin >> x >> y){
		p.clear();
		vis.clear();
		bfs(x, y);
		if(nc++) cout << endl;
		if(vis[y]) path(x, y);	
		else cout << "No solution." << endl;
	}	

	return 0;
}
