#include <iostream>
#include <cstdio>
#define N 400

using namespace::std;

int n;
int F[N], M[N];

int main(){

    scanf("%d%*c", &n);
    while(n--){
        int a, b; char c;
        scanf("%c%*c%d%*c%d%*c", &c, &a, &b);
        if(c == 'M')
            for(int i = a; i <= b; ++i)
                ++M[i];
        else
            for(int i = a; i <= b; ++i)
                ++F[i];
    }
    int r = 0;
    for(int i = 1; i <= 366; ++i)
        r = max(r, min(M[i], F[i]));
    printf("%d\n", r<<1);

    return 0;
}
