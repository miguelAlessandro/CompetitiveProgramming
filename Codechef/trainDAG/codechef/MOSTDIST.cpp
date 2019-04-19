#include <bits/stdc++.h>
using namespace std;

struct Point {
	int x, y, id;
	Point(int x=0, int y=0, int id=0): x(x), y(y), id(id) {}
};
struct cmp1 {
	bool operator()(Point p, Point q) {
		return p.x + p.y < q.x + q.y;
	}
};
struct cmp2 {	
	bool operator()(Point p, Point q) {
		return p.x + p.y > q.x + q.y;
	}
};
struct cmp3 {
	bool operator()(Point p, Point q) {	
		return p.x - p.y < q.x - q.y;
	}
};
struct cmp4 {
	bool operator()(Point p, Point q) {
		return p.x - p.y > q.x - q.y;
	}
};
int abs(Point p, Point q) {
	return abs(p.x - q.x) + abs(p.y - q.y);
}
priority_queue<Point, vector<Point>, cmp1> pq1;
priority_queue<Point, vector<Point>, cmp2> pq2;
priority_queue<Point, vector<Point>, cmp3> pq3;
priority_queue<Point, vector<Point>, cmp4> pq4;
int m;
const int maxN = 5e5 + 10;
bool vis[maxN];

void clear() {
	while (not pq1.empty() and vis[pq1.top().id]) pq1.pop();
	while (not pq2.empty() and vis[pq2.top().id]) pq2.pop();
	while (not pq3.empty() and vis[pq3.top().id]) pq3.pop();
	while (not pq4.empty() and vis[pq4.top().id]) pq4.pop();
}

void add(int x, int y) {
	pq1.push({x, y, ++m});
	pq2.push({x, y, m});
	pq3.push({x, y, m});
	pq4.push({x, y, m});
}

void erase(int n) {
	vis[n] = 1;
}

int query(int x, int y) {
	clear();
	int ans = 0;
	Point p(x, y);
	ans = max(ans, abs(pq1.top(), p));
	ans = max(ans, abs(pq2.top(), p));
	ans = max(ans, abs(pq3.top(), p));
	ans = max(ans, abs(pq4.top(), p));
	return ans;
}

int main() {
	int q;
	scanf("%d\n", &q);
	int ans = 0;
	while (q--) {
		char type = getchar();
		if (type == '+') {
			int x, y;
			scanf("%d %d\n", &x, &y);
			x ^= ans;
			y ^= ans;
			add(x, y);
		} else if (type == '-') {
			int n;
			scanf("%d\n", &n);
			n ^= ans;
			erase(n);
		} else {
			int x, y;
			scanf("%d %d\n", &x, &y);
			x ^= ans;
			y ^= ans;
			ans = query(x, y);
			printf("%d\n", ans);
		}
	}
	return 0;
}
