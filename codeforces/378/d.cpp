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
		
	if(it.size() == 3) it.pop_back();
}

int query(int id, int x, int y, int z){
	int r = min(x, y);
	t = -1;
	auto it = mp[{x, y}];
	int nz = z;	
	for(auto v : it)
		if(id != v.second and nz > z+v.first){
				nz = z + v.first;
				t = v.second;
			}

	return min(nz, r);
}

int main(){

	scanf("%d", &n);
	
	int temp = 0, ans, ans2;
	for(int i = 0; i < n; ++i){
		scanf("%d %d %d", X+i, Y+i, Z+i);
		insert(X[i], Y[i], Z[i], i);
		insert(Y[i], Z[i], X[i], i);
		insert(X[i], Z[i], Y[i], i);
		
		int r = min(X[i], min(Y[i], Z[i]));
		if(r > temp){
			temp = r;
			ans = i+1;
		}
	}

	
	for(int i = 0; i < n; ++i){
		int ww = 0;
				

		int a1 = query(i, X[i], Y[i], Z[i]);
		int t1 = t;
		int a2 = query(i, Y[i], X[i], Z[i]);
		int t2 = t;
		int a3 = query(i, X[i], Z[i], Y[i]);
		int t3 = t;
		int a4 = query(i, Z[i], X[i], Y[i]);
		int t4 = t;
		int a5 = query(i, Y[i], Z[i], X[i]);
		int t5 = t;
		int a6 = query(i, Z[i], Y[i], X[i]);
		int t6 = t;

		if(a1 >= temp and t1+1){
			temp = a1;
			ans = i+1, ans2 = t1+1;
		}
		if(a2 >= temp and t2+1){
            temp = a2;
            ans = i+1, ans2 = t2+1;
        }
		if(a3 >= temp and t3+1){
            temp = a3;
            ans = i+1, ans2 = t3+1;
        }
		if(a4 >= temp and t4+1){
            temp = a4;
            ans = i+1, ans2 = t4+1;
        }
		if(a5 >= temp and t5+1){
            temp = a5;
            ans = i+1, ans2 = t5+1;
        }
		if(a6 >= temp and t6+1){
            temp = a6;
            ans = i+1, ans2 = t6+1;
        }
	}
	
	if(ans2 != 0) printf("2\n%d %d\n", ans, ans2);
	else printf("1\n%d\n", ans);

	return 0;
}
