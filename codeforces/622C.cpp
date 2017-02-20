#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

class segment_tree{
	private:
		static const int N = 300005;
		pair<ii, ii> st[N<<1];//segment tree
		int ID;//identity
		function F;//operation (associative, conmutative)
	public:
		segment_tree(int id): ID(id){}//ID=0 for default
	
		ii build(int l, int r, int root, int a[]){//build segment tree
			if(l > r) return ii(-1, ID);
			if(l == r) return st[root] = pair<ii, ii>(ii(l, a[l]), ii(l, a[l]));
			int mid = l + (r-l)/2;
			ii left = build(l, mid, (root<<1)+1, a);
			ii right = build(mid+1, r, root+1<<1, a);
			if((F)(left.second, right.second)) return st[root] = left;
			else return st[root] = right;
		}			
		ii query(int lo, int hi, int l, int r, int root){
			if(r < l or hi < l or r < lo) return ii(-1, ID);
			if(lo <= l and r <= hi) return st[root];		
			int mid = l + (r-l)/2;
			ii left = query(lo, hi, l, mid, (root<<1)+1);
			ii right = query(lo, hi, mid+1, r, root+1<<1);
			if((F)(left.second, right.second)) return left;
			else return right;
		}
};

struct f1{ //functor
	bool operator()(int a, int b){
		return a < b;
	}
};

struct f2{
	bool operator()(int a, int b){
		return a > b;
	}
};


int a[200005];
int n, m;

int main(){
	segment_tree<f1> T1(INT_MAX);
	segment_tree<f2> T2(INT_MIN);
	cin >> n >> m;
	for(int i = 0; i < n; ++i)
		cin >> a[i];

	T1.build(0, n-1, 0, a);
	T2.build(0, n-1, 0, a);
	
	int l, r, x;
	ii mini, maxi;
	while(m--){
		cin >> l >> r >> x;
		l-=1;
		r-=1;
		mini = T1.query(l, r, 0, n-1, 0);
		maxi = T2.query(l, r, 0, n-1, 0);

		if(maxi.second == x){
			if(mini.second != x) cout << mini.first+1 << endl;
			else cout << -1 << endl;
		}	
		else cout << maxi.first+1 << endl;	
	}	

	return 0;
}
