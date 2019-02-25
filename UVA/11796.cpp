/**
 * UVA 11796 - Dog Distance
 * @author Miguel Miní
 * @tag geometry, shrink
 * @idea:
 *		- transform the problem to second person vision
 *		- you only need subtract second person velocity
 *		- O((A+B) x sqrt complexity)
 */


#include <bits/stdc++.h>
using namespace std;
typedef long double Real;
const int maxN = 55;
const long double eps = 1e-9;
struct Point {
	Real x, y;
	Point(Real x=0.L, Real y=0.L) : x(x), y(y) {}
	Point operator +(Point other) {return Point(x+other.x, y+other.y);}
	Point operator -(Point other) {return Point(x-other.x, y-other.y);}	
	Real operator *(Point other) {return x*other.x + y*other.y;}
	Real operator ^(Point other) {return x*other.y - y*other.x;}
	Point operator *(Real c) {return Point(c*x, c*y);}
	Point operator /(Real c) {return Point(x/c, y/c);}
	friend Real abs(Point p) {return p * p;}
	friend Real norm(Point p) {return sqrt(p * p);}
	friend Real dist(Point p, Point q) {return norm(p - q);}
} P[maxN], Q[maxN];
Real Tp[maxN], Tq[maxN];
int n, m;

struct Segment {
	Point a, ab;	
	Segment(Point a=Point(), Point b=Point(), bool twoPoints=1) : a(a), ab(twoPoints?b-a:b) {}
	Point b() {return a + ab;}
};

Real distanceS2P(Segment s, Point p) {
	if ((p - s.a) * s.ab <= 0) return dist(s.a, p);
	if ((p - s.b()) * s.ab >= 0) return dist(s.b(), p);
	return abs((p - s.a) ^ s.ab) / norm(s.ab);
}

int main() {
	int T;
	int nc = 1;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 0; i < n; ++i) {
			int x, y;
			cin >> x >> y;
			P[i] = Point(x, y);
		}
		for (int i = 0; i < m; ++i) {
			int x, y;
			cin >> x >> y;
			Q[i] = Point(x, y);
		}
		Real v1 = 0.L, v2 = 0.L;
		for (int i = 1; i < n; ++i) {
			v1 += dist(P[i-1], P[i]);
		}
		for (int i = 1; i < m; ++i) {
			v2 += dist(Q[i-1], Q[i]);
		}
		Tp[0] = Tq[0] = 0.L;
		for (int i = 1; i < n; ++i) {
			Tp[i] = Tp[i-1] + dist(P[i], P[i-1]) / v1;
		}
		for (int i = 1; i < m; ++i) {
			Tq[i] = Tq[i-1] + dist(Q[i], Q[i-1]) / v2;
		}
		vector<Segment> S;
		Point p0 = P[0];
		for (int i = 0, j = 0; i+1 < n and j+1 < m;) {
			Real time = min(Tp[i+1], Tq[j+1]) - Tp[i];
			Point w1 = (P[i+1] - P[i]) / dist(P[i], P[i+1]) * v1;
			Point w2 = (Q[j+1] - Q[j]) / dist(Q[j], Q[j+1]) * v2;
			Point p1 = p0 + (w1 - w2) * time;
			S.push_back(Segment(p0, p1));
			p0 = p1;
			if (abs(Tp[i+1] - Tq[j+1]) <= eps) {
				i += 1; j += 1;
			} else if (Tp[i+1] < Tq[j+1]) {
				Tq[j] = Tp[++i];
			} else {
				Tp[i] = Tq[++j];
			}
		}
		p0 = Q[0];
		Real maxDistance = -1e18, minDistance = 1e18;
		for (auto e : S) {
			minDistance = min(minDistance, distanceS2P(e, p0));
			maxDistance = max(maxDistance, max(dist(p0, e.a), dist(p0, e.b())));
		}
		cout << "Case " << nc++ << ": ";
		cout << (long long)(maxDistance - minDistance + 0.5) << endl;
	}
	return 0;
}
