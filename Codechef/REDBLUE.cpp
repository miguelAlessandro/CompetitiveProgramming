/**
 *	@name Red and blue points
 *	@author Miguel Mini	
 *	@tag radial_sweep
 *	@idea
 *		- direct aplication of
 *		radial sweep
 *		- note my sort :o (proyective order)
 */	

#include <bits/stdc++.h>
using namespace std;
int n, m;
const int maxn = 2010;
struct Point {
	int x, y, w;
	Point(int x=0, int y=0, int w=0):
		x(x), y(y), w(w) {}	
	Point operator -(Point other) {
		return Point(x-other.x, y-other.y, w);
	}
	long long operator ^(Point other) {
		return x*1ll*other.y - y*1ll*other.x;
	}
} p[maxn];

bool isAbove(Point p) {
	return (p.y > 0) or (p.y == 0 and p.x > 0);
}

bool cmp(Point p, Point q) {
	return (isAbove(p)==isAbove(q)) ^ ((p ^ q)>0);
}

int solve(vector<Point> p) {
	sort(p.begin(), p.end(), cmp);
	int cnt[2][2];
	memset(cnt, 0, sizeof cnt);
	for (auto e : p) {
		cnt[isAbove(e)][e.w] += 1;
	}
	int ans = min(cnt[0][0] + cnt[1][1], cnt[0][1] + cnt[1][0]);
	for (auto e : p) {
		cnt[isAbove(e)][e.w] -= 1;
		cnt[!isAbove(e)][e.w] += 1;
		ans = min(ans, cnt[0][0] + cnt[1][1]);
		ans = min(ans, cnt[0][1] + cnt[1][0]);
	}
	return ans;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; ++i) {
			cin >> p[i].x >> p[i].y;
			p[i].w = 1;
		}
		for (int i = 0; i < m; ++i) {	
			cin >> p[n+i].x >> p[n+i].y;
			p[n+i].w = 0;
		}
		int ans = 1e9;
		for (int i = 0; i < n+m; ++i) {
			vector<Point> to_solve;			
			for (int j = 0; j < n+m; ++j) {
				if (p[i].x == p[j].x and p[i].y == p[j].y) continue;
				to_solve.push_back(p[j] - p[i]);
			}
			ans = min(ans, solve(to_solve));
		}
		cout << ans << endl;
	}
	return 0;
}
