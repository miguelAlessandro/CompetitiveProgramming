/**
 *	@name Malaysian Computing Olympiad 2016 D Acorn
 *	@author Miguel Mini
 *	@tag convex_hull_trick
 *	@idea
 *		- If x < min(a_i) then, the 
 *		answer is the element with
 *		max(b_i) and lower a_i. This 
 *		element is the maximum in
 *		the infinity, so that dont 
 * 	consider x < min(a_i).
 *
 *		- we can build upper hull
 *		of dual lines (convex hull trick
 *		style) and note that a point
 *		a1=0, b1=999 and a2=1000, b2=1000 
 *		is a corner case with distinct 
 *		values in x ~ 10^6. 
 *
 *		complexity with monotone convex
 *		hull trick: O(n + 10000000)
 *		note that we can build cht in O(1000)		
 *
 *		we can reduce this deleting every
 *		line with maximum < 0 in convex hull 
 *		and verify if action range of a line
 *		contains a integer element. O(n + 1000)
 *
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
int B[maxn];
bool vis[maxn * maxn];
typedef long long llong;
struct Point {
	llong x, y;
	int id;
	Point(llong x=0, llong y=0, int id=0):x(x),y(y),id(id) {}
	Point operator -(Point other) {
		return Point(x - other.x, y - other.y);
	}
};

llong ccw(Point p, Point q) {
	return p.x * q.y - p.y * q.x;
}

llong dot(Point p, Point q) {
	return p.x * q.x + p.y * q.y;
}

int decr = 0;
struct ConvexHull {
	deque<Point> at;
	void add(Point p) {
		int n = at.size();
		while (n >= 2 and ccw(at[n-1]-at[n-2], p-at[n-2]) >= 0) {
			n -= 1;
		}
		at.resize(n);
		at.push_back(p);
	}
	void query(int x) {
		Point t(x, 1);
		while (at.size() > 1 and dot(t, at[0]) <= dot(t, at[1])) {
			at.pop_front();
		}
		if (dot(t, at[0]) < 0) return;
		if (not vis[at[0].id]) decr += 1;
		vis[at[0].id] = 1;
	}
} cht;

int main() {
	int n;
	cin >> n;
	memset(B, 1, sizeof B);
	for (int i = 1; i <= n; ++i) {
		int a, b;
		cin >> a >> b;
		B[b] = min(B[b], a);
	}
	for (int b = 1; b <= 1000; ++b) {
		if (B[b] > 1000) continue;
		cht.add(Point(b, -B[b]*b, b));
	}
	for (int i = 0; i <= 1000000; ++i) {
		cht.query(i);
	}
	cout << n - decr << endl;
	return 0;
}

