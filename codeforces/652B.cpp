#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n;
int a[N];

int main(){

	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", a+i);

	sort(a, a+n);
	deque<int> b;

	for(int i = 0; i < n; ++i)
		b.push_back(a[i]);

	int i = 1, q;
	while(not b.empty()){
		if(i%2 == 0)
			q = b.back(), b.pop_back();
		else
			q = b.front(), b.pop_front();
	
		printf("%d ", q);
		i++; 
	}
	puts("");

	return 0;
}
