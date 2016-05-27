#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1005;
int a[N];
int n, m;
int MIN[N];

int min_coin(int s){
	for(int i = 0; i < n; ++i) MIN[i] = 1<<27;
    MIN[0] = 0;
   	for(int i = 1; i <= s; ++i)
   		for(int j = 0; j < n; ++j)
        	if(a[j] <= i)
            	MIN[i] = min(MIN[i], MIN[i-a[j]]+1);
	return MIN[s];
}


int min_coin2(int x){
	if(x == 0) return 0;
	if(memo[x] != -1) return memo[x];
	
	memo[x] = INT_MAX;	
	for(int i = 0; i < n; ++i)
		if(x >= a[i] and memo[x] > 1 + s(x-a[i])){
			p[x] = i;
			memo[x] = 1 + s(x-a[i]);
		}

	return memo[x];
}

int main(){

    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i)
        scanf("%d", a+i);

	printf("%d\n", min(n, m));


    return 0;
}
