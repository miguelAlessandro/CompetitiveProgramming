#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int t, n, q;

class BIT{
	private:	
		long long ft_sum[N], ft_mul[N];
		int n;
	public:
		int init(const int m){
			n = m;
			memset(ft_sum, 0, sizeof ft_sum);
			memset(ft_mul, 0, sizeof ft_mul);
		}
		void update(int lo, int hi, long long v){
			update_range(lo, v, -v*(lo-1));
			update_range(hi, -v, v*hi);
		}
		void update_range(int x, long long mul, long long add){
			while(x <= n){
				ft_sum[x] += add;
				ft_mul[x] += mul;
				x += x&(-x);
			}
		}	
		long long query(int x){
			long long mul = 0;
			long long add = 0;
			int st = x;
			while(x > 0){
				mul += ft_mul[x];
				add += ft_sum[x];
				x -= x&(-x);
			}
			return mul*st + add;
		}
} bit;

int main(){

	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &q);
		bit.init(n);
		for(int d, a, b, c, i = 1; i <= q; ++i){
			scanf("%d", &d);
			if(d){
				scanf("%d %d", &a, &b);
				printf("%lld\n", bit.query(b) - bit.query(a-1));
			}
			else{
				scanf("%d %d %d", &a, &b, &c);
				bit.update(a, b, c);
			}
		}
	}

	return 0;
}
