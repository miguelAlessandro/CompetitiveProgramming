#include <bits/stdc++.h>
using namespace std;

const int N = 20005;
int ft[N], pos[N];
int n, t, len, r, last;

void update(int x, const int v){
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

int ones(int r){
	if(r%len == 0) return len;
	return r%len;
}

int main(){

	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		len = n;
		for(int i = 1; i <= n; ++i)
			update(i, 1);
		
		r = 2, last = 0;
		for(int x, lo, hi, i = 1; i <= n; ++i, ++r, --len){
			x = query(last);
			if(len - x >= ones(r)){
				lo = last + 1; hi = n;
				while(lo < hi){
					int mid = (hi+lo)/2;
					if(query(mid) - x < ones(r)) lo = mid+1;
					else hi = mid;
				}
			}
			else{
				int sup = query(n) - x;
				lo = 1; hi = last-1;
				while(lo < hi){
					int mid = (hi+lo)/2;
					if(query(mid) < ones(r) - sup) lo = mid+1;
					else hi = mid;
				}
			}
			pos[lo] = i;
			update(lo, -1);
			last = lo;
		}
		for(int i = 1; i <= n; ++i)
			printf("%d%c", pos[i], i==n?'\n':' ');		
	}	
	
	return 0;
}
