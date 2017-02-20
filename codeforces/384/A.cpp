#include <iostream>
#include <cstdio>
using namespace std;

int n, a, b;
char s[100005];

int main(){

	scanf("%d %d %d%*c%s", &n, &a, &b, s);
	printf("%d\n", s[a-1] != s[b-1]);

	return 0;
}
