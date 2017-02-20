#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int n, t;
vector<int> v;

int main(){

	scanf("%d%*c", &n);
	for(int c, r = 0, i = 0; i < n; ++i){
		c = getchar();
		if(c == 'B') r++;
		if(c == 'W' and r != 0){
			v.push_back(r);
			r = 0;
		}
		if(i == n-1 and r != 0)
			v.push_back(r);
	}	

	printf("%d\n", (int)v.size());
	for(auto it : v)
		printf("%d ", it);
	puts("");

	return 0;
}
