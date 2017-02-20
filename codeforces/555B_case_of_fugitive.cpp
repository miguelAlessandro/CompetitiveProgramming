#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int n, m;
int b[N];
long long X[N], Y[N]; 
pair<long long, int> a[N];
pair<pair<int, int>, int> Intv[N];


int main(){

	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i)
		scanf("%lld %lld", X+i, Y+i);

	for(int i = 0; i < m; ++i){
		scanf("%lld", &a[i].first);
		a[i].second = i;
	}

	if(m < n-1){
		puts("No");
		return 0;
	}	

	sort(a, a+m);


	bool ok = true;
	int lo, hi;
	for(int i = 0; i < n-1 and ok; ++i){
	
		Intv[i].second = i;

		lo = 0; hi = m-1;
		while(lo < hi){
			int mid = lo + (hi-lo)/2;
			if(a[mid].first < X[i+1]-Y[i]) lo = mid+1;
			else hi = mid;
		}
		//if(a[lo].first < X[i+1]-Y[i]) ok = false;
		Intv[i].first.second = lo;

		
		lo = 0; hi = m-1;
		while(lo < hi){
			int mid = lo + (hi-lo+1)/2;
			if(a[mid].first <= Y[i+1]-X[i]) lo = mid;
			else hi = mid-1;
		}
		//if(a[lo].first > Y[i+1]-X[i]) ok = false;
		Intv[i].first.first = lo;
	}


	/*if(not ok){
		puts("No");	
		return 0;
	}*/


	sort(Intv, Intv + n-1);
	int x = -1;
	for(int i = 0; i < n-1 and ok; ++i){
		x = max(x+1, Intv[i].first.second);
		if(x > Intv[i].first.first or x >= m){
			ok = false;
			break;
		}
		b[Intv[i].second] = a[x].second;
	}	

	if(not ok){
		puts("No");
		return 0;
	}

	puts("Yes");
	for(int i = 0; i < n-1; ++i)
		printf("%d ", b[i]+1);
	puts("");

	return 0;
}





