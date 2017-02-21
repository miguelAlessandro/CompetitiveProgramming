#include <bits/stdc++.h>
using namespace std;

template <class T, class function>
class segment_tree{
	private:
		static const int N = 131072;
		T st[N<<1];//segment tree
		T ID;//identity
		function F;//operation (associative, conmutative)
	public:
		segment_tree(int id = 0): ID(id){}//ID=0 for default
	
		T build(int l, int r, int root, T a[]){//build segment tree
			if(l > r) return ID;
			if(l == r) return st[root] = a[l];
			int mid = l + (r-l)/2;
			T left = build(l, mid, (root<<1)+1, a);
			T right = build(mid+1, r, root+1<<1, a);
			return st[root] = (F)(left, right);
		}			
		T query(int lo, int hi, int l, int r, int root){
			if(r < l or hi < l or r < lo) return ID;
			if(lo <= l and r <= hi) return st[root];		
			int mid = l + (r-l)/2;
			T left = query(lo, hi, l, mid, (root<<1)+1);
			T right = query(lo, hi, mid+1, r, root+1<<1);
			return (F)(left, right);	
		}
		T update(int uin, T v, int l, int r, int root){
			if(uin < l or uin > r or r < l) return ID;
			if(l==r) return st[root] += v;
			int mid = l + (r-l)/2;
			T left = update(uin, v, l, mid, (root<<1)+1);
			T right = update(uin, v, mid+1, r, root+1<<1);
			st[root] = (F)(left, right);
		}
};

struct gcd{ //functor
	int operator()(int a, int b){
		if(b==0) return a;	
		return operator()(b, a%b);
	}
};

const int N = 100005;
int a[N], n;

int main(){

	segment_tree<int, gcd> T;
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> a[i];
	T.build(0, n-1, 0, a);	

	int q, x, y;
	while(true){
		cin >> q >> x >> y;
		if(q==1) T.update(x-1, y, 0, n-1, 0);//a[x] to a[x]+y 	
		else cout<<T.query(x, y, 0, n-1, 0)<<endl;//gcd(a[x],...,a[y])
	}	

	return 0;
}
