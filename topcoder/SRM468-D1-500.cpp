/**
 *	@name RoadOrFlightHard srm 468 div1 500
 *	@author Miguel Mini
 *	@tag dp
 *	@idea
 *		- simple dp using memory compression.		
 *		dp(pos, k, isFlight). 
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long llong;

llong memo[2][41][2];

class RoadOrFlightHard {
	public:
	llong minTime(int N, int rFirst, int rProd, int rAdd, int rMod, int fFirst, int fProd, int fAdd, int fMod, int K) {
		int rTime[N];
		int fTime[N];		
		rTime[0] = rFirst % rMod; fTime[0] = fFirst % fMod;
		for (int i = 1; i < N; ++i) {
			rTime[i] = (rTime[i-1]*1ll*rProd + rAdd) % rMod;
			fTime[i] = (fTime[i-1]*1ll*fProd + fAdd) % fMod;
		}
       	for (int i = 0; i <= K; ++i) {
            for (int j = 0; j < 2; ++j) {
        		memo[N&1][i][j] = 0;
            }
        }
        for (int pos = N-1; pos >= 0; --pos) {
        	for (int k = 0; k <= K; ++k) {
            	for (int state = 0; state < 2; ++state) {
                	llong &ans = memo[pos&1][k][state] = 
                        memo[(pos&1)^1][k][state] + (state ? fTime[pos] : rTime[pos]);; 	   
                	if (state) ans = min(ans, memo[(pos&1)^1][k][0] + rTime[pos]);
			else if (k > 0) ans = min(ans, memo[(pos&1)^1][k-1][1] + fTime[pos]);
               	}
            }
        }
		return memo[0][K][0]; 
	}
} TEST;

#ifdef DEBUG
int main() {
 	cout << TEST.minTime(
		5,
85739,
94847,
93893,
98392,
92840,
93802,
93830,
92790,
3
	) << endl;
	return 0;
}
#endif
