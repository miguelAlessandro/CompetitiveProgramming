#include <bits/stdc++.h>
using namespace std;

string x, y;
map<string, int> d;
map<string, string> p;
map< string, vector<string> > adj;

void bfs(string x, string y){
	queue<string> Q; Q.push(x);
	d[x] = 0;		
	while(not Q.empty()){
		string s = Q.front(); Q.pop();
		if(s==y) return;
		for(auto it : adj[s])
			if(d.find(it) == d.end()){
				p[it] = s;
				d[it] = d[s] + 1;
				Q.push(it);
			}	
	}
}

int n;
string a1, a2;


void path(string x, string y){

	if(x != y) path(x, p[y]);
	cout << y << endl;
}

int main(){

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n;	
	for(int i = 0; i < n; ++i){
		cin >> x;
		if(i==0) a1 = x;
		if(i==n-1) a2 = x;
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
		bfs(a1, a2);

	if(d.find(a2) != d.end()){
		cout << d[a2]+1 << endl;
		path(a1, a2);		
	}
	else
		cout << "FAIL" << endl;	

	return 0;
}
