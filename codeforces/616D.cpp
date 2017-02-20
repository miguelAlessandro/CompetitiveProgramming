#include <cstdio>
using namespace std;

const int N = 500005;
int a[N], sz = 0, fr[N<<1];
int n, k, p = 0, q = 1;

void predicate(){

	int r = 0, l = 0;
	int len = 0;
	for(r = 0; r < n; ++r){
		scanf("%d", a+r);
		if(++fr[a[r]] == 1) sz++;

		while(sz > k){
			if(fr[a[l]]-- == 1) sz--;
			l++;
		}

		if(len < r-l+1){
			p = l;
			q = r;
			len = r-l+1;
		}
	}
}

int main(){

	scanf("%d %d", &n, &k);
	//for(int i = 0; i < n; ++i) scanf("%d", a+i);

	/*int lo = 1, hi = n; 
	while(lo < hi){
		int mid = lo + (hi-lo+1)/2;
		if(predicate(mid)) lo = mid;
		else hi = mid-1;
	}*/

	predicate();
	printf("%d %d\n", p+1, q+1);


	return 0;
}
