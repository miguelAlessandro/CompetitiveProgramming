#include <cstdio>
#include <iostream>
using namespace::std;

int n1, m1;

int main(){

    while(scanf("%d %d", &n1, &m1), n1 + m1){
	int n = max(n1, m1); m = min(n1, m1);
        if(n <= 2 && m <= 2)
            printf("%d knights may be placed on a %d row %d column board.\n", n*m, n, m);
        else if(m == 2 && n%4 >= 2)
            printf("%d knights may be placed on a %d row %d column board.\n", n/4*4 + 4, n, m);
        else if(m == 2)
            printf("%d knights may be placed on a %d row %d column board.\n", n/4*4 + n%4*2, n, m);
        else
            printf("%d knights may be placed on a %d row %d column board.\n", ((n+1)/2)*((m+1)/2) + (n/2)*(m/2), n, m);
    }

	return 0;
}


