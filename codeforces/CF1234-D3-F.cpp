/**
 *	@name F yet another substring reverse
 *	@author Miguel Mini	
 *	@tag dp_sum_over_subset
 *	@idea
 *			- every range of distinct
 *			element can merge.
 *	
 *			[--range1--]{--extra--[--range2--]}			
 *			=>
 *			[--range1--]{[--range2--]--extra--}
 *
 *			- then, we only need to analyze 
 *			sub arrays of length at most 20
 *			
 *			- let S1 the set of elements in
 *			range1, and S2 the set of elements
 *			in range2, then S2 \in \complement{S1}
 *  
 *			- use dp sum over subset to propagate
 *			len(S1) to all super set. the answer
 *		 	is:
 *				max(ans[S] + ans[\complement{S}]).
 */

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
const int S = 20;
char s[maxn];
int F[1<<S];
 
int main() {
	scanf("%s", s);
	for (int i = 0; s[i]; ++i) { 	
		int mask = 0;
		for (int j = i; s[j]; ++j) {
			if (mask & (1<<s[j]-'a')) {
				break;
			} else {
				mask |= (1<<s[j]-'a');
				F[mask] = __builtin_popcount(mask); 
			}
		}
	}
	for (int i = 0; i < S; ++i) {
		for (int mask = 0; mask < 1<<S; ++mask) if (mask & (1<<i)) {
				F[mask] = max(F[mask], F[mask^(1<<i)]);
		}
	}
	int ans = 0;
	for (int i = 0; i < 1<<S; ++i) {
		ans = max(ans, F[i] + F[((1<<S)-1)&~i]);
	}
	printf("%d\n", ans);
	return 0;
}

