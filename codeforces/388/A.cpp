#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <climits>
using namespace std;



int main(){

	int n;
	cin >> n;

	printf("%d\n", n/2);	
	for(int i = 0; i+1 < n/2; ++i)
		printf("2 ");
	printf("%d", (n&1) + 2);

	puts("");


	return 0;
}
