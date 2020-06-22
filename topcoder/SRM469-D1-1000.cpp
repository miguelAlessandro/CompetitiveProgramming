/**
 * @name TheMoviesLevelThreeDivOne SRM 469 div1 1000pts
 * @author Miguel Mini
 * @tag dp, memory_compression, math
 * @idea
 *	- We can prove that if A can't
 *	see every movie, then B can do. 
 *		
 *	- then, we need to check sum{not taked}(A) + sum{taked from 0 to i-1}(A_i) - sum{taked from 0 to i}(B_i) < 0 
 *	to both (A, B) and (B, A).	
 *
 * 	- dp take the form:
 *		dp(pos, sum, minimum) : sum( 
 *			to->A : dp(pos+1, sum + A[pos], minimum + A[pos])
 *			to->B : dp(pos+1, sum + A[pos] - B[pos], min(minimum, sum - B[pos]))	
 *		)
 *	- this dp is O(nx(20*n)^2) = O(400*n^3).
 *	and memory O(400*n^2) with memory compression.
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long llong;
const int maxn = 2*900;
const int o = 900;
//bool vis[2][maxn][maxn];
llong memo[2][maxn][maxn];

class TheMoviesLevelThreeDivOne {
	public:
	long long solve(vector<int>& J, vector<int>& B) {
		int n = J.size();
		for (int i = 0; i < maxn; ++i) {
			for (int j = 0; j < maxn; ++j) {
				memo[n&1][i][j] = j < o;
			}
		}
		for (int pos = n-1; pos >= 0; --pos) {
			for (int i = 0; i < maxn; ++i) {
				for (int j = 0; j < maxn; ++j) {
					llong &ans = memo[pos&1][i][j] = 0;
					if (i + J[pos] < maxn and j + J[pos] < maxn) {
						ans += memo[(pos&1)^1][i+J[pos]][j+J[pos]];
					}
					if (i + J[pos] - B[pos] >= 0 and i + J[pos] - B[pos] < maxn and min(j, i - B[pos]) >= 0) {
						ans += memo[(pos&1)^1][i+J[pos]-B[pos]][min(j, i-B[pos])];
					}
				}
			}
		}
		return memo[0][o][o];
	}
	llong find(vector<int> timeJ, vector<int> timeB) {
		int n = timeJ.size();
		//min(At + Ai-1 - Bi) < 0
		/**function<llong(int, int, int)> dp = [&](int pos, int ta, int tb)->llong {
			if (pos == n) return tb < 0;			
			if (vis[pos][o+ta][o+tb]) return memo[pos][o+ta][o+tb];			
			llong ans = memo[pos][o+ta][o+tb] = 0;
			ans += dp(pos+1, ta + timeJ[pos], tb + timeJ[pos]);
			ans += dp(pos+1, ta + timeJ[pos] - timeB[pos], min(tb, ta - timeB[pos]));
			vis[pos][o+ta][o+tb] = 1;
			return ans;
		};**/
		//memset(vis, 0, sizeof vis);
		//llong ans = dp(0, 0, 0);
		llong ans = solve(timeB, timeJ) + solve(timeJ, timeB);
		//memset(vis, 0, sizeof vis);
		//ans += dp(0, 0, 0);
		return (1ll<<n) - ans;
	}
} TEST;

#ifdef DEBUG
int main() {
	cout << TEST.find({4, 4},{4, 4}) << endl;
	cout << TEST.find({1, 2, 3, 4, 5, 6, 7},{7, 6, 5, 4, 3, 2, 1}
) << endl;
	return 0;
}
#endif
