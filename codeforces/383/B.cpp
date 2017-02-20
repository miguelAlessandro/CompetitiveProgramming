#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

const int N = 100005;
int a[N];
map<int, int> s;
int n, x;

int main(){

	scanf("%d %d", &n, &x);
	for(int i = 0; i < n; ++i){
		scanf("%d", a+i);	
		s[a[i]]++;
	}

	long long ans = 0;
	for(int i = 0; i < n; ++i){
		long long p = a[i]^x;
		s[a[i]]--;
		ans += s[p];
	}

	cout << ans << endl;

	return 0;
}
