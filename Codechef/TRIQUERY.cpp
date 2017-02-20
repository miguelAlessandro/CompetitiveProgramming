#include <bits/stdc++.h>
using namespace std;

const int N = 100001;
int ft[3][3*N], ans[2*N];
int n, q;
struct point{
	int x, y, d, id;
	point() {}
	point(int xx, int yy, int dd) : x(xx), y(yy), d(dd) {}
} Q[2*N], P[3*N];


void update(int x, int y, int v){
	while(y < 3*N){
		ft[x][y] += v;
		y += y&(-y);
	}
}

int query(int x, int y){
	int sum = 0;
	while(y > 0){
		sum += ft[x][y];
		y -= y&(-y);
	}
	return sum;
}

bool comp1(const point& p, const point& q){
	return p.x < q.x or p.x == q.x and p.y < q.y;
}

bool comp2(const point& p, const point& q){
	return p.x + p.y + p.d < q.x + q.y + q.d;
}

int main(){

	scanf("%d %d", &n, &q);		
	
	for(int i = 0; i < n; ++i){
		scanf("%d %d", &P[i].x, &P[i].y);	
		P[i].d = 0;
	}
	for(int i = 0; i < q; ++i){
		scanf("%d %d %d", &Q[i].x, &Q[i].y, &Q[i].d);
		Q[i].id = i;
	}

	sort(P, P+n, comp1);
	sort(Q, Q+q, comp1);	
	
	for(int i = 0, j = 0; i < q; ++i){
		for(; j < n; ++j)
			if(P[j].x >= Q[i].x) break;	
			else update(0, P[j].y, 1);			
		ans[Q[i].id] = query(0, Q[i].y-1); 
	}

	sort(P, P+n, comp2);
	sort(Q, Q+q, comp2);
	
	for(int i = 0, j = 0; i < q; ++i){
		for(; j < n; ++j)
			if(P[j].x + P[j].y > Q[i].x + Q[i].y + Q[i].d) break;
			else{
				update(1, P[j].x, 1);
				update(2, P[j].y, 1);
			}
		ans[Q[i].id] += j - query(1, Q[i].x-1) - query(2, Q[i].y-1);
	}	

	for(int i = 0; i < q; ++i)
		printf("%d\n", ans[i]);			

	return 0;
}
