#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <climits>
using namespace std;

const int N = 200005;
int n, q, r;
int a, b, id[N];
int p[N];
bool vis[N];
vector< pair<int, int> > c;
vector<int> V[N];
int len;

int main(){

	scanf("%d", &n);

	for(int i = 0; i < n; ++i){
		scanf("%d %d", &a, &b);
		a--;
		V[a].push_back(b);
		if(not vis[a]){
			p[len++] = a;
			vis[a] = true;
		}
	}
	
	for(int i = 0; i < len; ++i)
		c.push_back({V[p[i]].back(), p[i]});

	sort(c.begin(), c.end());
	for(int i = 0; i < len; ++i)
		id[c[i].second] = i;

	vector<int> s, mini;
	scanf("%d", &q);
	for(int i = 0; i < q; ++i){
		scanf("%d", &r);

		s.clear();
		for(int x, j = 0; j < r; ++j){
			scanf("%d", &x);
			if(vis[x-1]) s.push_back(id[x-1]);
		}

		sort(s.begin(), s.end());
		
		mini.clear();

		if(not s.empty()){
			if(s[0] >= 2) mini.push_back(s[0] - 2);
			if(s[0] >= 1) mini.push_back(s[0] - 1); 
		
			for(int j = 0; j+1 < s.size(); ++j){
				if(s[j+1] - s[j] >= 3) mini.push_back(s[j+1] - 2);
				if(s[j+1] - s[j] >= 2) mini.push_back(s[j+1] - 1); 
			}

			if(len - 1 - s.back() >= 2) mini.push_back(len-2);
			if(len - 1 - s.back() >= 1) mini.push_back(len-1);
		}
		else{
			if(len >= 2) mini.push_back(len-2);
			if(len >= 1) mini.push_back(len-1);
		}

		if(mini.empty()) puts("0 0");
		else if(mini.size() == 1) printf("%d %d\n", c[mini[0]].second + 1, V[c[mini[0]].second][0]);		
		else{
			int l = mini.size();
			int idx = c[mini[l-1]].second;
			int idy = c[mini[l-2]].second;
			int w = c[mini[l-2]].first;
			int lo = 0, hi = int(V[idx].size()) - 1;
			while(lo < hi){
				int mid = lo + (hi - lo)/2;
				if(V[idx][mid] <= w) lo = mid+1;
				else hi = mid;
			}
			printf("%d %d\n", idx+1, V[idx][lo]);
		}
	}

	return 0;
}
