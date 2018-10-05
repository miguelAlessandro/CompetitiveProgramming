/**
 *  UVA 588
 *  @problem: is possible use one camera to see a simple polygon (simplified art gallery problem)
 *  @solution: use cut polygon method for all edge (conserve left edge semiplane). 
 */


#include <bits/stdc++.h>
using namespace std;

const long double eps = 1e-8;
struct Point {
	double x, y;
	Point(double x = 0.d, double y = 0.d) : x(x), y(y) {}
	Point operator +(Point p) {return Point(x+p.x, y+p.y);}
	Point operator -(Point p) {return Point(x-p.x, y-p.y);}
	Point operator *(double c) {return Point(c*x, c*y);}
	Point operator /(double c) {return Point(x/c, y/c);}
	double operator *(Point p) {return x*p.x + y*p.y;}
	double operator ^(Point p) {return x*p.y - y*p.x;}
	friend Point operator *(double c, Point p) {return p * c;}
	friend Point operator /(double c, Point p) {return p / c;}
};

struct Line {
	Point a, ab;
	Line(Point _a, Point _b) : ab(_b-_a), a(_a) {}
	Point b() {return a + ab;}
};

bool intersect(Line l, Line r, Point& res) {
	double den = r.ab ^ l.ab;
	if (abs(den) <= eps) return 0;
	double t = (l.a - r.a) ^ l.ab;
	if (den < 0) den = -den, t = -t;
	return (-eps <= t and t <= den + eps) ? res = r.a + r.ab * t / den, 1 : 0; 
}

vector<Point> cutPoly(vector<Point> P, Line l) {
	
	vector<Point> Left;
	for (int i = 0; i < P.size(); ++i) {
		Point cur = P[i], nxt = P[(i+1) % (int) P.size()], res;
		if (intersect(l, Line(cur, nxt), res))	Left.emplace_back(res);
		if ((l.ab ^ (cur - l.a)) <= 0) Left.emplace_back(cur);
	}
	
	return Left;
}


int main() {
	int n, nc=1;
	while (scanf("%d", &n), n) {
		vector<Point> P;
		for (int i = 0; i < n; ++i) {
			int x, y;
			scanf("%d %d", &x, &y);
			P.emplace_back(x, y);
		}
		
		vector<Point> R = P;
		for (int i = 0; i < P.size(); ++i) {
			Point cur = P[i], nxt = P[(i+1)%(int)P.size()];
			R = cutPoly(R, Line(cur, nxt));
		}
		
		printf("Floor #%d\n", nc++);
		if (R.size() != 0) puts("Surveillance is possible.");
		else puts("Surveillance is impossible.");
		puts("");
	}
	
	return 0;
}
