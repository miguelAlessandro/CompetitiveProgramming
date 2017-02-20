#include <bits/stdc++.h>
using namespace std;

int n, c;
int A, D;

int main(){

	scanf("%d%*c", &n);
	for(int i = 0; i < n; ++i)
		if(getchar() == 'A') A++;
		else D++;

	if(A > D)
		puts("Anton");
	else if(D > A)
		puts("Danik");
	else
		puts("Friendship");
 

	return 0;
}
