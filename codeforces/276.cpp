#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int a[N];
long long b[N];
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

	scanf("%d %d", &n, &q);
	bit.init(n);
	for(int i = 0; i < n; ++i)
		scanf("%d", a+i);

	sort(a, a+n, greater<int>());

	for(int x, y, i = 0; i < q; ++i){
		scanf("%d %d", &x, &y);
		bit.update(x, y, 1);
	}
	
	
	for(int i = 0; i < n; ++i)
		b[i] = bit.query(i+1) - bit.query(i);
	
	sort(b, b+n, greater<int>());

	long long r = 0;
	for(int i = 0; i < n; ++i)
		r += a[i]*b[i];		

	printf("%I64d\n", r);

	return 0;
}
