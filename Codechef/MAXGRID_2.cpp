#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
long long ft[N][N];
int n, l;

void update(int x, int y, long long v){
	while(x < N){	
		int y2 = y;
		while(y2 < N){
			ft[x][y2] += v;
			y2 += y2&(-y2);
		}
		x += x&(-x);
	}
}

long long query(int x, int y){
	long long sum = 0;
	if(x >= N or y >= N) x = N-1, y = N-1;
	while(x > 0){ 
		int y2 = y;	
		while(y2 > 0){
			sum += ft[x][y2];
			y2 -= y2&(-y2);
		}
		x -= x&(-x);
	}
	return sum;
}

int main(){

	scanf("%d %d", &n, &l);
	for(int x, y, z, i = 0; i < n; ++i){
		scanf("%d %d %d", &x, &y, &z);
		update(x, y, z);
	}

	long long ans = 0;
	int id;
	for(int i = 1; i < N; ++i)
		for(int j = 1; j < N; ++j){
			long long uu = query(i+l-1, j+l-1), ul = query(i-1, j+l-1);
			long long lu = query(i+l-1, j-1), ll = query(i-1, j-1); 	
			if(uu - lu - ul + ll >= ans){
				int l1, l2;
				int lo = j-1, hi = j+l-1;
				while(lo < hi){
					int mid = lo + (hi-lo+1)/2;
					if(query(i+l-1, mid) - query(i-1, mid) <= uu - ul) lo = mid;
					else hi = mid-1;
				}
				l1 = lo-j+1;
				lo = i-1, hi = i+l-1;				
				while(lo < hi){
					int mid = lo + (hi-lo+1)/2;
					if(query(mid, j+l1-1) - query(mid, j-1) <= lu - ll) lo = mid;
					else hi = mid-1;
				}
				l2 = lo-i+1;
				if(ans < uu-lu-ul+ll){
					ans = uu-lu-ul+ll;
					id = max(l1, l2);
				}
				else id = min(id, max(l1, l2));
			}
		}
	printf("%lld %d\n", ans, id);

	return 0;
}
