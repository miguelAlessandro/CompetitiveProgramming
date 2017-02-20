#include <bits/stdc++.h>
using namespace std;

int t;
string x, y;
map<string, int> d;
map< string, vector<string> > adj;

int bfs(string x, string y){
	queue<string> Q; Q.push(x);
	d[x] = 0;		
	while(not Q.empty()){
		string s = Q.front(); Q.pop();
		if(s==y) return d[s];
		for(auto it : adj[s])
			if(d.find(it) == d.end()){
				d[it] = d[s] + 1;
				Q.push(it);
			}	
	}
}


int main(){

	cin >> t;	
	while(t--){
		adj.clear();
		cin >> x;
		while(x != "*"){
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
			cin >>x;
		}
		getline(cin, x);
		getline(cin, x);
		while(x != ""){
			istringstream line(x);
			d.clear();
			line >> x >> y;
			cout << x << " " << y << " " << bfs(x, y) << endl;
			if(not getline(cin, x)) break;
		}	
		if(t) cout << '\n';
	}

	return 0;
}
