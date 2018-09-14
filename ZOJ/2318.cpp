/**
 *  ZOJ 2318 - get out!
 *  hint1 : use shrink idea to convert boat in point. https://codeforces.com/blog/entry/11441
 *  hint2 : join intersect circles
 *  hint3 : use dfs and consider winding number http://geomalgorithms.com/a03-_inclusion.html
 */


#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e2 + 5;
const long double eps = 1e-8;

struct Point {
	long double x, y;
};
long double cross(Point p, Point q) {
	return p.x * q.y - p.y * q.x;
}

struct Circle 
{
	long double x, y, r;
	bool isIntersectWith(const Circle c) const {
		return hypot(x-c.x, y-c.y) + eps < r+c.r;
	}
	Point getCenter() {
		return {x, y};
	}
} island[MAXN];
Circle &boat = island[0];
int t, N;
vector<int> near[MAXN];
int considered[MAXN];
int winding[MAXN];

struct Winding_number_interface {
	Point O;
	void useCenter (Point O2) {O.x = O2.x, O.y = O2.y;}
	int operator()(Point a, Point b) {
		if (a.y-O.y <= eps){
			if (b.y-O.y > eps and cross({b.x - a.x, b.y - a.y}, {-a.x+O.x, -a.y+O.y}) > eps)
				return 1;
		} else if(b.y-O.y <= eps and cross({b.x - a.x, b.y - a.y}, {-a.x+O.x, -a.y+O.y}) < eps) {
			return -1;
		}
		return 0;
	}
} windingNumberCalculator;


enum {NO = 0, YES = 1, PENDING = 2};
bool dfs(int curIsland, int lastIsland = 0, int curWinding = 0) 
{
	considered[curIsland] = PENDING;
	winding[curIsland] = curWinding;
	bool pent = 0;
	for (int nxtIsland : near[curIsland]) {
		if (lastIsland == nxtIsland) {continue;}
		int nxtWindingNumber = windingNumberCalculator(
									island[curIsland].getCenter(),
									island[nxtIsland].getCenter()
								);
		if (not considered[nxtIsland]) 
		{
			pent |= dfs(
						nxtIsland, 
						curIsland, 
						curWinding + nxtWindingNumber
					);
		} else if (considered[nxtIsland] == PENDING) 
		{
			pent |= curWinding + nxtWindingNumber != winding[nxtIsland];
		}
	}
	considered[curIsland] = YES;
	return pent;
}


int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &N);	
		for (int i = 1; i <= N; ++i) {
			scanf("%Lf %Lf %Lf",
				&island[i].x,
				&island[i].y,
				&island[i].r
			);
		}
		scanf("%Lf %Lf %Lf",
			&boat.x,
			&boat.y,
			&boat.r
		);
		
		windingNumberCalculator
			.useCenter(boat.getCenter())
		;
		
		//shrink trick
		for (int i = 1; i <= N; ++i) {
			island[i].r += boat.r;
		}
		
		for (int i = 1; i <= N; ++i) {
			near[i].clear();
		}
		
		for (int i = 1; i <= N; ++i) {
			for (int j = i+1; j <= N; ++j) {
				if (island[i].isIntersectWith(island[j])) 
				{
					near[i].emplace_back(j);
					near[j].emplace_back(i);
				}
			}
		}
		
		bool pent = 0;
		memset(considered, 0, sizeof considered);
		memset(winding, 0, sizeof winding);
		for (int i = 1; i <= N; ++i) {
			if (not considered[i]) 
			{
				pent |= dfs(i);
			}
		}
		puts(pent ? "NO" : "YES");
		if (t) puts("");
	}	
	return 0;
}
