/**
 *	@name ruka
 *	@author Miguel Mini
 *	@tag fenwick_tree
 *	@idea
 *		- divide the positions into
 *		[0, cur_position) and [cur_position, n] 
 * 		solve queries in the first range with
 *		naive algorithm. to second range maintain
 *		every transition range [sum, sum + x[pos]]
 *		in a fenwick tree and if we need change the
 *		cur_position change system reference with
 *		the vector in the form system_reference += 
 *		vector[cur_position] - new_vector.
 *
 *		note: the axis is independent.	
 *
 *		O((n + q) log(1e8)) with unordered_map.
 */

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
const int maxn = 1e5 + 10;
const int maxS = 2e8 + 10; 
int axis_x = maxS/2, axis_y = maxS/2;
int n, q;
unordered_map<int, int> ft[2];
int x[maxn], y[maxn];
stack<int> Qx, Qy;
int left_ans;

void update(int t, int pos, int v) {
	pos += maxS/2;
	while (pos < maxS) {
		ft[t][pos] += v;
		pos += pos&-pos;
	}
}

int query(int t, int pos) {
	pos += t == 0 ? axis_x : axis_y;;
	int ans = 0;
	while (pos > 0) {
		ans += ft[t][pos];
		pos -= pos&-pos;
	}
	return ans;
}

void add_x(int l, int r) {
	if (l > r) swap(l, r);
	Qx.push(l); Qx.push(r);
	update(0, r+1, -1);
	update(0, l, 1);	
}

void add_y(int l, int r) {
	if (l > r) swap(l, r);
	Qy.push(l); Qy.push(r);
	update(1, r+1, -1);
	update(1, l, 1);
}

void remove_x() {
	int l = Qx.top(); Qx.pop();
	int r = Qx.top(); Qx.pop();
	if (l > r) swap(l, r);
	update(0, r+1, 1);
	update(0, l, -1);
}

void remove_y() {
	int l = Qy.top(); Qy.pop();
	int r = Qy.top(); Qy.pop();
	if (l > r) swap(l, r);
	update(1, r+1, 1);
	update(1, l, -1);
}

int sum_left_x, sum_left_y;
int sum_right_x, sum_right_y;
int cur_position;
void setup(int x[], int y[]) {
	sum_left_x = 1; sum_left_y = 1;
	sum_right_x = accumulate(x, x+n+1, 0);
	sum_right_y = accumulate(y, y+n+1, 0);
	for (int i = n; i >= 1; --i) {
		add_x(sum_right_x, sum_right_x - x[i]);
		add_y(sum_right_y, sum_right_y - y[i]);
		sum_right_x -= x[i]; sum_right_y -= y[i];
	}
	cur_position = 1;
}

void next_position() {
	remove_x();
	if ((sum_left_x^(sum_left_x + x[cur_position])) < 0) {
		left_ans += 1;
	}
	sum_left_x += x[cur_position];
	sum_right_x += x[cur_position];
	remove_y();
	if ((sum_left_y^(sum_left_y + y[cur_position])) < 0) {
		left_ans += 1;
	}
	sum_left_y += y[cur_position];
	sum_right_y += y[cur_position];
	cur_position += 1;
}

void prev_position() {	
	cur_position -= 1;		
	add_x(sum_right_x, sum_right_x - x[cur_position]);
	if ((sum_left_x ^ (sum_left_x - x[cur_position])) < 0) {
		left_ans -= 1;
	}
	sum_left_x -= x[cur_position];
	sum_right_x -= x[cur_position];
	add_y(sum_right_y, sum_right_y - y[cur_position]);
	if ((sum_left_y ^ (sum_left_y - y[cur_position])) < 0) {
		left_ans -= 1;
	}
	sum_left_y -= y[cur_position];
	sum_right_y -= y[cur_position];
}

void make_change(int _x, int _y) {
	remove_x();
	sum_right_x += x[cur_position];
	add_x(sum_right_x, sum_right_x - _x);
	sum_right_x -= _x;
	axis_x += x[cur_position] - _x;
	x[cur_position] = _x;
	remove_y();
	sum_right_y += y[cur_position];
	add_y(sum_right_y, sum_right_y - _y);
	sum_right_y -= _y;
	axis_y += y[cur_position] - _y;
	y[cur_position] = _y;
}	

int response() {
	return query(0, 0) + query(1, 0) + left_ans;	
}

int main() {
	cin >> n;
	x[0] = y[0] = 1;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i];
	}
	setup(x, y);
	cin >> q; cin.get();
	while (q--) {
		int type = cin.get();
		if (type == 'Q') {
			cout << response() << endl;
		} else if (type == 'F') {
			if (cur_position < n) {	
				next_position();
			}
		} else if (type == 'B') {
			if (cur_position > 1) {
				prev_position();
			}
		} else {
			int x, y;
			cin >> x >> y;
			make_change(x, y);
		}
		cin.get();
	}
	return 0;
}
