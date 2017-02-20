#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
pair<int, int> v[N];
int n;
int c[N];

int main(){

	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", &v[i].second, &v[i].first);

	sort(v, v+n);
	c[0] = 1;
	for(int i = 1; i < n; ++i)
		
	
	return 0;
}
