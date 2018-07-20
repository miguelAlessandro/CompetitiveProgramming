#include <iostream>
#include <stdio.h>

using namespace std;

long long f[95] = {0, 1, 2}, n;

int main() {
    
    for(int i = 3; i <= 90; i++)
        f[i] = f[i-1]+f[i-2];
 
    while(scanf("%lld", &n) != EOF) {
        long long a[100], b[100], c = 0;
        printf("%lld\n", n);
        for(int i = 90; i >= 1; i--)
            if(f[i] <=  n) {
                n -= f[i];
                a[c] = f[i];
                b[c] = i;
            	c = c + 1;
            }
        for(int i = 0; i < c; i++)
            printf("%lld ", b[i]);
        puts("");
        for(int i = 0; i < c; i++)
            printf("%lld ", a[i]);
        puts("\n");
    }
    return 0;
}
