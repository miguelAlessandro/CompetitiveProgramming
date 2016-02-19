#include <cstdio>
#include <iostream>
#define N 105

using namespace::std;

bool a[N], b[N];
int n, x, y, ca, cb;

int main( void ){   

    scanf("%d", &n);
    
    for(int i = 0; i < n; i++){
        scanf("%d %d", &x, &y);
    
        if(!a[x])   a[x] = true, ca++;   
        if(!b[y])   b[y] = true, cb++;
    
    }

    printf("%d\n", min(ca, cb));

    return 0;
}
