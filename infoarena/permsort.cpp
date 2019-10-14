/*
 * @name infoarena permsort
 * @author Miguel Mini
 * @tag math
 * @idea:
 *	- if we think the array as a circular 
 *	array, centered on element 1, each time
 *	that the element i is removed, the center 
 *	becomes the element i.
 *
 *	- The current position is the amount of 
 *	active elements to the right of the center.
 *
 *	- the position in step i (i > 1), is  
 * 	number of elements actives in cyclic range 
 *	[position of i-1, position of i] equal to 
 *	if [position of i-1] < [position of i]:
 *		[active from 1 to i] -		
 *		[active from 1 to i-1] 
 *	else:
 *		[active from 1 to i] + 
 *		(n - i + 1 - [active from 1 to i-1])
 *
 *	same than:
 *		[active from 1 to i] - [active from 1 to i-1]
 *				+ 
 *		if [position of i-1] > [position of i]:
 *			n - i + 1
 *		else: 
 *			0
 *	the difficult part is:
 *		[active from 1 to i] - [active from 1 to i-1]
 *
 *	supposse that: 
 *		in step i, q = [active from 1 to i].
 *		obviusly in step i+1 element i is inactive
 *		then in step i+1 [active from 1 to i] == q - 1.
 *
 *	above sum [active from 1 to i] - [active from 1 to i-1]		
 *	for every step is (telescoping sum) n-1 + [active from 1 to n] 
 *	-(0 = [active from 1 to 0]). As in step n [active from 1 to n] is
 *	1. our sum is n + [pos i-1 > pos i] * (n - i + 1). 
 *
 */

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
bool vis[maxn];
int n;

int main() {
	freopen("permsort.in", "r", stdin);	
	freopen("permsort.out", "w", stdout);
	scanf("%d", &n);
	long long ans = n;
	vis[0] = 1;
	for (int i = 1; i <= n; ++i) {
		int cur;
		scanf("%d", &cur);
		vis[cur] = 1;
		if (not vis[cur-1]) ans += n - cur + 1;
	}
	printf("%lld\n", ans);
	return 0;
}
