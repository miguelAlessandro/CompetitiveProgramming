#include <bits/stdc++.h>
using namespace std;

string f[] = {"abababab", "babababa", "acacacac", "cacacaca", "bcbcbcbc", "cbcbcbcb"};
string ff[] = {"bababab", "abababa", "cacacac", "acacaca", "cbcbcbc", "bcbcbcb"};
int t;
string s, p;

bool dfs(int pos){
	
	if(pos + 1 == p.size()) return s.size();
	if(pos+1 == s.size()) return false;

	if(p[pos] == s[pos]) return dfs(pos+1);
	else{
		if(s[pos-1] == 'a' and s[pos] == 'b'){
				p.erase(pos, 1);
				p.insert(pos, ff[0]);
		}
		if(s[pos-1] == 'b' and s[pos] == 'a'){
				p.erase(pos, 1);
				p.insert(pos, ff[1]);		
		}	
		if(s[pos-1] == 'a' and s[pos] == 'c'){
				p.erase(pos, 1);
				p.insert(pos, ff[2]);		
		}	
		if(s[pos-1] == 'c' and s[pos] == 'a'){
				p.erase(pos, 1);
				p.insert(pos, ff[3]);	
		}
		if(s[pos-1] == 'b' and s[pos] == 'c'){
				p.erase(pos, 1);
				p.insert(pos, ff[4]);		
		}
		if(s[pos-1] == 'c' and s[pos] == 'b'){
				p.erase(pos, 1);
				p.insert(pos, ff[5]);			
		}
		return dfs(pos+1);
	}
}

int main(){

	cin >> t;
	while(t--){
		cin >> s;
		p = "";
		bool ok = false;
		if(s.size() >= 8){ 
	
			if(s[0] == 'a' and s[1] == 'b')
				p.insert(0, f[0]);
			if(s[0] == 'b' and s[1] == 'a')
				p.insert(0, f[1]);			
			if(s[0] == 'a' and s[1] == 'c')
				p.insert(0, f[2]);			
			if(s[0] == 'c' and s[1] == 'a')		
				p.insert(0, f[3]);	
			if(s[0] == 'b' and s[1] == 'c')
				p.insert(0, f[4]);		
			if(s[0] == 'c' and s[1] == 'b')
				p.insert(0, f[5]);			
			
			if(dfs(2)) cout << "closed" << endl;
			else cout << "open" << endl;
		}
		else cout << "open" << endl;
	}

	return 0;
}
