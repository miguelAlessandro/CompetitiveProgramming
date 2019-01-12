/**
 *  Polyline SRM 244 div1 500
 *  @author Miguel Mini
 *  -------------------------
 *  @tags geometry, optic
 *  @idea
 *        - the minimum distance going through a edge 
 *        is the distance of reflection
 *        - we need reflect two times the horizontal and 
 *        vertical edges 
 *        - two horizontal reflection generate -2b or +2b,
 *        same to vertical.
 */
#include <bits/stdc++.h>
using namespace std;
 
class Polyline { public:
	int d[2] = {-2, 2};
	double length(int a, int b, int x0, int y0, int x1, int y1)	{
		double minLength = DBL_MAX;
		for (int i = 0; i < 2; ++i) {
			for(int j = 0; j < 2; ++j) {
				minLength = min(minLength, hypot(x0 - x1 - d[i] * a, y0 - y1 - d[j] * b));
			}
		}
		return minLength;
	}
};
 
int main() {
	Polyline task;
	cout << task.length(4, 3, 1, 1, 3, 2) << endl;
	return 0;
}
