#include <iostream>
#include <cstdio>
using namespace std;

int n;
int a, b, c;

int main(){
	scanf("%d", &n);
	b = 1; 
	c = 1;
	for(int i = 2; i <= n; ++i){ 
		c = a + b;
		a = b;
		b = c;
	}

	printf("%lld\n", 2ll*c);
	
	return 0;
}
