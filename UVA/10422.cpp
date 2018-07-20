#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

typedef pair<int, int> ii;
int t;
string sol("111110111100 110000100000");
unordered_map<string, int> d;
const int dx[] = {2, 1, -1, -2, -2, -1, 1, 2},
		  dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

bool bfs(string s, int x, int y, int& r){
	queue<string> Q; Q.push(s);
	queue<ii> Q2; Q2.push(ii(x, y));
	d[s] = 0;
	while(not Q.empty()){
		string s1 = Q.front(); Q.pop();
		ii q = Q2.front(); Q2.pop();
		if(s1 == sol){ 
			r = d[sol];
			return true;
		}
		if(d[s1] > 10) return false;
		for(int i = 0; i < 8; ++i){
			int a = q.first+dx[i], b = q.second+dy[i];
			string s2 = s1;
			if(a >= 0 and a < 5 and b >= 0 and b < 5){
				s2[5*q.first+q.second] = s2[a*5 + b];  
				s2[a*5+b] = ' ';
				if(d.find(s2) == d.end()){
					d[s2] = d[s1] + 1;
					Q.push(s2);
					Q2.push(ii(a, b));
				}
			}
		}
	}
	return false;
}

string m;

int main(){

	scanf("%d%*c", &t);
	while(t--){
		d.clear();
		string s("");
		for(int i = 0; i < 5; ++i){
			getline(cin, m);
			for(int j = 0; j < 5; ++j)
				s.push_back(m[j]);		
		}
		int a, b;
		bool ok = true;
		for(int i = 0; i < 5 and ok; ++i)
			for(int j = 0; j < 5 and ok; ++j)
				if(s[i*5+j] == ' '){
					a = i; b = j;
					ok = false;	
				}		
		int r;	
		if(bfs(s, a, b, r))
			printf("Solvable in %d move(s).\n", r);
		else
			printf("Unsolvable in less than 11 move(s).\n");	
	}

	return 0;
}
