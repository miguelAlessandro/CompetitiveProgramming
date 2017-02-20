#include <bits/stdc++.h>
using namespace std;

int n, q, x, y, pos;
bool e = true;

int add(int a, int b){
	return (n + (a+b)%n)%n;
}


int main(){

	scanf("%d %d", &n, &q);
	
	while(q--){
		scanf("%d %d", &x, &y);
		if(x == 1)
			pos = add(pos, y);	
		else
			pos = add(y, -pos), e ^= true;
	}
	
	if(e) printf("1 %d\n", (n-pos)%n);
	else  printf("2 %d\n", pos);

	return 0;
}
