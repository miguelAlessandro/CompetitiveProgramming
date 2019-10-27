/**
 *	@name CEOI 2018 knights
 *	@author Miguel Mini
 *	@tag game theory, pattern finding
 *	@idea:
 *			- strategy:
 *				* the horses in a losing 
 *				position move them to 
 *				finish quickly.
 *
 *				dist(l) = max(1 + dist(w))
 *
 *				* the horses in a winning 
 *				position move them to 
 *				finish slowly to a losing 
 *				position
 *
 *				dist(w) = min(1 + dist(l))
 *
 *			- with this strategy if 
 *			a player has 
 *
 *			max(dist(w)) > max(dist(l))
 * 	
 *			in the next step the second
 *			player has
 *
 *			max(dist(l)) > max(dist(w))
 *
 *			in the case 
 *
 *			max(dist(l)) == max(dist(w))
 *
 *			only parity matters.
 *
 *		OBSERVATION:
 *			- the case of equal values
 *		 	in the contest is not scored.
 *
 * 	FIND THE PATTERNS!!!
 *		- be careful with the limits.
**/


#include <bits/stdc++.h>
using namespace std;

const int dx[] = {-2, -2, -1, 1};
const int dy[] = {-1, 1, -2, -2};
int n, m;

bool valid(int x, int y) {
	return min(x, y) >= 0 and max(x, y) < n;
}

//const int maxn = 1010;
//bool vis[maxn][maxn], memo[maxn][maxn];
bool win_lose(int x, int y) {
	/**
	if (vis[x][y]) return memo[x][y];
	vis[x][y] = 1;
	bool &win = memo[x][y] = 0;
	for (int k = 0; k < 4; ++k) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (not valid(nx, ny)) continue;
		win |= not win_lose(nx, ny);
	}**/
	if (x > y) swap(x, y);
	if (n%4 == 0 and x == n-1) return 0;
	if (n%4 == 1 and y == n-1 and x%2 == 0) return 0;  
	//assert(win == bool((x|y)&2));
	//return win;
	//**/
	return (x|y)&2;
}

//const int maxn = 1010;
//bool vis[maxn][maxn];
//int memo[maxn][maxn];
int dist(int x, int y) {
	/**
	if (vis[x][y]) return memo[x][y];
	vis[x][y] = 1;
	bool win = win_lose(x, y);
	int &d = memo[x][y] = win ? 0 : 1e9;
	//int &d = memo[x][y] = 1e9;
	for (int k = 0; k < 4; ++k) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (not valid(nx, ny)) continue;
		if (win and not win_lose(nx, ny)) {
			d = max(d, 1 + dist(nx, ny));
			//d = min(d, 1 + dist(nx, ny));
		}
		if (not win) {
			d = min(d, 1 + dist(nx, ny));
		}
	}
	if (d == 1e9) d = 0;
	}**/
	int add = 0;
	if (n%4 == 0) {
		if (y == n-1) y -= 1;
		if (x == n-1) x -= 1, add = 1;
	}
	if (n%4 == 1) {
		if (y == n-1) {
			if (x%4 == 3 and x!=n-2) return 0; 	
			if (x%4 == 2) x -= 1;
		}
	}
	int res = ((y + x) >> 1) + add;
	x &= 3; y &= 3; //x%4 y%4
	res += x*y==6; //(x=2 and y=3) or (x=3 and y=2) 
	res -= x*y==1 or x+y==4; // (x=1 and y=1) or x+y==4
	//assert(d == res);
	//return d;
	return res;
}

int main() {
	/**
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << setfill(' ') << setw(3) << dist(i, j);
		}
		cout << endl;
	}
	**/
	///**	
   cin >> m >> n;
	vector<pair<int, int>> P;
	int dw = 0, dl = 0;	
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		x -= 1; y -= 1;
		P.push_back({x, y});
		if (win_lose(x, y)) dw = max(dw, dist(x, y));
		else dl = max(dl, dist(x, y));
	}
	if (dw > dl or (dw == dl and dw%2 == 1)) {
		cout << "YES" << endl;
		for (int i = 0; i < m; ++i) {		
			int x = P[i].first, y = P[i].second;
			bool win = win_lose(x, y);
			int d = win ? -1e9 : 1e9;
			int tr;
			for (int k = 0; k < 4; ++k) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (not valid(nx, ny)) continue;
				if (win) {
					if (not win_lose(nx, ny)) {
						if (d < dist(nx, ny)) {
							d = dist(nx, ny);
							tr = k;
						}
					}
				} else {
					if (d > dist(nx, ny)) {
						d = dist(nx, ny);
						tr = k;
					}
				}
			}
			cout << x + 1 + dx[tr] << " " << y + 1 + dy[tr] << endl;
		}
	} else {
		cout << "NO" << endl;
	}
	//**/
	return 0;
}
