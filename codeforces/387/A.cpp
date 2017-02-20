#include <iostream>
#include <cstdio>
#include <climits>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <queue>
#include <set>
using namespace std;

int n;
int a, b;
int diff;

int main(){

	cin >> n;

	diff = n;
	for(int i = 1; i <= n; ++i)
		if(n%i == 0 and abs(n/i - i) <= diff){
			diff = abs(n/i - i);
			a = min(i, n/i);
			b = max(i, n/i);
		}

	printf("%d %d\n", a, b);

	return 0;
}
