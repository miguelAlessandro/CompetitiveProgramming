/**
 *	@name POI 2008 BBB
 *	@author Miguel Mini
 *	@tag greedy, min_queue
 *	@idea
 *			- we can reduce the problem
 *			to solve separately every 
 *			traslation (second action).
 *
 *			- greedy observation: we just
 *			need ceil(minimum / 2) for i-th
 *			traslation to avoid negative balance.
 *
 *			then, if p + sum_total < q 
 *			(diff = q - p - sum_total is even), we
 *			can achieve balance adding (change "-" to "+") 
 *			digg / 2, change first negative transactions.
 *
 *			on the other hand we can achieve balance
 *			changing the last positives diff / 2 transactions.
 *
 *			- to greedy observation is enough to
 *			changing first ceil(minimum / 2) negative
 *			to positive, it is easy to calculate
 *			that all sums are now non-negative.
 *
 *			- to calculate minimum to every range, we can use 
 *			min-queue or min-stack with sweep windows.
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int s[maxn][2];
int sum[maxn*2];
int t[2];
int n, p, q, x, y;
char text[maxn];
int min0 = 1e9;

/**
 *	START MIN-QUEUE WITH TWO STACKS
**/
void mq_add(int p) {
	min0 = min(min0, p);
	s[t[0]++][0] = p;
}

int mq_rem() {
	if (t[1] > 0) t[1] -= 1;
	else {
		for (int i = t[0]-1; i > 0; --i) {
			if (t[1] == 0) {
				s[t[1]++][1] = s[i][0];
			} else {
				s[t[1]++][1] = min(s[t[1]-1][1], s[i][0]);
			}
		}
		t[0] = 0;
		min0 = 1e9;
	}
}

int mq_min() {
	if (t[1] > 0) return min(s[t[1]-1][1], min0);
	return min0;
}
/**
 *	END
**/

int main() {
	scanf("%d %d %d %d %d\n", &n, &p, &q, &x, &y);
	scanf("%s", text);
	for (int i = 0; i < n + n; ++i) {
		int r = i < n ? i : i - n;
		sum[i] = (i == 0 ? 0 : sum[i-1]) + (text[r] == '+' ? 1 : -1);
	}
	for (int i = 0; i < n; ++i) mq_add(sum[i]);
	int pref = 0;
	int total = sum[n-1];
	int ans = INT_MAX;
	for (int i = 0; i < n; ++i) {
		int t = mq_min() - pref; 	
		int d = (-min(p + t, 0) + 1)/2;
		int temp = y * (i==0?0:n-i) + (d + abs(q - (total+2*d) - p) / 2) * x;
		ans = min(ans, temp);
		mq_add(sum[n+i]);
		mq_rem();
		pref = sum[i];
	}
	printf("%d\n", ans);
	return 0;
}	
