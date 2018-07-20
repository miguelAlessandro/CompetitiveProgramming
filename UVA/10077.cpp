#include <iostream>
#include <cstdio>
using namespace std;

typedef pair<int, int> ii;
int a, b;

int main(){

    while(scanf("%d %d", &a, &b), a+b != 2){
        ii lo(0, 1), hi(1, 0);
        while(lo.first*hi.second < lo.second*hi.first){
            ii me = ii(lo.first + hi.first, lo.second + hi.second);
            if(me.first*b > me.second*a){
                putchar('L');
                hi = me;
            }
            else if(me.first*b < me.second*a){
                putchar('R');
                lo = me;
            }
            else
                break;
        }
        putchar('\n');
    }

    return 0;
}
