#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
struct point{
	int x, y, c;
	bool operator<(const point& q){
		return x < q.x or x == q.x and y < q.y;
	}
} P[N];
long long ansg;
int n, L, ansl;
long long ft[N];

void update(int y, long long v){
	while(y < N){
		ft[y] += v;
		y += y&(-y);
	}
}

long long query(int y){
	long long sum = 0;
	while(y > 0){
		sum += ft[y];
		y -= y&(-y);
	}
	return sum;
}

int main(){

	scanf("%d %d", &n, &L);
	for(int i = 0; i < n; ++i)	
		scanf("%d %d %d", &P[i].x, &P[i].y, &P[i].c);

	sort(P, P+n);	
	for(int i = 0; i < n; ++i)
		printf("%d %d %d\n", P[i].x, P[i].y, P[i].c);
	
	int l = 0, r = 0;	
	while(l < n){
		while(r < n and P[r].x-P[l].x+1 <= L){
			update(P[r].y, P[r].c);		
			int lo = max(P[r].y-L, 0), hi = P[r].y-1;
			long long back = query(lo);
			while(lo < hi){
				int mid = lo+(hi-lo+1)/2;
				if(query(mid) <= back) lo = mid;
				else hi = mid-1;
			}
			long long sol = query(P[r].y)-back;			
			if(sol > ansg){
				ansg = sol;
				ansl = max(P[r].x-P[l].x+1, P[r].y-lo);
			}
			else if(sol == ansg)
				ansl = min(ansl, max(P[r].x-P[l].x+1, P[r].y-lo));
			r++;
		}
		int base = l;
		while(l < n and P[l].x == P[base].x){		
			update(P[l].y, 0LL-P[l].c);
			l++;
		}
	}

	printf("%lld %d\n", ansg, ansl);

	return 0;
}
