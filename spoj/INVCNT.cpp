#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

vector<int> a, b; 
int n, t;

class BIT{
	private:
		int ft[N];
		int n;
	public:
		void init(const int m){
			n = m;
			memset(ft, 0, sizeof ft);
		}
		
		void update(int x, const int v = 1){
			while(x <= n){
				ft[x] += v;
				x += x&(-x);
			}
		}
			
		int query(int x){
			int sum = 0;
			while(x > 0){
				sum += ft[x];
				x -= x&(-x);		
			}
			return sum;
		}		
} bit;


int main(){

	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		bit.init(n); a.resize(n);
		for(int i = 0; i < n; ++i)
			scanf("%d", &a[i]);	

		b = a;	
		sort(b.begin(), b.end());
	
		long long ninv = n*1LL*(n-1)/2;
		for(int i = 0; i < n; ++i){
			int lo = 0, hi = n-1;
			while(lo < hi){
				int mid = lo + (hi-lo+1)/2;
				if(b[mid] <= a[i]) lo = mid;
				else hi = mid-1;
			}
			ninv -= bit.query(lo+1);
			bit.update(lo+1);			
		}
		printf("%lld\n", ninv);
	}
	return 0;
}
