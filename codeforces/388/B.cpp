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

int X[4], Y[4];

int main(){

	for(int i = 0; i < 3; ++i)
		scanf("%d %d", X+i, Y+i);

	puts("3");
	printf("%d %d\n", X[0] + X[1] - X[2], Y[0] + Y[1] - Y[2]);
	printf("%d %d\n", X[0] + X[2] - X[1], Y[0] + Y[2] - Y[1]);
	printf("%d %d\n", X[2] + X[1] - X[0], Y[2] + Y[1] - Y[0]);


	return 0;
}
