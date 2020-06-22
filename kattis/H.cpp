#include <bits/stdc++.h>
using namespace std;
const int maxN = 5005;
int n;
vector<int> g[maxN];

struct Point {
	long long x, y;
	Point():x(0), y(0) {}
	Point(long long x, long long y): x(x), y(y) {}
	Point operator -(Point other) {return Point(x-other.x, y-other.y);}
	long long operator ^ (Point other) {return x*other.y - y*other.x;}
	Point& operator =(Point other) {return x=other.x, y=other.y, *this;}
	bool operator ==(Point other) {return x==other.x and y==other.y;}
};

bool vis[maxN];
stack<int> p;
void dfs(int x) {
	vis[x] = 1;
	for (int v : g[x]) {
		if (not vis[v]) {
			dfs(v);
		}
	}
	p.push(x);
}

int main() {
	cin >> n;
	vector<pair<pair<Point, Point>, int>> d;
	for (int i = 1; i <= n; ++i) {
		int x_1, y_1, x_2, y_2;
		cin >> x_1 >> y_1 >> x_2 >> y_2;
		if (x_1 > x_2 or x_1 == x_2 and y_1 > y_2) {
			swap(y_1, y_2);
			swap(x_1, x_2);
		}
		d.push_back({{Point(x_1, y_1), Point(x_2, y_2)}, i});
	}
	typedef pair<pair<Point, Point>, int> iii;
	auto cmp = [](iii p, iii q)->bool {
		Point o = p.first.first;
		Point a = p.first.second;
		Point b = q.first.first;
		Point c = q.first.second;
		if (c.x < o.x or a.x < b.x) return 0;
		if (o.x == a.x and c.x == b.x) return o.y < b.y;
		if (o.x == a.x) return ((c-b)^(o-b)) < 0;
		if (c.x == b.x) return ((a-o)^(b-o)) > 0;
		if (o.x <= b.x and b.x <= a.x) return ((a-o)^(b-o)) >= 0;
		if (o.x <= c.x and c.x <= a.x) return ((a-o)^(c-o)) >= 0;
		if (b.x <= o.x and o.x <= c.x) return ((c-b)^(o-b)) < 0;
		if (b.x <= a.x and a.x <= c.x) return ((c-b)^(a-b)) < 0;
		return 0;
	};
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) if (i != j) {
			if (cmp(d[i-1], d[j-1])) g[i].push_back(j);	
		}
	}
	for (int i = 1; i <= n; ++i) if (not vis[i]) dfs(i);
	while (not p.empty()) {
		cout << p.top() << " ";
		p.pop();
	} cout << endl;
	return 0;
}
