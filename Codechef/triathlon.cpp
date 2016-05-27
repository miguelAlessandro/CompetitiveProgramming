#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;

const int N = 200005;
int n;
pair<int, int> a[N];
bool comp(const pair<int, int>& p, const pair<int, int>& q){
	return p.second < q.second;
}

int main(){

	scanf("%d", &n);
	long long sum = 0;
	for(int x, y, i = 0; i < n; ++i){
		scanf("%d %d %d", &a[i].first, &x, &y);
		sum += a[i].first;
		a[i].second = x+y;
	}	

	sort(a, a+n, comp);

	long long maxi = 0; 
	for(int i = 0; i < n; ++i){
		maxi = max(maxi, sum + a[i].second);
		sum -= a[i].first;
	}
	
	printf("%lld\n", maxi);

	return 0;	
}
