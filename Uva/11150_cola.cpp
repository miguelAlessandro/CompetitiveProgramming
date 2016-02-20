#include <iostream>
#include <cstdio>

using namespace::std;
int n, m = 1, s;

int main( void )
{
	while(scanf("%d", &n) != EOF)
		printf("%d\n",  n + n/2);
	return 0;
}
