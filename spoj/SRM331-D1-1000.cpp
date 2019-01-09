/**
 * SRM331 - Div 1 - 1000 HiddenSquares
 * 
 * @author Miguel Mini
 * -------------------------------------------
 * @tags geometry, coordinate-compression, dsu
 * @idea
 *		- it's necessary than the vertex of squares are vertex of input too.
 *		- I use coordinate compression to make easy union - find use.
 *		- note than is necessary know if two points are horizontal or vertical connected.
 *		- finally check all possible square and verify edge existence.
 * 
 */
#include <bits/stdc++.h>
using namespace std;

class HiddenSquares {
	public:
		const static int maxN = 102;
		
		//{{
		//UNION - FIND
		int id[2][maxN * maxN];
		int rnk[2][maxN * maxN];
		int value(int x, int y) {
			return x * maxN + y;
		}
		int get(int who, int x) {
			return x == id[who][x] ? x : id[who][x] = get(who, id[who][x]);
		}
		void Union(int who, int x, int y) {
			x = get(who, x);
			y = get(who, y);
			if (x == y) {
				return;
			}
			if (rnk[who][x] < rnk[who][y]) swap(x, y);
			id[who][y] = x;
			rnk[who][x] += rnk[who][x] == rnk[who][y];
		}
		//}}
		int count(vector<int> x1, vector<int> y1, vector<int> x2, vector<int> y2) {
			//{{ coordinate - compression
			map<int, int> X, Y;
			int n = x1.size();
			for (int i = 0; i < n; ++i) {
				X[x1[i]]; X[x2[i]];
				Y[y1[i]]; Y[y2[i]];
			}
			int nx = 0;
			for (auto& element : X) {
				element.second = nx++;
			}
			int ny = 0;
			for (auto& element : Y) {
				element.second = ny++;
			}
			for (int k = 0; k < 2; ++k) {
				for (int i = 0; i < ny; ++i) {
					for (int j = 0; j < nx; ++j) {
						id[k][value(i, j)] = value(i, j);
						rnk[k][value(i, j)] = 0;
					}
				}	
			}
			//}}
			//{{ build connectivity knowledge
			for (int i = 0; i < n; ++i) {
				int iy1 = Y[y1[i]], iy2 = Y[y2[i]];
				int ix1 = X[x1[i]], ix2 = X[x2[i]];
				for (int j = ix1+1; j <= ix2; ++j) {
					Union(0, value(iy1, j-1), value(iy1, j));
					Union(0, value(iy2, j-1), value(iy2, j));
				}
				for (int j = iy1+1; j <= iy2; ++j) {
					Union(1, value(j-1, ix1), value(j, ix1));
					Union(1, value(j-1, ix2), value(j, ix2));
				}
			}
			//}}
			//{{ inverse of coordinate-compression to calculate distance
			vector<int> invX(nx), invY(ny);
			for (auto element : X) {
				invX[element.second] = element.first;
			}
			for (auto element : Y) {
				invY[element.second] = element.first;
			}
			//}}
			//{{ check all possible square
			int cnt = 0;
			for (int i = 0; i < ny; ++i) {
				for (int j = i+1; j < ny; ++j) {
					for (int k = 0; k < nx; ++k) {
						for (int l = k+1; l < nx; ++l) {
							if (invX[l] - invX[k] == invY[j] - invY[i] and 
								get(0, value(i, k)) == get(0, value(i, l)) and
								get(0, value(j, k)) == get(0, value(j, l)) and
								get(1, value(i, k)) == get(1, value(j, k)) and
								get(1, value(i, l)) == get(1, value(j, l))
							) {
								cnt += 1;	
							}
						}
					}
				}
			}
			//}}
			return cnt;
		}
} task;

int main() {

	cout << task.count(
{453453463,453453500,453453495,453453512,453453478,453453489,
 453453466,453453500,453453498,453453510,453453472,453453512,
 453453519,453453514,453453521,453453518,453453523,453453517,
 453453466,453453525,453453496,453453495,453453463,453453461,
 453453460,453453522,453453471,453453468,453453479,453453517,
 453453485,453453518,453453499,453453464,453453494},
{364646438,364646402,364646449,364646438,364646415,364646401,
 364646446,364646416,364646456,364646414,364646463,364646407,
 364646436,364646450,364646421,364646411,364646414,364646419,
 364646445,364646427,364646405,364646442,364646418,364646464,
 364646457,364646463,364646432,364646426,364646444,364646431,
 364646450,364646418,364646434,364646458,364646402},
{453453488,453453510,453453525,453453523,453453493,453453500,
 453453470,453453511,453453499,453453521,453453518,453453524,
 453453523,453453523,453453524,453453523,453453525,453453519,
 453453473,453453526,453453511,453453517,453453470,453453464,
 453453511,453453524,453453516,453453516,453453492,453453524,
453453513,453453522,453453520,453453505,453453512},
{364646460,364646454,364646462,364646466,364646464,364646455,
 364646457,364646461,364646457,364646450,364646466,364646453,
 364646441,364646451,364646460,364646461,364646446,364646464,
 364646447,364646460,364646454,364646450,364646444,364646466,
 364646458,364646466,364646455,364646442,364646462,364646435,
 364646464,364646444,364646455,364646459,364646430}
	) << endl;
	
	return 0;
}
