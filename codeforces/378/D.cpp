#include <bits/stdc++.h>
using namespace std;
	
const int N = 100002;
int n;
int t;
int X[N], Y[N], Z[N];
map<pair<int, int>, vector<pair<int, int> > > mp;


void insert(int x, int y, int z, int id){
	auto& it = mp[{x, y}];
	
	it.push_back({z, id});
	sort(it.rbegin(), it.rend());

	if(it.size() == 2 and it[0].second == it[1].second) it.pop_back();

	if(it.size() == 3){
		if(it[1].second == it[0].second) swap(it[1], it[2]);
		it.pop_back();
	}
}

int main(){

	scanf("%d", &n);
	
	int temp = 0, ans, ans2=0;
	for(int i = 0; i < n; ++i){
		scanf("%d %d %d", X+i, Y+i, Z+i);
		insert(X[i], Y[i], Z[i], i);
		insert(Y[i], X[i], Z[i], i);
		insert(Y[i], Z[i], X[i], i);
		insert(Z[i], Y[i], X[i], i);
		insert(X[i], Z[i], Y[i], i);
		insert(Z[i], X[i], Y[i], i);
		
		int r = min(X[i], min(Y[i], Z[i]));
		if(r > temp){
			temp = r;
			ans = i+1;
		}
	}

	for(auto it : mp)
		if(it.second.size() == 2 and it.second[0].second != it.second[1].second){
			int r = min(it.first.first, it.first.second);	
			r = min(r, it.second[0].first + it.second[1].first);

			if(r > temp){
				temp = r;
				ans = it.second[0].second+1;
				ans2 = it.second[1].second+1;
			}
		}	

	
	if(ans2 != 0) printf("2\n%d %d\n", ans, ans2);
	else printf("1\n%d\n", ans);

	return 0;
}
