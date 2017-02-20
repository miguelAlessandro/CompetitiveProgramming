/**********************
round: 397
handle: _threat_
theme: ad-hoc, greedy
complexity: O(1)
**********************/

#include <bits/stdc++.h>
using namespace std;
int a, b, k;

int main(){
	scanf("%d %d %d", &k, &a, &b);
	
	if(a > b) swap(a, b);
	if(b < k or b%k and a<k) puts("-1");
	else printf("%d\n", a/k+b/k);

	return 0;
}
