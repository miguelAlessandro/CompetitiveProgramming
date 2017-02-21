#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n;
vector<int> v;

int main(){

	scanf("%d", &n); v.resize(n);
	for(int i = 0; i < n; ++i)
		scanf("%d", &v[i]);

	

	sort(v.begin(), v.end());
	int mini = v.front();
	int maxi = v.back();
	int r = 0;
	for(int i = 0; i < n; ++i)
		if(v[i] != mini and v[i] != maxi)
			r++;			

	printf("%d\n", r);

	return 0;
}
