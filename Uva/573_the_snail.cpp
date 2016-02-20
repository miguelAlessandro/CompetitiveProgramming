#include <bits/stdc++.h>
#define eps 1e-9

using namespace::std;

int h, u, d, f;

int main(){

    while(scanf("%d", &h), h){
        scanf("%d %d %d", &u, &d, &f);

        double dist = double(u), dist_dia = u; int r = 1;
        while(dist > 0.0 && dist - h <= 0.0){
            if((dist -= d) < 0.0)
                break;
            dist_dia -= (double(u*f)/100.0);
            if(dist_dia < 0.0)
                dist_dia = 0.0;
            dist += dist_dia;
            ++r;
        }

        if(dist < eps)
            printf("failure on day %d\n", r);
        else
            printf("success on day %d\n", r);
    }

    return 0;
}
