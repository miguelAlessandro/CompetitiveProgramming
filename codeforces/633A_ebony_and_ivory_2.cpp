#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace::std;

int gcd(int a, int b, int& x, int& y){
    if(b == 0){
        x = 1; y = 0;
        return a;
    }
    int x1, y1, g;
    g =  gcd(b, a%b, x1, y1);
    x = y1;
    y = x1 - (a/b)*y1;
    return g;
}

int a, b, c;

int main(){

    scanf("%d %d %d", &a, &b, &c);
    int x, y;
    int g = gcd(a, b, x, y);

    if(c%g == 0 && abs(y*c/a + x*c/b) > 0 || c%a == 0 || c%b == 0) puts("Yes");
    else puts("No");

    return 0;
}
