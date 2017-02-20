#include <bits/stdc++.h>
using namespace std;

int h, m, a;

int main(){

	scanf("%d%*c%d%*c%d", &h, &m, &a);	
	a %= 1440;
	h += a/60;
	m += a%60;
	
	h += m/60;
	m %= 60;

	printf("%02d:%02d\n", h%24, m);

	return 0;
}
