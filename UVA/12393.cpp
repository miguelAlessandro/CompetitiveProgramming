#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1000010;
int n;
int a[N];
int hi[N], lo[N], me[N];


int main(){

    while(scanf("%d", &n), n){
        for(int i = 0; i < n; ++i)
            scanf("%d", a+i);
    
        me[0] = a[0];
        for(int i = 1; i < n; ++i)
            me[i] = me[i-1] + a[i];

        lo[0] = a[0];
        for(int i = 1; i < n; ++i)
            lo[i] = min(me[i], lo[i-1]);
        
        hi[n-1] = a[n-1];
        for(int i = n-2; i > 0; --i)
            hi[i] = min(a[i], hi[i+1] + a[i]);

        int r = (lo[n-1] >= 0);
        for(int i = 1; i < n; ++i)
            r += (hi[i] >= 0 and lo[i] + me[n-1] >= me[i-1]);
        printf("%d\n", r);
    }

    return 0;
}
