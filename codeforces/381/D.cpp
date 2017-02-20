#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
vector<int> control;
long long a[N];
long long dis[N];
vector<pair<int, long long>> adj[N];
int n, ans[N];

class BIT{
    private:    
        long long ft_sum[N], ft_mul[N];
        int n;
    public: 
        int init(const int m){n = m;}
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

void dfs(int x, int p, int w){
	if(p) dis[x] = dis[p] + w;

	int len = control.size();
	if(len){
		int lo = 0, hi = len-1; 
		while(lo < hi){
			int mid = lo + (hi-lo)/2;	
			if(dis[x] - dis[control[mid]] <= a[x]) hi = mid;
			else lo = mid+1;
		}
		if(dis[x] - dis[control[lo]] <= a[x]) bit.update(lo+1, len, 1);
	}

	control.push_back(x);
	
	for(auto v : adj[x])
		if(v.first != p)
			dfs(v.first, x, v.second);
	
	ans[x] = bit.query(len+1) - bit.query(len);
	bit.update(len+1, len+1, -ans[x]);
	
	control.pop_back();
}

int main(){

	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%lld", a+i);
	int x;
	long long y;
	for(int i = 1; i <= n-1; ++i){
		scanf("%d %lld", &x, &y);
		adj[i+1].push_back({x, y});
		adj[x].push_back({i+1, y});
	}
	bit.init(n);
	
	dfs(1, 0, 0);
	for(int i = 1; i <= n; ++i)
		printf("%d ", ans[i]);
	puts("");

	return 0;
}
