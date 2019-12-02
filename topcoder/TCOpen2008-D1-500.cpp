/**
 *	@name topcoder open 2008 online round 2 div 1 level two
 *	@author Miguel Mini
 *	@tag dp
 *	@idea
 *			- we can reduce the problem to dp(position, D, taked):
 *			throught elements from 0 to n-1, with D days and taked
 *			elements to cur position what is the maximum score. 
 *
 *			- in cur position my items are count[pos] + taked and
 *			repeat process.
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long llong;

bool vis[50][101][101];
llong memo[50][101][101];

class CreatureTraining {
	public:
	llong maximumPower(vector<int> count, vector<int> power, int D) {
		int n = count.size();
		function<llong(int, int, int)> dp = [&](int pos, int d, int taked)->llong {
			if (pos == n) return 0;
			if (vis[pos][d][taked]) return memo[pos][d][taked];
			llong &ans = memo[pos][d][taked] = 0;
			for (int i = 0; i <= min(count[pos] + taked, d); ++i) {		
				ans = max(ans, (count[pos] + taked - i) *1ll* power[pos] + dp(pos+1, d-i, i));
			}
			vis[pos][d][taked] = 1;
			return ans;
		};
		return dp(0, D, 0);
	}
} TEST;

#ifdef DEBUG
int main() {
	cout << TEST.maximumPower(
		{0, 2, 1, 0, 0, 1, 2},
		{25, 292, 328, 391, 618, 771, 952},
		11
	) << endl;
	return 0;
}	
#endif
